#include "utils.h"
#define TRUE 0
#define FALSE 1

void sequence_complementaire(char sequence[], int taille, char sequence_comp[]){ //prend ue séquence et la taille de la séquence en argument

	int i;
	int j=0;

	for(i=taille;i>=0;i--){
		if(sequence[i] == '\0'){
			j--;	
		}
		if(sequence[i]=='T'){
			sequence_comp[j]='A';
			
		}
		if(sequence[i] == 'A'){
			sequence_comp[j] ='T';
		}
		if(sequence[i] =='G'){
			sequence_comp[j] = 'C';
		}
		if(sequence[i] == 'C'){
			sequence_comp[j]='G';
		}
		j++;
	}	
		sequence_comp[j] ='\0';	
}

void recherche_sequence_codante(char sequence[], int taille){

	char* seq  = malloc(sizeof(char)*taille);
	char* sequence_comp = malloc(sizeof(char)*taille);
	int debut = TRUE; //si on commence 0 sinon 1 
	int k =0; // position du premier nucléotide afin de pouvoir initier l'écriture de notre cds la plus grande lors de la fin du traitement de notre séquence  
	int j = 0; //compteur nombres de nt
	int i =0; // compteur en respectant le cadre de lecture et la lecture de codon(+3) à chaque tour
	int max =0; // valeur max de la taille de la CDS
	int brin_sens = TRUE; //Valeur 0 si on est dans le cas du brin sens et 1 si brin anti-sens
	int cadre_lecture= 0; // Indique à l'utilisateur dans qu'elle cadre de lecture se trouve la  plus grande CDS
	int max_brin=TRUE;	//permet de connaître le brin pris en compte pour notre cds la plus grane 
	int position = k;
	int fin = FALSE;
	int seq_complet = TRUE;

	sequence_complementaire(sequence,taille,sequence_comp);
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
				while((j==0)||(i<taille)){ //prend taille -4 car on exclut la lecture du caractère fin de chaîne de caractère
				
					if ((sequence[i]=='A') && (sequence[i+1]=='T') && (sequence[i+2]=='G')){ // si on trouve notre codon start
						j=3;
						k=i;	// on prend la position du codon start
						while((i<taille)||(fin==TRUE)){
			
		
	
							if((sequence[i]=='T') && (sequence[i+1]=='A') && (sequence[i+2]=='A')){
								fin=TRUE;
								break;
							}
							if((sequence[i]=='T') && (sequence[i+1]=='A') && (sequence[i+2]=='G')){
								fin=TRUE;
								break;
							}
							if((sequence[i]=='T') && (sequence[i+1]=='G') && (sequence[i+2]=='A')){
								fin=TRUE;
								break;
							}
							if((sequence[i]=='\0')){
								fin=TRUE;
								seq_complet = FALSE;
								break;
							}
							if((sequence[i+1]=='\0')){
								fin=TRUE;
								seq_complet = FALSE; //FALSE car la séquence n'est pas complete donc on ne la prend pas en compte
								break;
							}
							if((sequence[i]=='\0')){
								fin=TRUE;
								seq_complet = FALSE;
								break;
							}
				/*		while (((sequence[i]!='T') && (sequence[i+1]!='A') && (sequence[i+2]!='A')) ||
	      	 			((sequence[i]!='T') && (sequence[i+1]!='A') && (sequence[i+2]!='G')) || 
					((sequence[i]!='T') && (sequence[i+1]!='G') && (sequence[i+2]!='A'))||
					((sequence[i]=='\0')||(sequence[i+1]=='\0')||(sequence[i+2]=='\0'))){ // on cherche le codon stop après avoir trouvé un codon start
*/
							i= i+3;
							j= j+3;	
						}	
			
					}
					if(seq_complet==FALSE){
						j=0;
						seq_complet = TRUE;
					}
					i++;
						
				}	
			}
			else{
			       	if(debut ==TRUE){	// si on est au debut on prend comme i initial = au cadre de lecture 
				i=cadre_lecture;
				debut=FALSE;
				}
				while((j==0)||(i<taille)){
			
					if ((sequence_comp[i]=='A') && (sequence_comp[i+1]=='T') && (sequence_comp[i+2]=='G')){ // si on trouve notre codon start
						j=3;
						k=i;
						while((i<taille)||(fin==TRUE)){// on cherche le codon stop après avoir trouvé un codon start
						
				
					
							if((sequence_comp[i]=='T') && (sequence_comp[i+1]=='A') && (sequence_comp[i+2]=='A')){
								fin = TRUE;
								break;
							}
							if((sequence_comp[i]=='T') && (sequence_comp[i+1]=='A') && (sequence_comp[i+2]=='G')){
								fin=TRUE;
								break;
							}
							if((sequence_comp[i]=='T') && (sequence_comp[i+1]=='G') && (sequence_comp[i+2]=='A')){
								fin=TRUE;
								break;
							}
							if((sequence_comp[i]=='\0')){
								fin=TRUE;
								seq_complet = FALSE;
								break;
							}
							if((sequence_comp[i+1]=='\0')){
								fin=TRUE;
								seq_complet = FALSE; //FALSE car la séquence n'est pas complete donc on ne la prend pas en compte
								break;
							}
							if((sequence_comp[i]=='\0')){
								fin=TRUE;
								seq_complet = FALSE;
								break;
							}
							i= i+3;
							j= j+3;
						}
				
				}
					if(seq_complet == FALSE){
						j=0;
						seq_complet = TRUE;
					}
					i++;
				}
				fin=FALSE;
			}
			if(max<j){ // si on a une cds de taille plus importante
				max = j;
				max_brin = brin_sens;
				position = k;
			}
			if ((sequence[i]=='\0')||(sequence[i+1]=='\0')||(sequence[i+2]=='\0')){ // dans le cas ou on est à la fin de la séquence
				cadre_lecture = cadre_lecture + 1;
				debut=TRUE;
			}
			if ((sequence_comp[i]=='\0')||(sequence_comp[i+1]=='\0')||(sequence_comp[i+2]=='\0')){ // dans le cas ou on est à la fin de la séquence complémentaire
				cadre_lecture = cadre_lecture + 1;
				debut=TRUE;
			}
			i=i+1;
			if ((brin_sens == FALSE)&&(cadre_lecture =3)){
				fin = TRUE;
			}
		}
		
		if(max!=0){// on verifie que notre fonction fonctionne en ayant trouvé au moins une CDS
			i=0;	//on réinitialise notre compteur
			k=position;
			if(max_brin == TRUE){
				while (i<max-1){	// j étant le nombre de nucléotides tant que notre compteur est infrieur ou égal au nombre de nucléotide max on boucle
					if(sequence[k] == '\n'){
						seq[i] = sequence[k];
					//seq[i]=sequence[k];
					k++;	
					}
					seq[i] = sequence[k];
					k++;
					i++;

				}
				seq[i]='\0';
			}
			else{
				while (i<=max){	// j étant le nombre de nucléotides tant que notre compteur est infrieur ou égal au nombre de nucléotide max on boucle
					seq[i] = sequence_comp[k];
					i++;
					k++;
				}
				seq[i]='\0';
			}

			printf("test : %s\n",sequence);
			printf("\nLa CDS se situe sur le brin: %d\t (0 si brin sens et 1 si brin complémentaire)\n",max_brin);
			printf("\nCDS:5'-%s-3'\n",seq);
			char path_output[10]="CDS.fasta";
			save_sequence(path_output,seq);
		}
		else{
			printf("Aucune CDS trouvée, ou le programme n'a pas fonctionné!!\n");
		}	
}
