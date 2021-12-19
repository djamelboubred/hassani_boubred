#include "utils.h"
#define TRUE 0
#define FALSE 1

char sequence_complemenataire(char sequence, int taille){ //prend ue séquence et la taille de la séquence en argument
	char comp;
	int i = taille;
	int j=0; 

	while((sequence[i]!="\O")||(sequence[i]!="\n")){
			
		if(sequence[i]=="T"){
			comp[j]="U";
			
		}
		else{
			comp[j]=sequence[i];
			
		}
		j++;
		i--;
	}
	return comp;
}

char recherche_sequence_codante(char* path_input){
 	
	extract_sequence(const char* path_input,char* sequence);
	
	char sequence_comp;
	int debut = TRUE; //si on commence 0 sinon 1 
	int k =0; // position tu premier nucléotide afin de pouvoir 
	int j = 0; //compteur nombre de aa
	int i =0; // compteur en respectant le cadre de lecture +3 à chaque tour
	int max =0; // valeur max de la taille de la CDS // mettre pointeur 
	int brin_sens = TRUE; //Valeur 0 si on est dans le cas du brin sens et 1 si brin anti-sens
	int cadre_lecture= 0; // Indique à l'utilisateur dans qu'elle cadre de lecture se trouve la  plus grande CDS
	int taille=0; // voir si on n'importe pas cette variable qui sera déterminer lors du remplissage de notre variables sequence
	int max_brin=TRUE;// pointeur dessus!!
	int max_cadre=0;//pointeur dessus!!
	char cds;	
		while((cadre_lecture <4)&&(brin_sens = 0)){//On procéde dans l'odre le cadre de lecture 0,+1,+2 puis on change de brin et on remodifie le cadre de lecture
	
			// condition concernant l'intitulé de la séquence de telle sorte qu'on met en place une boucle qui va tourner tant qu'on est dans l'intitulé 
			if(sequence[i]="<"){
				while (sequence[i]!="\n"){
					i=i+1;
				}
			}
			if(cadre_lecture>3){
				cadre_lecture = 0;
				brin_sens = 1;



			}
			if (brin_sens == TRUE);{ 	// dans le cas du brin sens


				if(debut ==TRUE;){	//Determine le cadre de lecture => si on est au debut on prend comme i initial = au cadre de lecture 
				i=cadre_lecture;
				debut=FALSE;
				}
				
				if ((sequence[i]=="A") && (sequence[i+1]=="T") && (sequence[i+2]=="G")){ // si on trouve notre codon start
					j=3;
					k=i;	// on prend la position du codon start
					while (((sequence[i]!="T") && (sequence[i+1]!="A") && (sequence[i+2]!="A")) ||
	      	 			((sequence[i]!="T") && (sequence[i+1]!="A") && (sequence[i+2]!="G")) || 
					((sequence[i]!="T") && (sequence[i+1]!="G") && (sequence[i+2]!="A"))){ // on cherche le codon stop après avoir trouvé un codon start

					i= i+3;
					j= j+3;
					}
				}
			}
			else{	// dans le cas du brin anti sens
				
				if(debut ==TRUE;){	// si on est au debut on prend comme i initial = au cadre de lecture 
				i=taille - cadre_lecture;
				debut=FALSE;
				sequence_comp = sequence_complementaire(sequence,taille);
				}
				
				if ((sequence_comp[i]=="A") && (sequence_comp[i+1]=="T") && (sequence_comp[i+2]=="G")){ // si on trouve notre codon start
					j=3;
					k=i;
					while (((sequence_comp[i]!="T") && (sequence_comp[i+1]!="A") && (sequence_comp[i+2]!="A")) ||
	      	 			((sequence[i]!="T") && (sequence[i+1]!="A") && (sequence[i+2]!="G")) || 
					((sequence[i]!="T") && (sequence[i+1]!="G") && (sequence[i+2]!="A"))){ // on cherche le codon stop après avoir trouvé un codon start

					i= i+3;
					j+3;
					}
				}

			}
				if (max<j){ // si on a une cds de taille plus importante
					max = j;
					max_brin = brin_sens; 
					max_cadre = cadre_lecture;
					position = k;
				}
			}
			if ((sequence[i]==EOF)){ // dans le cas ou on est à la fin de la séquence
				cadre_lecture = cadre_lecture + 1;
				debut=TRUE;
				taile = i-1;// on prend i - 1 car sequence[i] est vide 
			}
			i=i+1;
		}
		
		if(max!=0){// on verifie que notre fonction fonctionne en ayant trouvé au moins une CDS
			i=0;	//on réinitialise notre compteur
			while (i<=j){	// j étant le nombre de nucléotides tant que notre compteur est infrieur ou égal au nombre de nucléotide max on boucle
				cds[i] = sequence[k];
				i++;
				k++;
			}
			printf("cadre lecture : %d\nbrin_sens:%d\t(0 si sens et 1 si anti-sens)\nCDS:\n%s",max_cadre,max_brin,cds);
		}
		else{
			print("Aucune CDS trouvée, ou le programme n'a pas fonctionné!!\n");
		}
return cds;
}
			









