#include"utils/utils.h"

int main(){

//module 1
	char* nom_fichier1= malloc(sizeof(char));
	stocker_nom_fichier(nom_fichier1);

	FILE* fichier1 = fopen(nom_fichier1,"r");
	if(!fichier1){
		fprintf(stderr, "L'ouverture à échoué.\n");
		return EXIT_FAILURE;
	}
	else{
		printf("Le fichier:\t%s à été charger avec succès\n",nom_fichier1);
	}
	int taille_fichier1= calcul_taille_fichier(fichier1);

	char* sequence= malloc(sizeof(char)*taille_fichier1);// taille maximum qui seras réduit plus tard
	extract_sequence(fichier1, sequence);
	//printf("test bis");
	fclose(fichier1);

	recherche_sequence_codante(sequence,taille_fichier1);
  //module 2
	char* nom_fichier2 = malloc(sizeof(char));
	stocker_nom_fichier(nom_fichier2);
	FILE* fichier2 = fopen(nom_fichier2,"r");
	if(!fichier2){
		fprintf(stderr, "L'ouverture à échoué.\n");
		return EXIT_FAILURE;
	}
	else{
		printf("Le fichier:\t%s à été charger avec succès\n",nom_fichier2);
	}
	int taille_fichier2 = calcul_taille_fichier(fichier2);

	char* cds = malloc(sizeof(char)*taille_fichier2);
	extract_sequence(fichier2,cds);
	transcription(cds,taille_fichier2);
  //module 3
	char* nom_fichier3 = malloc(sizeof(char));
        stocker_nom_fichier(nom_fichier3);
        FILE* fichier3 = fopen(nom_fichier3,"r");
        if(!fichier3){
                fprintf(stderr, "L'ouverture à échoué.\n");
                return EXIT_FAILURE;
        }
        else{
                printf("Le fichier:\t%s à été charger avec succès\n",nom_fichier3);
        }
        int taille_fichier3 = calcul_taille_fichier(fichier3);
        char* sequence_ARN = malloc(sizeof(char)*taille_fichier3);
        extract_sequence(fichier3,sequence_ARN);
        traduction(sequence_ARN,taille_fichier3);
	//module 4
	module_4();
	//module 5
	module_5();
	//module 6
	module_6();
}
