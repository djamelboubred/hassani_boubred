#include"utils.h"

char* transcription(char* sequence){
	// mettre extract sequence 
	int taille = strlen(sequence);
	int i=0;
	char* sequence_ARN = malloc(sizeof(sequence_ARN)*taille);
	while(sequence[i]!='\0'){ 
		if(sequence[i]=='T'){		//procéde à la transcription
			sequence_ARN[i]='U';	
		}
		else{				//sinon reprend juste le nucléotide de la séquence
			sequence_ARN[i]=sequence[i];
		}
		i++;
	}
	sequence_ARN[i]='\0';
	printf("sequence:\t5'-%s-3'\ntranscription effectué:\n=>\n=>\nsequence:\t5'%s-3'\n",sequence,sequence_ARN);

	return sequence_ARN;

}
