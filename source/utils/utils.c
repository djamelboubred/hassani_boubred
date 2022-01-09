#include "utils.h"


/*fonction utilitaire (mis dans utils.c) permet de demander à l'utilisateur un nom de fichier pour le stocker dans une variable
entree: fichier deja ouvert
sortie: aucune*/
void stocker_nom_fichier(char* nom_fichier){
  printf("\nVeuillez saisir le chemin vers votre fichier contenant la ou les séquences à analyser: ");
  scanf("%s",nom_fichier);
}



/*Pour extraire une sequence d'un fichier en la placant dans une variable sequence
entree: fichier deja ouvert  et une variable sequence de type tableau
sortie: aucune*/
void extract_sequence(FILE* fichier, char sequence[]){
  int i=-1;//pour avoir la bonne taille
  char lettre_lu;
  fseek(fichier,0,SEEK_SET);
  if(fgetc(fichier)=='>'){
    while(fgetc(fichier)!='\n'){ // si le debut du fichier commence par > alors sauter une ligne

    }
  }
  else{
    fseek(fichier,0,SEEK_SET);
  }
  while((lettre_lu=fgetc(fichier))!=EOF){// tant que la lettre lu n'est pas a la fin du fichier
    if(lettre_lu!='\n'){
      i++;
      sequence[i]=lettre_lu;
    }
  }
}

/* Ecrit dans un fichier la séquence contenue dans la variable sequence
en renvoyant à la ligne tous les 80 caractères, comme dans le format FASTA
entree: un pointeur du chemin donne par l'utilisateur et une variable sequence de type tableau
sortie: rien */
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


  /*Permet de calculer la taille de la sequence present dans un fichier
  entree:un fichier deja ouvert
  sortie: la taille de la sequence dans un fichier*/
int calcul_taille_fichier(FILE* fichier){
  int i=0;// compteur
  char lettre_lu; // variable optionnelle permet de rendre plus lisible le code, represente lettre lu
  if(fgetc(fichier)=='>'){ // si le debut du fichier commence par > alors sauter une ligne
    while(fgetc(fichier)!='\n'){// avancer le curseur jusqu'au saut de ligne

    }
  }
  else{ // sinon remettre le curseur au debut du fichier
    fseek(fichier,0,SEEK_SET);
  }

  while((lettre_lu=fgetc(fichier))!=EOF){// tant que la lettre lu n'est pas a la fin du fichier
    if(lettre_lu!='\n'){
      i++;//on increment i qui representera a la fin la taille du fichier
    }
  }
  return i;
  fseek(fichier,0,SEEK_SET); //pour remettre curseur en debut de fichier
}
