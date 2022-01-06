#include"utils.h"

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
