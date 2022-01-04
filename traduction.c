#include "utils.h"

//On lit le codon et on le traduit
void traduction(char sequence[],int taille){

	char* sequence_AA = malloc(sizeof(sequence_AA)*taille);
	int i=0;
	int j=0;

	while((sequence[i]!='\0')||(sequence_AA[j]=='\0')){
		if((sequence[i]=='A')&&(sequence[i+1]=='U')&&(sequence[i+2]=='G')){
			sequence_AA[j] = 'M';
		}
		if(((sequence[i]=='U')&&(sequence[i+1]=='U')&&(sequence[i+2]=='U'))||((sequence[i]=='U')&&(sequence[i+1]=='U')&&(sequence[i+2]=='C'))){
			sequence_AA[j] = 'F';
		}
		if(((sequence[i]=='U')&&(sequence[i+1]=='U')&&((sequence[i+2]=='A')||(sequence[i+2]=='G')))||
		((sequence[i]=='C')&&(sequence[i+1]=='U')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')||(sequence[i+2]=='A')||(sequence[i+2]=='G')))){
			sequence_AA[j]='L';
		}
		if((sequence[i]=='A')&&(sequence[i+1]=='U')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')||(sequence[i+2]=='A'))){
			sequence_AA[j]='I';
		}
		if((sequence[i]=='G')&&(sequence[i+1]=='U')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')||(sequence[i+2]=='A')||(sequence[i+2]=='G'))){
			sequence_AA[j]='V';
		}
		if(((sequence[i]=='U')&&(sequence[i+1]=='C')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')||(sequence[i+2]=='A')||(sequence[i+2]=='G')))||
		((sequence[i]=='A')&&(sequence[i+1]=='G')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')))){
			sequence_AA[j]='S';
		}
		if((sequence[i]=='C')&&(sequence[i+1]=='C')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')||(sequence[i+2]=='A')||(sequence[i+2]=='G'))){
			sequence_AA[j]='P';
		}
		if((sequence[i]=='A')&&(sequence[i+1]=='C')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')||(sequence[i+2]=='A')||(sequence[i+2]=='G'))){
			sequence_AA[j]='T';
		}
		if((sequence[i]=='G')&&(sequence[i+1]=='C')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')||(sequence[i+2]=='A')||(sequence[i+2]=='G'))){
			sequence_AA[j]='A';
		}
		if(((sequence[i]=='C')&&(sequence[i+1]=='G')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')||(sequence[i+2]=='A')||(sequence[i+2]=='G')))
		||((sequence[i]=='A')&&(sequence[i+1]=='G')&&((sequence[i+2]=='A')||(sequence[i+2]=='G')))){
			sequence_AA[j]='R';
		}
		if((sequence[i]=='G')&&(sequence[i+1]=='G')&&((sequence[i+2]=='U')||(sequence[i+2]=='C')||(sequence[i+2]=='A')||(sequence[i+2]=='G'))){
			sequence_AA[j]='G';
		}
		if((sequence[i]=='U')&&(sequence[i+1]=='A')&&((sequence[i+2]=='U')||(sequence[i+2]=='C'))){
			sequence_AA[j]='Y';
		}
		if(((sequence[i]=='U')&&(sequence[i+1]=='A')&&((sequence[i+2]=='A')||(sequence[i+2]=='G')))||((sequence[i]=='U')&&(sequence[i+1]=='G')&&(sequence[i+2]=='A'))){
			sequence_AA[j]='*';
			sequence_AA[j+1]='\0';
		}
		if((sequence[i]=='C')&&(sequence[i+1]=='A')&&((sequence[i+2]=='U')||(sequence[i+2]=='C'))){
			sequence_AA[j]='H';
		}
		if((sequence[i]=='C')&&(sequence[i+1]=='A')&&((sequence[i+2]=='A')||(sequence[i+2]=='G'))){
			sequence_AA[j]='Q';
		}
		if((sequence[i]=='A')&&(sequence[i+1]=='A')&&((sequence[i+2]=='U')||(sequence[i+2]=='C'))){
			sequence_AA[j]='N';
		}
		if((sequence[i]=='A')&&(sequence[i+1]=='A')&&((sequence[i+2]=='A')||(sequence[i+2]=='G'))){
			sequence_AA[j]='K';
		}
		if((sequence[i]=='G')&&(sequence[i+1]=='A')&&((sequence[i+2]=='U')||(sequence[i+2]=='C'))){
			sequence_AA[j]='D';
		}
		if((sequence[i]=='G')&&(sequence[i+1]=='A')&&((sequence[i+2]=='A')||(sequence[i+2]=='G'))){
			sequence_AA[j]='E';
		}
		if((sequence[i]=='U')&&(sequence[i+1]=='G')&&((sequence[i+2]=='U')||(sequence[i+2]=='C'))){
			sequence_AA[j]='C';
		}
		if((sequence[i]=='U')&&(sequence[i+1]=='G')&&((sequence[i+2]=='G'))){
			sequence_AA[j]='W';
		}
		i=i+3;
		j++;
	}
	printf("sequence traduite :\t5'-%s-3'\n",sequence_AA);
}
