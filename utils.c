
#include "utils.h"

/*Stocke dans path_input un nom de fichier saisi par l'utilisateur*/

void get_path_from_user(char* path_input){
	printf("Veuillez saisir le nom de votre fichier contenant la séquence à analyser:\n");
	scanf("%s",path_input);
	FILE* finput= fopen("path_input","r");
		if (!finput){
			printf(stderr, "L'ouverture a échoué");
			return EXIT_FAILURE ;
		}
	fclose(finput);
}

/*Stocke dans la variable sequence, une séquence contenue dans un fichier au format FASTA accessible via le chemin précisé en path_input*/

void extract_sequence(const char* path_input, char* sequence){

	FILE* fextract=fopen("path_input","r");
	if (!fextract){
			printf(stderr, "L'ouverture a échoué");
			return EXIT_FAILURE;
	}

	sequence = malloc(taille * sizeof(int));/*Allocation dynamique d'un tableau car je ne sais pas d'avance la taille de la sequence*/
	if (taille == NULL){ /*message d'erreur si la demande de memoire a échoué*/
        exit(0);
  }
	/* Stocker les elements du fichier dans le tableau sequence*/
	/* Je ne veux pas inserer les retours a la ligne, ni prendre en compte la 1er ligne*/
	while(fgetc(fextract)!=EOF && fgets(fextract)!=0){
		if(fgetc(fextract)!="\n"){
			sequence=fgetc(fextract);
		}
		else{
			fgetc(fextract);
		}
	fclose(fextract);
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
