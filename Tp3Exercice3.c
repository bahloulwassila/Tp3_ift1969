/*Travail fait par :
Wassila 20183065*/


#include <stdio.h>  
#include <string.h> 
#include <stdbool.h> 
#include <math.h>
#define MAX_ELEVES 200
#define LONGUEUR_MAX_NOM 21

typedef struct {
    int numero;
    char nom[LONGUEUR_MAX_NOM];
    char prenom[LONGUEUR_MAX_NOM];
    float note;
} Etudiant;

//Implementation d'une fonction permettant d'echanger les valeurs des variables pointees par les pointeurs a et b
void echanger(Etudiant *a, Etudiant *b) {
    Etudiant temp = *a;
    *a = *b;
    *b = temp;
}

//Implementation de la fonction creer pour creer le tableau composé du numero etudiant, nom, prenom et sa note
void creer(Etudiant etudiants[], int *nombre_etudiants) {
    FILE *aLire = fopen("note1.txt", "r"); // // Ouverture et lecture du fichier

    if (aLire == NULL) { //test de l'ouverture du fichier
        fprintf(stderr, "Impossible d'ouvrir le fichier notes.txt\n\n");//Si l'ouverture du fichier échoue un message d'erreur est affiché
        return;
    } else {
    	printf("Fichier ouvert avec succes.\n\n");
    }

    int n = 0;
    while (fscanf(aLire, "%d %s %s %f\n\n", &etudiants[n].numero, etudiants[n].nom, etudiants[n].prenom, &etudiants[n].note) == 4) //lecture des donnees du fichier ligne par ligne
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
    *nombre_etudiants = n; //Pointeur nombre_etudiants initialisé avec la valeur du nombre d'étudiants lus
}

//Implementation d'une fonction afficheant les informations d'un etudiant (numero, nom, prenom, note)
void afficherEtudiant(Etudiant etudiant) {
    printf("%d %s %s %.2f\n", etudiant.numero, etudiant.nom, etudiant.prenom, etudiant.note); //Affichage des informations (numero, nom, prenom, note)
}

//Implementation de la fonction partitionner utiliser dans le quicksort
void partitionner2(Etudiant etudiants[], int debut, int fin, int *indPivot){
    int gauche = debut , droite = fin ;
    Etudiant pivot = etudiants[debut];
             
	while (gauche <= droite){
		while (gauche <= fin && etudiants[gauche].note >= pivot.note) {
			gauche++;
		}
		
		while (droite >= debut && etudiants[droite].note < pivot.note) {
	        droite--;
	    }
	    
	    if (gauche < droite) {
	        echanger(&etudiants[gauche], &etudiants[droite]);
	    }
	}   
	echanger(&etudiants[debut], &etudiants[droite]);
	*indPivot = droite;
}


//Implementation de la  fonction quicksort
void quickSort(Etudiant etudiants[], int debut, int fin) {
	if (debut < fin) {
		int indPivot;
		partitionner2(etudiants, debut, fin, &indPivot);
        quickSort(etudiants, debut, indPivot - 1);
        quickSort(etudiants, indPivot + 1, fin);
    }
}


//Implementation d'une fonction effectue une recherche dichotomique uniquement dans le tableau de notes
int rechercheDichotomique(Etudiant etudiants[], int nombre_etudiants, float noteCherchee) {
	int gauche = 0;
    int droite = nombre_etudiants - 1;

    while (gauche <= droite) {
        int milieu = gauche + (droite - gauche) / 2;
        if (fabs(etudiants[milieu].note - noteCherchee) < 0.01) { // 0.01 est l'epsilon pour la comparaison des notes
            return milieu;
        }
        if (etudiants[milieu].note < noteCherchee) {
            droite = milieu - 1;
        } else {
            gauche = milieu + 1;
        }
    }
    return -1; // Retourne -1 si la note n'est pas trouvée
}

int main() {
	Etudiant etudiants[MAX_ELEVES];
	int nombre_etudiants = 0;
	
    creer(etudiants, &nombre_etudiants);//Appel de la fonction creer pour lire les donnees du fichier et initialiser les 4 tableaux   
	
    quickSort(etudiants, 0, nombre_etudiants - 1); //Appel de la fonction quickSort pour trier les donnees par ordre decroissant de la note
    
    int i = 0;
    while (i < nombre_etudiants){
    	afficherEtudiant(etudiants[i]);
    	i++;
	}
    
    
	printf("\nNombre d'etudiants: %d\n", nombre_etudiants);//Print pour afficher le nombre d'étudiants dans la liste
	
	printf("Meilleur resultat :"); // Affichage de la meilleure note
    afficherEtudiant(etudiants[0]); //Appel de la fonction afficherEtudiant pour afficher les informations du meilleur etudiant
	
	printf("Pire resultat :");// Affichage de la pire note
    afficherEtudiant(etudiants[nombre_etudiants - 1]); //Appel de la fonction afficherEtudiant pour afficher les informations du pire etudiant.
	
	// Recherche dichotomique pour une note spécifique
    float noteCherchee;
    int validInput;
    
    bool continuerRecherche = true;
    while (continuerRecherche) {
    	do {
    		printf("Entrez la note a chercher : ");
    		validInput = scanf("%f", &noteCherchee);
    		while(getchar() != '\n');
    	} while (validInput != 1);

        int resultatRecherche = rechercheDichotomique(etudiants, nombre_etudiants, noteCherchee);
        if (resultatRecherche != -1) {
        	printf("La note a ete trouve :\n");
            afficherEtudiant(etudiants[resultatRecherche]);
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
