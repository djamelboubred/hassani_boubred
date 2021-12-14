#include "utils.h"



extract_sequence(const char* path_input, char* sequence);


// void ou int ; soit je return sois je return rien à voir 
int cds_max(char* sequence, int* max_brin, int* max_cadre,int* taille,char* max_cds){
// création d'une fonction qui recherche un codon en particulier 
	
	int debut = 0; //si on commence 0 sinon 1 
	int j = 0; //compteur nombre de aa
	int i =0; // compteur en respectant le cadre de lecture +3 à chaque tour
	int max =0; // valeur max de la taille de la CDS // mettre pointeur 
	int brin_sens = 0; //Valeur 0 si on est dans le cas du brin sens et 1 si brin anti-sens
	int cadre_lecture= 0; // Indique à l'utilisateur dans qu'elle cadre de lecture se trouve la  plus grande CDS
	int atg = 0; // Si on est dans le premier codon start la valeur et 0 en revanche si on trouve un autre ATG dans la CDS on ne le prend pas en compte afin d'obtenir la plus grande cds
	// peut potentiellement supprimé variable atg elle ne sert à rien ic ici
	int a=0;
	int b=0;	
	int taille=0; // voir si on n'importe pas cette variable qui sera déterminer lors du remplissage de notre variables sequence
	int max_brin=0;// pointeur dessus!!
	int max_cadre=0;//pointeur dessus!!
	
		while((cadre_lecture <4)&&(brin_sens = 1)){//On procéde dans l'odre le cadre de lecture 0,+1,+2 puis on change de brin et on remodifi le cadre de lecture
	
			// mettre une condition concernant l'intitulé de la séquence de telle sorte qu'on met en place une boucle qui va tourner tant qu'on est dans l'intitulé 
	
			if(cadre_lecture>4){
				cadre_lecture = 0;
				brin_sens = 1;
			}
			if (brin_sens = 0);{
				if(debut =0;){// si on est au debut on prend comme i initial = au cadre de lecture 
				i=cadre_lecture;
				debut=1;
				}
				a=i+1;
				b=i+2;
				
				if (((sequence[i]="A") && (sequence[a]="T") && (sequence[b])) && (atg=0)){ // si on trouve notre codon start
					j=3;
					atg=1;// supprimé ?
					while (((sequence[i]!="T") && (sequence[i+1]!="A") && (sequence[i+2]!="A")) ||
	      	 			((sequence[i]!="T") && (sequence[i+1]!="A") && (sequence[i+2]!="G")) || 
					((sequence[i]!="T") && (sequence[i+1]!="G") && (sequence[i+2]!="A"))){ // on cherche le codon stop après avoir trouvé un codon start
	
					cds[i] = sequence[i];
					cds[i+1] = sequence[i+1];
					cds[i+2] = sequence[i+2];

					i= i+3;
					j= j+3;
					atg=0; // peut - être supprimé???
			}
			else{	
				if(debut =0;){// si on est au debut on prend comme i initial = au cadre de lecture 
				i=taille - cadre_lecture;
				debut=1;
				}
				a=i-1;
				b=i-2;
			}
			if (((sequence[i]="A") && (sequence[a]="T") && (sequence[b])) && (atg=0)){ // si on trouve notre codon start
				j=3;
				atg=1;// supprimé ?
				while (((sequence[i]!="T") && (sequence[i+1]!="A") && (sequence[i+2]!="A")) ||
	      	 		((sequence[i]!="T") && (sequence[i+1]!="A") && (sequence[i+2]!="G")) || 
				((sequence[i]!="T") && (sequence[i+1]!="G") && (sequence[i+2]!="A"))){ // on cherche le codon stop après avoir trouvé un codon start
	
					cds[i] = sequence[i];
					cds[i+1] = sequence[i+1];
					cds[i+2] = sequence[i+2];

					i= i+3;
					j= j+3;
					atg=0; // peut - être supprimé???

				}
				if (max<j){ // si on a une cds de taille plus importante
					max = j;
					max_brin = brin_sens; // pointeur sur max_brin
					max_cadre = cadre_lecture; // pointeur sur max_brin
					max_cds = cds; // j'enregistre dans ma variable final la séquence que j'ai calculé
				}
			}
			if (sequence[i] = ""){ // dans le cas ou on est 
				cadre_lecture = cadre_lecture + 1;
				debut=0;
				taile = i-1;// voir si on ne l'importe pas de la taille de notre sequence
			}
			i=i+3;
		}
		if(max!=0){
			printf("cadre lectrue : %d\nbrin_sens:%d\t(0 si sens et 1 si anti-sens)\nCDS:\n%s",max_cadre,max_brin,max_cds);
		}
		else{
			print("Aucune CDS trouvé\n");
		}
}
			









