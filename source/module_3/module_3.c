#include "module_3.h"

//On lit le codon et on le traduit
void traduction(char sequence[],int taille){

	char* sequence_AA = malloc(sizeof(sequence_AA)*taille);
	int i=0;
	int j=0;

	while((sequence[i]!='\0')||(i<taille)||(sequence_AA[j-1]=='\0')){// scrute la sequence tant qu'on n'est pas à la fin
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
		//codon stop on met un caractère de fin de chaîne de caractères
		if(((sequence[i]=='U')&&(sequence[i+1]=='A')&&((sequence[i+2]=='A')||(sequence[i+2]=='G')))||((sequence[i]=='U')&&(sequence[i+1]=='G')&&(sequence[i+2]=='A'))){
			//sequence_AA[j]='*';
			sequence_AA[j]='\0';
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
/*	char path_output[17] = "sequenceAA.fasta";
        save_sequence(path_output,sequence_AA);
*/
	// erreur lors du remplissage du fichier sequenceAA.fasta, cette erreur est visible uniquement lors de l'appelle de la fonction save_sequence(path_output,sequence_AA); du module 3
	// erreur est : malloc(): corrupted top size
	free(sequence_AA);
}

int module_3(){
	printf("\n MODULE 3: Traduction d’une séquence codante en séquence protéique \n");
	char* nom_fichier3 = malloc(sizeof(char));
  stocker_nom_fichier(nom_fichier3);
  FILE* fichier3 = fopen(nom_fichier3,"r");
  if(!fichier3){
          fprintf(stderr, "L'ouverture à échoué.\n");
          return EXIT_FAILURE;
  }
  else{
          printf("Le fichier:\t%s à été charger avec succès\n",nom_fichier3);
  }
  int taille_fichier3 = calcul_taille_fichier(fichier3);
  char* sequence_ARN = malloc(sizeof(char)*taille_fichier3);
  extract_sequence(fichier3,sequence_ARN);
  traduction(sequence_ARN,taille_fichier3);
	free(sequence_ARN);
	return 0;
}

int main(){
	module_3();
}
