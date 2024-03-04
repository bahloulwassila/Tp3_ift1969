/*
    Matrices.c
	Cours IFT1969 A23, Enseignant : Michel Reid
	Traitements sur des matrices d'entiers d'au plus 10X10
	Travail fait par :
    Wassila 20183065
*/
#include <stdio.h>

#define MAX 10

typedef int Matrice[MAX][MAX];

/* fonction servant a determiner si une matrice de ln X col est carree
   
   Comme aucun traitement est effectue sur les valeurs dans la matrice,
   il n'est pas utile de la passer en parametre. 

   Parametres : ln et col le nombre de lignes et de colonnes contenant
                les valeurs initialisees de la matrice.

   Resultat : 1 (vrai) si le ln est egal a col, 0 (faux) sinon
*/

int estCarree(int ln, int col) {
    return ln == col ? 1 : 0;
}

/* fonction servant a afficher une matrice de ln X col    

   Parametres : M, le tableau (matrice),ln et col le nombre de lignes 
                et de colonnes contenant les valeurs initialisees de la matrice
				et message une chaine de caracteres pour identifier la matrice.

   Resultat :   aucun, affichage direct a l'ecran
*/

void afficheMatrice(Matrice m, int ln, int col, char *message)
{
    int i, j;

    printf("La matrice %s de taille %d X %d\n", message, ln, col);

    for (i = 0; i < ln; i++)
    {
        for (j = 0; j < col; j++)
            printf("%4d", m[i][j]);
        printf("\n");
    }
    printf("\n");
}

/* fonction servant a effectuer le produit scalaire d'une matrice de ln X col 
   avec un entier    

   Parametres : M, le tableau (matrice),ln et col le nombre de lignes 
                et de colonnes contenant les valeurs initialisees de la matrice
				et operande l'entier pour la multiplication et Res, le tableau
				pour le resultat.

   Resultat :   aucun résultat de retourne, par contre, les elements de Res seront changés
*/

void produitScalaire(Matrice m, Matrice Res, int ln, int col, int operande)
{
    int i, j;

    for (i = 0; i < ln; i++)
    {
        for (j = 0; j < col; j++)
            Res[i][j] = m[i][j] * operande;
    }
}

/* fonction servant a determiner si une matrice de ln X col est une matrice
   identitee
   
   
   Parametres : ln et col le nombre de lignes et de colonnes contenant
                les valeurs initialisees de la matrice.

   Resultat : 1 (vrai) si la matrice est l'identitee, 0 (faux) sinon
*/

int estIdentitee(Matrice m, int ln, int col)
{
    int i, j;

	/* la matrice doit etre carree */
	
    if (!estCarree(ln, col))
        return 0;
	
	/* si une valeur de la diagonale est different de 1 ou encore 
	si une valeur qui n'est pas sur la diagonale est different de 0
	alors ce n'est pas l'identitee
	*/
	
    for (i = 0; i < ln; i++) {
        for (j = 0; j < col; j++)
        {
            if (i == j && m[i][j] != 1)
                return 0;
            else if (i != j && m[i][j] != 0)
                return 0;
        }
    }
    return 1;
}

int estSymetrique(Matrice m, int ln, int col){
    int i, j;

    if (!estCarree(ln, col)) {
        return 0;
	}

    for (i = 0; i < ln; i++) {
    	
        for (j = 0; j < col; j++)
        {
            if (m[i][j] != m[j][i]) {
                return 0;
        	}
        }
    }
    return 1;
}

int estDiagonale(Matrice m, int ln, int col) {
    int i, j;

    if (!estCarree(ln, col)) {
        return 0;
	}

    for (i = 0; i < ln; i++) {
        for (j = 0; j < col; j++) {
            if (i != j && m[i][j] != 0) {
                return 0;
        	}
        }
    }
    return 1;
}

int estTridiagonale(Matrice m, int ln, int col) {
    int i, j;

    if (!estCarree(ln, col)) {
        return 0;
    }

    for (i = 0; i < ln; i++) {
        for (j = 0; j < col; j++) {
            if (i != j && abs(i - j) > 1 && m[i][j] != 0) {
                return 0;
        	}
        }
    }
    return 1;
}

