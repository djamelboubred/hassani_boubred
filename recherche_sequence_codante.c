#include "utils.h"
#define TRUE 0
#define FALSE 1
int recherche_max_cds(char sequence[], int* position, int cadre){
	int j=0; // compteur du nombre de nt
	int k = 0; // position initial du premier nt de la cds
	int maximum =0;   // le nombre le plus important de nt dans une cds
	int taille = strlen(sequence);
	int fin = FALSE;
	int i = cadre;	
	int seq_complet = TRUE;
//	printf("test valeur de i:%d\n",i);
//	printf("sequence : %s\n",sequence);
//	printf("taille : %d\n",taille);
	while((j==0)||(i<taille-2)){ 	
        	//printf("%d",i); fonctionne
		//printf("test dans la boucle"); fonctionne ici
		if ((sequence[i]=='A') && (sequence[i+1]=='T') && (sequence[i+2]=='G')){ // si on trouve notre codon start
                	// printf("test dans le codon start");// fonctionne 
			j=3;
                        k=i;    // on prend la position du codon start
                        while((i<taille-2)||(fin!=TRUE)){
			//	printf("entrée seconde boucle");fonctionne
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
				if((sequence[i+2]=='\0')){
	 				fin=TRUE;
                                        seq_complet = FALSE;
                                        break;
                                }  
				i= i+3;
   				j= j+3; 
			}
			//printf("test de mi parcours après econde boucle");fonctionne
                        if(seq_complet==FALSE){
                        	j=0;
                                seq_complet = TRUE;
                        }
	//	printf("test fin de boucle\n"); fonctionne
                if(maximum<j){ // si on a une cds de taille plus importante
                 	maximum = j;
                        printf("test max %d\n",maximum);// test de la plus grande
                        position =&k;
			printf("positiob dans fct = %d\n",*position);
                }
		}
	i=i+3;
	}
	return maximum;
}

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

	char* seq  = malloc(sizeof(char)*taille);// => mettre cds à la place 
	char* sequence_comp = malloc(sizeof(char)*taille);
//	int debut = TRUE; //si on commence 0 sinon 1 
	int k =0; // position du premier nucléotide afin de pouvoir initier l'écriture de notre cds la plus grande lors de la fin du traitement de notre séquence  
	int j = 0; //compteur nombres de nt
	int i =0; // compteur en respectant le cadre de lecture et la lecture de codon(+3) à chaque tour
	int max =0; // valeur max de la taille de la CDS
	int brin_sens = TRUE; //Valeur 0 si on est dans le cas du brin sens et 1 si brin anti-sens
	int cadre_lecture= 0; // Indique à l'utilisateur dans qu'elle cadre de lecture se trouve la  plus grande CDS
	int max_brin=TRUE;	//permet de connaître le brin pris en compte pour notre cds la plus grane 
	int position = 0; //position définitif de la plus grande cds
//	int fin = FALSE;
	int cadre_max;
//	int seq_complet = TRUE; // gestion erreur si \n présent dans la sequence

	sequence_complementaire(sequence,taille,sequence_comp);
	// test
