#include "utils.h"


//fonction utilitaire (mis dans utils.c) permet de demander à l'utilisateur un nom de fichier pour le stocker dans une variable
void stocker_nom_fichier(char* nom_fichier)
{
  printf("\nVeuillez saisir le chemin vers votre fichier contenant la ou les séquences à analyser: ");
  scanf("%s",nom_fichier);
  printf("%s\n",nom_fichier);
}



/*Pour extraire une sequence d'un fichier en la placant dans une variable sequence*/
void extract_sequence(FILE* fichier, char sequence[])
{

  int i=-1;
  char lettre_lu;
  fseek(fichier,0,SEEK_SET);
  if(fgetc(fichier)=='>')
  {
    while(fgetc(fichier)!='\n') /*On avance le curseur jusqu'au premier saut de ligne*/
    {

    }
  }
  else
  {
    fseek(fichier,0,SEEK_SET);
  }
  while((lettre_lu=fgetc(fichier))!=EOF)
  {
    if(lettre_lu!='\n')
    {
      i++;
      sequence[i]=lettre_lu;
    }
  }
}

/* Ecrit dans un fichier la séquence contenue dans la variable sequence
en renvoyant à la ligne tous les 80 caractères, comme dans le format FASTA*/
	void save_sequence(const char* path_output, char sequence[]){
		FILE* fsequence = fopen(path_output,"w");
		if (!fsequence){
			fprintf(stderr, "L'ouverture a échoué.\n");
			EXIT_FAILURE;
		}
		int i=0;
		int compteur=1;
		while(sequence[i]!='\0'){
			if(compteur == 80){
				fprintf(fsequence, "\n");
				compteur =1;
			}
			fprintf(fsequence,"%c",sequence[i]);
			i++;
			compteur++;
		}

		fclose(fsequence);
		EXIT_SUCCESS;
		printf("La séquence a  été sauvegardé avec succès dans le fichier : %s\n", path_output);
	}


  /*Pour calculer la taille de la sequence present dans un fichier*/
  int calcul_taille_fichier(FILE* fichier)
  {
    int i=0;
    char lettre_lu;
    if(fgetc(fichier)=='>')
    {
      while(fgetc(fichier)!='\n')
      {

      }
    }
    else
    {
      fseek(fichier,0,SEEK_SET);
    }

    while((lettre_lu=fgetc(fichier))!=EOF)
    {
      if(lettre_lu!='\n') i++;
    }
    return i;
    fseek(fichier,0,SEEK_SET);
  }
