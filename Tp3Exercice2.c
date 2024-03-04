/*Travail fait par :
Wassila 20183065*/ 

#include <stdio.h>  
#include <string.h> 
#include <stdbool.h>
#include <math.h> 
#define MAX_ELEVES 200
#define LONGUEUR_MAX_NOM 21

//Implementation d'une fonction permettant d'echanger les valeurs des variables pointees par les pointeurs a et b
void echanger(float *a, float *b) {
    float temp = *a; //Stockage de la valeur pointee par le pointeur a dans une variable temporaire nommee temp
    *a = *b; //Copie de la valeur pointee par le pointeur b dans la position memoire pointee par a
	*b = temp; //Copie de la valeur temp (valeur initiale de a) dans la position memoire pointee par b
}


//Implementation d'une fonction permettant d'echanger les valeurs des entiers pointes par a et b + les chaines de caracteres nomA, nomB, prenomA, prenomB
void echangerEtudiants(int *a, int *b, char nomA[], char nomB[], char prenomA[], char prenomB[]) {
    int temp = *a; //Stockage de la valeur pointee par le pointeur a dans une variable temporaire nommee temp
    *a = *b; //Copie de la valeur pointee par le pointeur b dans la position memoire pointee par a
    *b = temp; //Copie de la valeur temp (valeur initiale de a) dans la position memoire pointee par b

    char tempNom[LONGUEUR_MAX_NOM]; //Declaration d'une variable temporaire nommee tempNom de type tableau de caracteres pour stocker temporairement une chaine de caracteres
    strcpy(tempNom, nomA); //Copie de la chaine de caracteres nomA dans la variable tempNom
    strcpy(nomA, nomB); //Copie de la chaine de caracteres nomB dans la variable nomA
    strcpy(nomB, tempNom); //Copie la chaine de caracteres tempNom (valeur initiale de nomA) dans la variable nomB

    char tempPrenom[LONGUEUR_MAX_NOM]; //Declaration d'une variable temporaire tempPre//nom de type tableau de caracteres pour stocker temporairement une chaine de caracteres
    strcpy(tempPrenom, prenomA); //Copie de la chaine de caracteres prenomA dans la variable tempPrenom
    strcpy(prenomA, prenomB); //Copie de la chaine de caracteres prenomB dans la variable prenomA
    strcpy(prenomB, tempPrenom); //Copie de la chaine de caracteres tempPrenom  dans la variable prenomB, échangeant ainsi les valeurs de prenomA et prenomB
}

//Implementation D'une fonction creer pour creer un tableau avec les parametres numero_etudiants, nom, prenom, et note
void creer(int numero_etudiants[MAX_ELEVES], char nom[MAX_ELEVES][LONGUEUR_MAX_NOM], char prenom[MAX_ELEVES][LONGUEUR_MAX_NOM], float notes[MAX_ELEVES], int *p) {
    FILE *aLire = fopen("note1.txt", "r"); // // Ouverture et lecture du fichier
	
	//test de l'ouverture du fichier
    if (aLire == NULL) { 
        fprintf(stderr, "Impossible d'ouvrir le fichier notes.txt\n\n");//Si l'ouverture du fichier échoue un message d'erreur est affiché
        return;
    } else {
    	printf("Fichier ouvert avec succes.\n\n");
    }

    int n = 0;
    while (fscanf(aLire, "%d %s %s %f\n\n", &numero_etudiants[n], nom[n], prenom[n], &notes[n]) == 4) //lecture des donnees du fichier ligne par ligne
	{
        n++;
        if (n >= MAX_ELEVES) //Lecture du fichier jusqu'au nombre maximum d'étudiants
            break;
    }
	
	if (ferror(aLire)) {
		fprintf(stderr, "Erreur lors de la lecture du fichier.\n");
		fclose(aLire);
		return;
	}
		
    fclose(aLire); //Fermeture du fichier
    *p = n; // Pointeur p initialisé avec la valeur du nombre d'étudiants lus
}

//Implementation d'une fonction afficheant les informations d'un etudiant (numero, nom, prenom, note)
void afficherEtudiant(int numero, char nom[], char prenom[], float note) {
    printf("%d %s %s %.2f\n\n", numero, nom, prenom, note); //Affichage des informations (numero, nom, prenom, note)
}

