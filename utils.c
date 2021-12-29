
#include "utils.h"

/*Stocke dans nom_fichier un nom de fichier saisi par l'utilisateur*/

void stocker_nom_fichier(char* nom_fichier)
{
  printf("Veuillez saisir le nom de votre fichier contenant la ou les séquences à analyser: ");
  scanf("%s",nom_fichier);
  printf("%s\n",nom_fichier);
}

/*Stocke dans la variable sequence, une séquence contenue dans un fichier au format FASTA accessible via le chemin précisé en path_input*/

void extract_sequence_de_proteine(FILE* fichier, proteine sequence[])
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
      sequence[i]=*creation_proteine(lettre_lu);
    }
  }
  sequence[i+1]=*creation_proteine('\0');
}

/* Ecrit dans un fichier la séquence contenue dans la variable sequence
en renvoyant à la ligne tous les 80 caractères, comme dans le format FASTA*/
	void save_sequence(const char* path_output, char* sequence){
		FILE* fsequence=fopen("path_output","w");
		if (!fextract){
				printf(stderr, "L'ouverture a échoué");
				return EXIT_FAILURE;
		}
		int i=0;
		while(sequence[i]*!="\0"){
			for(i=0,i<80,i++){
				fputc(sequence[i]*);
			}
			fputc("\n");
		}
		fclose(fsequence);
	}
