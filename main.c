#include"utils.h"
int main(){
	char sequence[] ={'A','G','T','C','T','G','A','C','C','C','A','T','G','T','A','C','A','G','T','C','A','G','C','A','\0'};
	int taille = strlen(sequence);
	//recherche_sequence_codante(sequence,taille);
	char* sequenceTranscris = malloc(sizeof(sequenceTranscris)*taille);
	sequenceTranscris = transcription(sequence);
	printf("vérification:%s\n",sequenceTranscris);
	//	char* sequence_AA;
//	sequence_complementaire(sequence,taille);
	//char* cds = malloc(sizeof(char)*taille);
//	recherche_sequence_codante(sequence,taille);
//	traduction(sequence,sequence_AA);
//	printf("%s\n",sequence_AA);
	printf("\nMesage de fin\n");
}
// pensé à une allocation dinamique en utilisant malloc
//
