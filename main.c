#include"utils.h"
int main(){
	//char sequence[] ={'A','G','T','C','T','G','A','C','C','C','A','T','G','T','A','C','A','G','T','T','A','A','C','A','\0'}; 
	printf(" ");
	char* nom_fichier= malloc(sizeof(char));
	char* sequence= malloc(sizeof(char));// taille maximum qui seras réduit plus tard	
	stocker_nom_fichier(nom_fichier);
	
	FILE* fichier = NULL;
		fichier = fopen(nom_fichier,"r");
	if(!fichier){
		fprintf(stderr, "L'ouverture à échoué.\n");
		return EXIT_FAILURE;
	}
	else{
		printf("Le fichier:\t%s à été charger avec succès\n",nom_fichier);
	}
	extract_sequence(fichier, sequence);
	int taille = strlen(sequence);
	recherche_sequence_codante(sequence,taille);
	fclose(fichier);	

	char* cds = malloc(sizeof(char)*taille);	
	char* nom_fichier2 = malloc(sizeof(char));
	
	stocker_nom_fichier(nom_fichier2);
	FILE* fichier2 = NULL;
		fichier2 = fopen(nom_fichier2,"r");
	if(!fichier2){
		fprintf(stderr, "L'ouverture à échoué.\n");
		return EXIT_FAILURE;
	}
	else{
		printf("Le fichier:\t%s à été charger avec succès\n",nom_fichier2);
	}
	extract_sequence(fichier2,cds);
	taille = strlen(cds); // on modifie la taille réservé pour les chaîne de caractère en prenant celle de la cds et non de la séquence de départ
	transcription(cds,taille);
//	printf("A ton avancé après la onction transcription\n");
	//	traduction(sequence, taille);

//	printf("%s\n",sequence_AA);

}

