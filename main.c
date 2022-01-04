#include"utils.h"
int main(){
	//char sequence[] ={'A','G','T','C','T','G','A','C','C','C','A','T','G','T','A','C','A','G','T','T','A','A','C','A','\0'}; 
	char* nom_fichier= malloc(sizeof(char));
	char* sequence= malloc(sizeof(char));// taille maximum qui seras réduit plus tard	
	stocker_nom_fichier(nom_fichier);
	FILE* fichier = fopen(nom_fichier,"r");
	if(!fichier){
		fprintf(stderr, "L'ouverture à échoué.\n");
		return EXIT_FAILURE;
	}
	extract_sequence(fichier, sequence);
	int taille = strlen(sequence);
//	char* cds = malloc(sizeof(char)*taille);	
	recherche_sequence_codante(sequence,taille);
//	taille = strlen(sequence); // on modifie la taille réservé pour les chaîne de caractère en prenant celle de la cds et non de la séquence de départ
//	transcription(sequence,taille);//remplacer nom_fichier par cds
//	printf("A ton avancé après la onction transcription\n");
	//	traduction(sequence, taille);

//	printf("%s\n",sequence_AA);

}

