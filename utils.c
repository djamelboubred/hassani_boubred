#include "utils.h"

void get_path_from_user(char* path_input){
	printf("Veuillez saisir le nom de votre fichier contenant la/les séquence(s):\n");
	
	scanf("%s",path_input)
	FILE* fpath_input= fopen("path_input","r");
		if (!fpath_input){
			printf(stderr, "L'ouverture a échoué");
			exit(1);
		}
	fclose(fpath_input);
}

void extract_sequence(const char* path_input, char* sequence){
	FILE* foutput =NULL;
	int i=0;
	foutput = fopen("path_input", "r");
		if (!foutput){
			fprintf(stderr, "L'ouverture a échoué");
			exit(1);
		}	
		while (fgets(fpath_input) !=EOF){
			 sequence[i] = fgets(fpath_input, "%80s")
			 i++;
		}
		fclose(foutput);
		exit(0);

void save_sequence(const char* path_output, char* sequence){
	FILE* finput;
	int i = 0;
	int j = 0;
	int fin =1;
	finput = fopen("sequence.fasta", "a");
		if(!finput){
			printf(stderr, "L'ouverture a échoué");
			exit(1);
		}
		// pas dd'utilisation de tableau ni de matrix utilisisere une suite de charactère pour la fonction en dessous et au dessus 
			while (fin!=0){
				if(sequence[i][j] = ">"){
				fputs(sequence.fasta, "%s\n", sequence[0]);
				}
			else{
				if((sequence[i][j] = "")&& (j<80)){
					fin = 0;
					}
				else{
					fputc(sequence.fasta, "%c\n", sequence[i][j]	
