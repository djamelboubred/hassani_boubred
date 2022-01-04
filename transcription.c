#include"utils.h"

void transcription(char* sequence,int taille){
	char* SequenceTranscris;
	int i=0;
	int j=0;
	char* sequence_ARN = malloc(sizeof(sequence_ARN)*taille);
	while(sequence[i]!='\0'){ 
		if(sequence[i]=='T'){		//procéde à la transcription
			sequence_ARN[j]='U';	
		}
		else{		//sinon reprend juste le nucléotide de la séquence
			sequence_ARN[j]=sequence[i];
		}
		if(sequence[i]=='\n'){
		}
		if(j%80==0){
			j++;
			sequence_ARN[j]='\n';
		}
		j++;
		i++;
	}
	sequence_ARN[j]='\0';
	save_sequence(SequenceTranscris,sequence_ARN);
	printf("sequence:\t5'-%s-3'\ntranscription effectué:\n=>\n=>\nsequence:\t5'%s-3'\n",sequence,sequence_ARN);
}
