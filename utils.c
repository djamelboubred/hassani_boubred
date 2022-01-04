#include "utils.h"

/*Stocke dans nom_fichier un nom de fichier saisi par l'utilisateur*/

void stocker_nom_fichier(char* nom_fichier)
{
  printf("Veuillez saisir le nom de votre fichier contenant la ou les séquences à analyser:\t ");
  scanf("%s",nom_fichier);
  printf("Le fichier:\t%s à été charger avec succès\n",nom_fichier);
}

/*Stocke dans la variable sequence, une séquence contenue dans un fichier au format FASTA accessible via le chemin précisé en path_input*/
void extract_sequence(FILE* fichier, char sequence[]){
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
		FILE* fsequence=fopen("path_output","w");
		if (!fsequence){
			fprintf(stderr, "L'ouverture a échoué.\tvérifier les points suivant:\n=>le nom du fichier saisis\n=>le nom du fichier n'est pas trop grand >20 char\n=>le fichier est bien dans le répertoire\n");
			EXIT_FAILURE;
		}
		int i=0;
		while(sequence[i]!='\0'){
			for(i=0;i<80;i++){
			fprintf(fsequence,"%c",sequence[i]);
			}
			fprintf(fsequence,"\n");
			i++;
		}
		fprintf(fsequence,"%c",sequence[i]);//ecrit la fin de chaîne de caractère
		fclose(fsequence);
		EXIT_SUCCESS;
	}

