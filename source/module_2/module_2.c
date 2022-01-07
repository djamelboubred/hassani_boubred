#include"module_2.h"

void transcription(char* sequence,int taille){
	char path_output[18]="sequenceARN.fasta";
	int i=0;
	int j=0;

	char* sequence_ARN = malloc(sizeof(sequence_ARN)*taille);
	while(j<taille){
		if(sequence[i]=='T'){		//procéde à la transcription
			sequence_ARN[j]='U';
		}
		else{		//sinon reprend juste le nucléotide de la séquence
			sequence_ARN[j]=sequence[i];
		}
		j++;
		i++;
	}
	sequence_ARN[j]='\0';
	printf("\ntranscription effectué:\n=>\nsequence:5'-%s-3'\n",sequence_ARN);
	save_sequence(path_output,sequence_ARN);
}

int module_2(){
	printf("\n MODULE 2: Transcription d’une séquence ADN en séquence ARN \n");
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
	return 0;
}

int main(){
	module_2();
}