void transposee(Matrice m, Matrice Res, int ln, int col) {
    int i, j;

    for (i = 0; i < ln; i++) {
        for (j = 0; j < col; j++) {
            Res[j][i] = m[i][j];
        }
    }
}

void produitMatriciel(Matrice A, Matrice B, Matrice Res, int lnA, int colA, int lnB, int colB)
{
    int i, j, k;

    for (i = 0; i < lnA; i++) {
        for (j = 0; j < colB; j++) {
            Res[i][j] = 0;
            for (k = 0; k < colA; k++) {
                Res[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    Matrice A = {{1, 2, 0, 0, 0}, {2, 3, 9, 0, 0}, {0, 9, 5, 2, 0},
                 {0, 0, 2, 7, 3}, {0, 0, 0, 3, 5}};
    int nbLnA = 5, nbColA = 5;

    Matrice B = {{2, 0, 0, 0}, {0, 4, 0, 0}, {0, 0, 8, 0}, {0, 0, 0, 5}};
    int nbLnB = 4, nbColB = 4;

    Matrice C = {{1, 7, 0, 1}, {0, 9, 2, 0}, {3, 7, 2, 5}, {4, 6, 7, 3}};
    int nbLnC = 4, nbColC = 4;

    Matrice D = {{3, 7, 5}, {1, 4, 2}, {9, 3, 5}, {9, 1, 6}};
    int nbLnD = 4, nbColD = 3;

	/*Matrice à remplir pour produit scalaire, Transposée et produit matriciel*/

    Matrice Res;
    int nbLnRes, nbColRes;
    
    afficheMatrice(A, nbLnA, nbColA, "A");
    afficheMatrice(B, nbLnB, nbColB, "B");
    afficheMatrice(C, nbLnC, nbColC, "C");
    afficheMatrice(D, nbLnD, nbColD, "D");
    
    	/* produit scalaire : Res = 5A */
	produitScalaire(A,Res,nbLnA, nbColA, 5);
	nbLnRes = nbLnA;
	nbColRes = nbColA;
	
	afficheMatrice(Res, nbLnRes, nbColRes, "resultant du produit scalaire 5A");
	
	/* test si la matrice B est une matrice identitee */
    printf("La matrice B %s une matrice identitee.\n\n", 
		    estIdentitee(B,nbLnB, nbColB)?"est":"n'est pas");
		    
    printf("La matrice A %s symetrique.\n\n", estSymetrique(A, nbLnA, nbColA) ? "est" : "n'est pas");
    printf("La matrice B %s symetrique.\n\n", estSymetrique(B, nbLnB, nbColB) ? "est" : "n'est pas");
    printf("La matrice C %s symetrique.\n\n", estSymetrique(C, nbLnC, nbColC) ? "est" : "n'est pas");
    printf("La matrice D %s symetrique.\n\n", estSymetrique(D, nbLnD, nbColD) ? "est" : "n'est pas");

    printf("La matrice A %s diagonale.\n\n", estDiagonale(A, nbLnA, nbColA) ? "est" : "n'est pas");
    printf("La matrice B %s diagonale.\n\n", estDiagonale(B, nbLnB, nbColB) ? "est" : "n'est pas");
    
    printf("La matrice A %s tridiagonale.\n\n", estTridiagonale(A, nbLnA, nbColA) ? "est" : "n'est pas");
    printf("La matrice D %s tridiagonale.\n\n", estTridiagonale(D, nbLnD, nbColD) ? "est" : "n'est pas");
	
	Matrice ResTransposee;
    transposee(D, ResTransposee, nbLnD, nbColD);
    afficheMatrice(ResTransposee, nbColD, nbLnD, "transposee de D");
    
	Matrice ResProduit;
    produitMatriciel(B, D, ResProduit, nbLnB, nbColB, nbLnD, nbColD);
    afficheMatrice(ResProduit, nbLnB, nbColD, "produit de B par D");
}
