#include"utils.h"

char transcription(char* sequence){
	// mettre extract sequence 
	
	int i;
	char sequence_ARN;
	while(sequence[i]!=EOF){ 
		if(sequence[i]="<"){	//prend en compte l'intitulé de la séquence
			while(sequence[i]!="\n"){ // et on réecrit l'intitulé de lma séquence
				sequence_ARN[i]=sequence[i];
				i=i+1;
			}
		}
		if(sequence[i]="T"){		//procéde à la transcription
			sequence_ARN[i]="U';	
		}
		else{				//sinon reprend juste le nucléotide de la séquence
			sequence_ARN[i]=sequence[i];
		}
	}
	return sequence_ARN;

}
