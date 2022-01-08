#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TRUE 0
#define FALSE 1

 recherche_sous_chaine_max(char matrice[][])
 {
   printf("%c\n",matrice[0][0]);
   printf("%c\n",matrice[1][0]);
   printf("%c\n",matrice[0][1]);
   printf("%c\n",matrice[1][1]);
 }

int main()
{
   /*printf("\n MODULE 7: Recherche de la plus grande sous-chaîne de polarité commune à 2 séquences \n");
   printf("L'ordinateur va vous demander à une seule reprise de taper le chemin menant à votre fichier contenant vos sequences\n");
   char* nom_fichier1=malloc(sizeof(char));
   char* nom_fichier2=malloc(sizeof(char));
   stocker_nom_fichier(nom_fichier1);
   stocker_nom_fichier(nom_fichier2);

   FILE* fichier1=fopen(nom_fichier1,"r");
   FILE* fichier2=fopen(nom_fichier2,"r");
   if (!fichier1 || !fichier2)
   {
 			fprintf(stderr, "L'ouverture a échoué");
 			return EXIT_FAILURE;
 	}
   int taille1= calcul_taille_fichier(fichier1);
   int taille2= calcul_taille_fichier(fichier2);
   char matrice[taille1][taille2];*/
   char matrice[2][2]={{'A','B'},
                        {'C','D'}};
    printf("%c\n",matrice[0][0]);
    printf("%c\n",matrice[1][0]);
    printf("%c\n",matrice[0][1]);
    printf("%c\n",matrice[1][1]);
    recherche_sous_chaine_max(matrice);

 }
