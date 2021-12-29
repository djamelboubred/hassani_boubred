#include"utils.h"
int main(){
	char sequence[] ={'A','G','T','C','T','G','A','C','C','C','A','T','G','T','A','C','A','G','T','C','A','G','C','A','\0'};
	int taille = strlen(sequence);
	//	char* sequence_AA;
//	sequence_complementaire(sequence,taille);
	//char* cds = malloc(sizeof(char)*taille);
	recherche_sequence_codante(sequence,taille);
//	traduction(sequence,sequence_AA);
//	printf("%s\n",sequence_AA);
	printf("\nLe programme viens de finir pour la fonction recherche sequence codante");
}
// pensé à une allocation dinamique en utilisant malloc
//
