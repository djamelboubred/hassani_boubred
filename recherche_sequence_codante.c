#include "utils.h"
#define TRUE 0
#define FALSE 1

char* sequence_complementaire(char sequence[], int taille){ //prend ue séquence et la taille de la séquence en argument
	int i;
	int j=0; 
	char* comp=malloc(sizeof(char)*taille);
	
	for(i=taille-1;i>=0;i--){
			
		if(sequence[i]=='T'){
			comp[j]='A';
			
		}
		if(sequence[i] == 'A'){
			comp[j] ='T';
		}
		if(sequence[i] =='G'){
			comp[j] = 'C';
		}
		if(sequence[i] == 'C'){
			comp[j]='G';
		}
		j++;
	}	
		comp[j] ='\0';	
		printf("comp=\t3'-%s-5'\n",comp);

	return comp;
}

char* recherche_sequence_codante(/*char* path_input*/char sequence[], int taille){

//	extract_sequence(const char* path_input,char* sequence);
	char* seq  = malloc(sizeof(char)*taille);
	char* sequence_comp = malloc(sizeof(char)*taille);
	int debut = TRUE; //si on commence 0 sinon 1 
	int k =0; // position du premier nucléotide afin de pouvoir initier l'écriture de notre cds la plus grande lors de la fin du traitement de notre séquence  
	int j = 0; //compteur nombres de aa
	int i =0; // compteur en respectant le cadre de lecture et la lecture de codon(+3) à chaque tour
	int max =0; // valeur max de la taille de la CDS // mettre pointeur 
	int brin_sens = TRUE; //Valeur 0 si on est dans le cas du brin sens et 1 si brin anti-sens
	int cadre_lecture= 0; // Indique à l'utilisateur dans qu'elle cadre de lecture se trouve la  plus grande CDS
	int max_brin=TRUE;	//permet de connaître le brin pris en compte pour notre cds la plus grane 
	int max_cadre =0;	//permet de connaitre le cadre de lecture pour notre cds max pris en compte
	int position = k;
	int fin = FALSE;
	sequence_comp = sequence_complementaire(sequence,taille);
		while(fin == FALSE){//On procéde dans l'odre le cadre de lecture 0,+1,+2 puis on change de brin et on remodifie le cadre de lecture
			if(cadre_lecture>3){
				cadre_lecture = 0;
				brin_sens = FALSE;



			}
			if (brin_sens == TRUE){ 	// dans le cas du brin sens


				if(debut ==TRUE){	//Determine le cadre de lecture => si on est au debut on prend comme i initial = au cadre de lecture 
				i=cadre_lecture;
				debut=FALSE;
				}
				while((j==0)||(i<taille-4)){ //prend taille -4 car on exclut la lecture du caractère fin de chaîne de caractère
					if ((sequence[i]=='A') && (sequence[i+1]=='T') && (sequence[i+2]=='G')){ // si on trouve notre codon start
						j=3;
						k=i;	// on prend la position du codon start
						while (((sequence[i]!='T') && (sequence[i+1]!='A') && (sequence[i+2]!='A')) ||
	      	 			((sequence[i]!='T') && (sequence[i+1]!='A') && (sequence[i+2]!='G')) || 
					((sequence[i]!='T') && (sequence[i+1]!='G') && (sequence[i+2]!='A'))||(i<taille)){ // on cherche le codon stop après avoir trouvé un codon start

						i= i+3;
						j= j+3;	
					
						}	
					}
					i++;
						
				}	
			}
			else{	// dans le cas du brin anti sens
				
				if(debut ==TRUE){	// si on est au debut on prend comme i initial = au cadre de lecture 
				i=(taille-1) - cadre_lecture;
				debut=FALSE;
				}	
				while((j==0)||(i<taille-4)){
					if ((sequence_comp[i]=='A') && (sequence_comp[i+1]=='T') && (sequence_comp[i+2]=='G')){ // si on trouve notre codon start
						j=3;
						k=i;
						while (((sequence_comp[i]!='T') && (sequence_comp[i+1]!='A') && (sequence_comp[i+2]!='A')) ||
	      	 			((sequence[i]!='T') && (sequence[i+1]!='A') && (sequence[i+2]!='G')) || 
					((sequence[i]!='T') && (sequence[i+1]!='G') && (sequence[i+2]!='A'))||(i<taille)){ // on cherche le codon stop après avoir trouvé un codon start

						i= i+3;
						j= j+3;
						}
					}
					i++;
				}
			}
			if (max<j){ // si on a une cds de taille plus importante
				max = j;
				max_brin = brin_sens; 
				max_cadre = cadre_lecture;
				position = k;
			}
			if ((sequence[i]=='\0')){ // dans le cas ou on est à la fin de la séquence
				cadre_lecture = cadre_lecture + 1;
				debut=TRUE;
			}
			i=i+1;
			if ((brin_sens == FALSE)&&(cadre_lecture >3)){
				fin = TRUE;
			}
		}
		
		if(max!=0){// on verifie que notre fonction fonctionne en ayant trouvé au moins une CDS
			i=0;	//on réinitialise notre compteur
			if(max_brin == TRUE){
				while (i<=max){	// j étant le nombre de nucléotides tant que notre compteur est infrieur ou égal au nombre de nucléotide max on boucle
				k = position;
				seq[i] = sequence[k];
				i++;
				k++;
				}
			}
			else{
				while (i<=max){	// j étant le nombre de nucléotides tant que notre compteur est infrieur ou égal au nombre de nucléotide max on boucle
					k=position;
					seq[i] = sequence_comp[k];
					i++;
					k++;
				}
			}
			printf("cadre lecture : %d\nbrin_sens:%d\t(0 si sens et 1 si anti-sens)\nCDS:\t5'-%s-3'\n",max_cadre,max_brin,seq);
			printf("sequence = %s\n",sequence);
		}
		else{
			printf("Aucune CDS trouvée, ou le programme n'a pas fonctionné!!\n");
		}
	return seq;	
}
