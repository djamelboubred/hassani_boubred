#include <stdio.h>
#include <stdlib.h>

/*void stocker_nom_fichier_p(char* nom_fichier)
{
  printf("Veuillez saisir le nom de votre fichier contenant la ou les séquences à analyser: ");
  scanf("%s",nom_fichier);
  printf("%s\n",nom_fichier);
  FILE* finput= fopen(nom_fichier,"r"); //on verifie que l'ouverture du fichier est bien possible
    if (!finput)
    {
      fprintf(stderr, "L'ouverture a échoué\n");
      exit(1) ;
    }
  fclose(finput);
}
*/

void stocker_nom_fichier(char nom_fichier)
{
  printf("Veuillez saisir le nom de votre fichier contenant la ou les séquences à analyser: ");
  scanf("%s",&nom_fichier);
  printf("%s\n",nom_fichier);
  FILE* finput= fopen(nom_fichier,"r"); //on verifie que l'ouverture du fichier est bien possible
    if (!finput)
    {
      fprintf(stderr, "L'ouverture a échoué\n");
      exit(1) ;
    }
  fclose(finput);
}


//stocke dans nom_fichier un fichier donné par utilisateur

int main()
{
  char filename=malloc(sizeof(char));

 stocker_nom_fichier(filename);
}
