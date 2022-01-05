#include "utils.h"

/*Stocke dans nom_fichier un nom de fichier saisi par l'utilisateur*/

void stocker_nom_fichier(char* nom_fichier)
{
  printf("Veuillez saisir le nom de votre fichier contenant la ou les séquences à analyser:\t ");
  scanf("%s",nom_fichier);
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
		FILE* fsequence=fopen(path_output,"w");
		if (!fsequence){
			fprintf(stderr, "L'ouverture a échoué.\tvérifier les points suivant:\n=>le nom du fichier saisis\n=>le nom du fichier n'est pas trop grand >20 char\n=>le fichier est bien dans le répertoire\n");
			EXIT_FAILURE;
		}
		int i=0;
		int compteur=1;
		while(sequence[i]!='\0'){
			if(compteur == 80){
				fprintf(fsequence, "\n");
				compteur =0;
			}
			fprintf(fsequence,"%c",sequence[i]);
			i++;
			compteur++;
		}
			
			
			/*	for(j=i;j<i+80;j++){
				fprintf(fsequence,"%c",sequence[j]);
				if(sequence[j] =='\0'){
					fprintf(fsequence,%c,sequence[i]);
					j=j-1;
					break;
			}
			fprintf(fsequence,"\n");
			i=j+1;
		}*/
	
		fclose(fsequence);
		EXIT_SUCCESS;
		printf("La séquence à été sauvegarder avec succès dans le fichier : %s\n", path_output);	
	}