//Implementation de la fonction partition pour l'utilisation de quickSort
void partitionner2(float notes[], int numero_etudiants[], char nom[MAX_ELEVES][LONGUEUR_MAX_NOM], char prenom[MAX_ELEVES][LONGUEUR_MAX_NOM], int debut, int fin, int *indPivot)
           {
             int   gauche = debut , droite = fin ;
             float   valPivot = notes[debut];

             do
              {while (gauche <= droite && notes[gauche] >= valPivot)
              	gauche++;
               while (notes[droite]< valPivot)
			   	droite-- ;

               if (gauche < droite) {
					echanger(&notes[gauche], &notes[droite]);
               		echangerEtudiants(&numero_etudiants[droite], &numero_etudiants[gauche], nom[droite], nom[gauche], prenom[droite], prenom[gauche]);
           		}
              } while (gauche <= droite );
             echanger(&notes[droite], &notes[debut]);
             echangerEtudiants(&numero_etudiants[droite], &numero_etudiants[debut], nom[droite], nom[debut], prenom[droite], prenom[debut]);

             *indPivot = droite;
           }


//Implementation de la  fonction quicksort
void quickSort(float notes[MAX_ELEVES], int numero_etudiants[MAX_ELEVES], char nom[MAX_ELEVES][LONGUEUR_MAX_NOM], char prenom[MAX_ELEVES][LONGUEUR_MAX_NOM], int debut, int fin) {
    int indPivot;
	if (debut < fin) {
		partitionner2(notes, numero_etudiants, nom, prenom, debut, fin, &indPivot);
        quickSort(notes, numero_etudiants, nom, prenom, debut, indPivot - 1);
        quickSort(notes, numero_etudiants, nom, prenom, indPivot + 1, fin);
    }
}


//Implementation d'une fonction effectue une recherche dichotomique uniquement dans le tableau de notes
int rechercheDichotomique(float notes[], int gauche, int droite, float noteCherchee) {
	const float epsilon = 0.001;
    while (gauche <= droite) { //Tant que des elements sont disponibles continuer defectuer les instructions dans la boucle
        int milieu = gauche + (droite - gauche) / 2;
        if (fabs(notes[milieu] - noteCherchee) < epsilon)
            return milieu;
        if (notes[milieu] > noteCherchee)
            gauche = milieu + 1;
        else
            droite = milieu - 1;
    }
    return -1; // Retourne -1 si la note n'est pas trouvee
}

int main() {
    // Declaration des tableaux pour stocker les donnees
    int numero_etudiants[MAX_ELEVES];
    char nom[MAX_ELEVES][LONGUEUR_MAX_NOM];
    char prenom[MAX_ELEVES][LONGUEUR_MAX_NOM];
    float notes[MAX_ELEVES];
    int nombre_etudiants;
	
	//Appel de la fonction creer pour lire les donnees du fichier et initialiser les 4 tableaux   
    creer(numero_etudiants, nom, prenom, notes, &nombre_etudiants);
	
	//Appel de la fonction quickSort pour effectuer le tri rapide
    quickSort(notes, numero_etudiants, nom, prenom, 0, nombre_etudiants - 1); //Appel de la fonction quickSort pour trier les donnees par ordre decroissant de la note
    
	int i=0;
	while(i<nombre_etudiants){
		printf("%d %s %s %.2f\n", numero_etudiants[i], nom[i], prenom[i], notes[i]);
		i++;
	}
	printf("\nNombre d'etudiants: %d\n\n",nombre_etudiants); //Affichage du nombre d'étudiants
	
	printf("Meilleur resultat :"); // Affichage de la meilleure note
    afficherEtudiant(numero_etudiants[0], nom[0], prenom[0], notes[0]); //Appel de la fonction afficherEtudiant pour afficher les informations du meilleur etudiant
	
	printf("\nPire resultat :");// Affichage de la pire note
    afficherEtudiant(numero_etudiants[nombre_etudiants - 1], nom[nombre_etudiants - 1], prenom[nombre_etudiants - 1], notes[nombre_etudiants - 1]); //Appel de la fonction afficherEtudiant pour afficher les informations du pire etudiant.
	
	// Recherche dichotomique pour une note spécifique
    bool continuerRecherche = true;
    while (continuerRecherche) {
    	float noteCherchee;
    	int validInput;
    	do {
    		printf("Entrez la note a chercher : ");
    		validInput = scanf("%f", &noteCherchee);
    		while(getchar() != '\n');
    	} while (validInput != 1);

        int resultatRecherche = rechercheDichotomique(notes, 0, nombre_etudiants - 1, noteCherchee);
        if (resultatRecherche != -1) {
            afficherEtudiant(numero_etudiants[resultatRecherche], nom[resultatRecherche], prenom[resultatRecherche], notes[resultatRecherche]);
        } else {
            printf("Note %.2f non trouvee.\n", noteCherchee);
        }

        printf("Voulez-vous chercher une autre note? (1 pour oui, 0 pour non) : ");
        int reponse;
        scanf("%d", &reponse);
        continuerRecherche = (reponse == 1);
    }
 
    return 0;
}


 