//	printf("complementaire: %s\n",sequence_comp);
/*	char path_output[20] = "complementaire.fasta";
	save_sequence(path_output,sequence_comp);*/
	if(brin_sens == TRUE){
	//	printf("test entrée fonctin recherche cds\n");
		j = recherche_max_cds(sequence,&k,cadre_lecture);
	//	printf("test1");
		if(max<j){
			max=j;
			printf("valeur de k:%d\n",k);
			position = k;
			cadre_max =cadre_lecture;	
			max_brin = brin_sens;
		}
		printf("position = %d\n",position);
		cadre_lecture++;
		j = recherche_max_cds(sequence,&k,cadre_lecture);
	//	printf("test2");
		if(max<j){
			max=j;
			position= k;
			cadre_max = cadre_lecture;
			max_brin = brin_sens;

		}
		printf("position = %d\n", position);
		cadre_lecture++;
		j = recherche_max_cds(sequence,&k,cadre_lecture);
	//	printf("test3");
		if(max<j){
			max=j;
			position=k;
			cadre_max = cadre_lecture;
			max_brin = brin_sens;
		}
		brin_sens = FALSE;
	}
	if(brin_sens == FALSE){
		cadre_lecture = 0; //on réinitialise le cadre de lecture
		j = recherche_max_cds(sequence_comp,&k,cadre_lecture);
	//	printf("test4");
                if(max<j){
                        max=j;
                        position=k;
                        cadre_max =cadre_lecture;
                        max_brin = brin_sens;
                }
		printf("position = %d\n",position);
                cadre_lecture++;
                j = recherche_max_cds(sequence_comp,&k,cadre_lecture);
	//	printf("test5");
                if(max<j){
                        max=j;
                        position=k;
                        cadre_max = cadre_lecture;
                        max_brin = brin_sens;
                }
		printf("position = %d\n",position);
                cadre_lecture++;
                j = recherche_max_cds(sequence_comp,&k,cadre_lecture);
	//	printf("test6");
                if(max<j){
                        max=j;
                        position=k;
                        cadre_max = cadre_lecture;
                        max_brin = brin_sens;
                }
	}

	/*	while(fin == FALSE){//On procéde dans l'odre le cadre de lecture 0,+1,+2 puis on change de brin et on remodifie le cadre de lecture
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
							if((sequence[i+2]=='\0')){
								fin=TRUE;
								seq_complet = FALSE;
								break;
							}
							i= i+3;
							j= j+3;	
						}	
			
					}
					if(seq_complet==FALSE){
						j=0;
						seq_complet = TRUE;
					}
					i=i+3;
					if(max<j){ // si on a une cds de taille plus importante
	                	                 max = j;
        	                	         printf("test max %d\n",max);// test de la plus grande
						 max_brin = brin_sens;
                	               		 position = k;
                         		}
	
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
							if((sequence_comp[i+2]=='\0')){
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
					printf("on y est "); // test pour voir si on rentre dans la boucle 
					if(max<j){ // si on le max est inférieur au nombre de nt trouvé dans une cds j'enregistre les données de la cds
	                                	max = j;// ici le nombre de nt max
						printf("test max anti-sens %d\n",max);
	                                	max_brin = brin_sens; //le brin sur lequel il se situe
						position = k; //la position du premier nt de la cds
	                        	}

				}*/
		/*		fin=FALSE;
			}*/
			/*if(max<j){ // si on a une cds de taille plus importante
				max = j;
				max_brin = brin_sens;
				position = k;
			}*/
		/*	if ((sequence[i]=='\0')||(sequence[i+1]=='\0')||(sequence[i+2]=='\0')){ // dans le cas ou on est à la fin de la séquence
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
			}*/
	//	}
		
		if(max!=0){// on verifie que notre fonction fonctionne en ayant trouvé au moins une CDS
			i=0;	//on réinitialise notre compteur
			int x = position;
			if(max_brin == TRUE){
				while (i<max){	// j étant le nombre de nucléotides tant que notre compteur est infrieur ou égal au nombre de nucléotide max on boucle
					if(sequence[x] == '\n'){
						seq[i] = sequence[x];
					//seq[i]=sequence[k];
					x++;	
					}
					seq[i] = sequence[x];
					x++;
					i++;

				}
				seq[i]='\0';
			}
			else{
				while (i<=max){	// j étant le nombre de nucléotides tant que notre compteur est infrieur ou égal au nombre de nucléotide max on boucle
					seq[i] = sequence_comp[x];
					i++;
					x++;
				}
				seq[i]='\0';
			}

		//	printf("test : %s\n",sequence);
			printf("\nLa CDS se situe sur le brin: %d\t (0 si brin sens et 1 si brin complémentaire)\nEt sur le cadre de lecture: +%d\n",max_brin,cadre_max);
			printf("\nCDS:5'-%s-3'\n",seq);
			char path_output[10]="CDS.fasta";
			save_sequence(path_output,seq);
		}
		else{
			printf("Aucune CDS trouvée, ou le programme n'a pas fonctionné!!\n");
		}	
}
