# Tp3_ift1969
Numéro 1 : Matrices 
Pour la partie 1 de ce travail, vous allez modifiez le programme tp3Partie1.c pour qu’il effectue les traitements demandés.
Votre programme doit déclarer une matrice additionnelle et l’initialiser comme suit :
C = 	1 7 0 1	
	0 9 2 0	
	3 7 2 5	
	4 6 7 3
Quelques définitions :		
•	Une matrice A est diagonale si elle est carrée et que aij == 0 pour tout i != j.
•	Une matrice A est tridiagonale si elle est carrée et que aij == 0 pour tout |i-j|>= 2.
•	Une matrice A est symétrique si elle est carrée et que aij == aji pour tout i et j.
•	La matrice B de taille m x n est la transposée de A de taille n x m si bij == aji pour tout 0 <= i < m et 0 <= j < n .
•	Le produit d’une matrice A de taille k x n et d’une matrice B de taille n x m est une matrice C de taille k x m où  cij = ai0 * b0j +ai1 * b1j + ai2 * b2j  + ... + ai n-1 * bn-1 j pour tout 0 <= i < k et 0 <= j < m .
Écrivez des fonctions pour réaliser chacun des traitements demandés.  
Au début du traitement, le programme doit afficher toutes les matrices déjà initialisées (A, B, C et D). Ces fonctions doivent être assez générales pour fonctionner avec des matrices reçues en paramètres.
Après chaque traitement, votre programme doit afficher le résultat à l’écran dans un message significatif.
Ex : La matrice B est symetrique.
Traitement demandé pour la remise de la partie 1.
•	Déterminez si les matrices A, B, C et D sont symétriques
•	Déterminez si les matrices A et B sont diagonales
•	Déterminez si les matrices A et D sont tridiagonales
•	Effectuez le traitement nécessaire pour qu’une matrice Res soit la transposée de D et affichez ensuite la matrice Res.
•	Effectuez le traitement nécessaire pour qu’une matrice Res soit le produit de B par D et affichez ensuite la matrice Res.
Critères de correction du numéro 1
Bon fonctionnement	6 points
Découpage du traitement en fonctions	10 points
Présentation des résultats et lisibilité du programme	4 points


Numéro 2 : Tableaux, tri rapide et recherche dichotomique 
Vous disposez du fichier notes.txt (disponible sur le site Studium du cours) d’un maximum de 200 lignes.  Chaque ligne contient le numéro de l’étudiant, son nom (20 caractères), son prénom (20 caractères) et sa note.
Exemple de données du fichier :
1000 Docteur             Albert              65.5
1001 Solo                Hanz                23.4
1002 Caillou             Frederic            78.7
…

Écrivez un programme, en langage C, pour lire les données du fichier et les placer dans 4 tableaux.

De plus, votre programme doit faire :
•	Trier les tableaux, en utilisant le QuickSort, en ordre décroissant de la note.
•	Faire afficher le numéro, le nom, le prénom et la note de l’étudiant ayant obtenu le meilleur résultat.
•	Faites de même pour l’étudiant ayant le pire résultat. 
•	Demander à l’usager une note à chercher et utiliser la recherche dichotomique pour afficher le numéro de l’étudiant ayant obtenu cette note, ou un message indiquant que la note ne s’y trouve pas. Répéter tant que l’usager veut faire des recherches.

Critères de correction du numéro 2
Bon fonctionnement	8 points
Présentation des résultats et lisibilité du programme	2 points

 
Numéro 3 : Tableaux de structures 
Écrivez un autre programme qui va refaire le même traitement que le numéro 2 en utilisant une structure et un tableau de structures.

Critères de correction du numéro 3
Bon fonctionnement	6 points
Définition de la structure	2 points
Définition et remplissage du tableau de structures	2 points

