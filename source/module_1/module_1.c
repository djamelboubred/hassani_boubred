#include "module_1.h"
int recherche_max_cds(char sequence[], int* position, int cadre){
	/*prend une séquence , une position intermédiaire, ainsi que le cadre de lecture pris en compte lors de la lecture de la séquence
	Cette fonction va sruter la sequence en prenant en compte le cadre de lecture, et chercher le début de la cds en cherchant un atg, puis elle va chercher
	un codon stop, en auglmentant à chaque fois j de trois qui est le nombre de nt (3 car on cherche des codons à chaque fois)
	-	dans le cas ou elle en trouve(codon stop): le j est concervé et va être comparer au max de nt dans un cds précedement trouvé (si on est dans le cas de la première max vaut 0)
	-	dans le cas ou il ne trouve pas(codon stop): le j n'est pas pris en compte on le réinitialise et on continue a scruté la séquence.
	*/
	int j=0; // compteur du nombre de nt
	int k = 0; // position initial du premier nt de la cds
	int maximum =0;   // le nombre le plus important de nt dans une cds
	int taille = strlen(sequence);
	int fin = FALSE;
	int i = cadre;
	int seq_complet = TRUE;
	while((j==0)||(i<taille-2)){
        	if ((sequence[i]=='A') && (sequence[i+1]=='T') && (sequence[i+2]=='G')){ // si on trouve notre codon start
			j=3;
                        k=i;    // on prend la position du codon start
                        while((i<taille-2)||(fin!=TRUE)){
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
                                if(sequence[i]=='\0'){
                                	fin=TRUE;
                                        seq_complet = FALSE;
                                        break;
                                }
                                if(sequence[i+1]=='\0'){
                                	fin=TRUE;
                                        seq_complet = FALSE; //FALSE car la séquence n'est pas complete donc on ne la prend pas en compte
                                        break;
                                }
				if(sequence[i+2]=='\0'){
	 				fin=TRUE;
                                        seq_complet = FALSE;
                                        break;
                                }
				i= i+3;
   				j= j+3;
			}
			if(seq_complet==FALSE){ //dans le cas ou la séquence commencant par un atg ne finis pas par un codon on ne prends pas en compte cette séquence en remettant j à 0.
                        	j=0;
                                seq_complet = TRUE;
                        }
                	if(maximum<j){ // si on a une cds de taille plus importante
                 		maximum = j; // on enregistre le max
                        	*position =k; // on enregistre la position du premier nt de la séquence dans la variable posiution qui ici représente la position du 1er nt de la CDS la plus grande.
	        	}
		}
	i=i+3;
	}
	return maximum;
}


void sequence_complementaire(char sequence[], int taille, char sequence_comp[]){ //prend ue séquence et la taille de la séquence en argument
// Cette fonction prend une séquence, une taille principalement utilisé pour lire la séquence de droite à gauche , et une sequence qu'on va remplir.
	int i; // compteur de séquence
	int j=0; //compteur de  sequence_comp

	for(i=taille;i>=0;i--){
		if(sequence[i] == '\0'){
			j--; //on prend j-1 car étant donné qu'on lit la séquence à l'envers le caractère de fin de chaîne est lu en premier.
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
// prend une séquence à analyser , une taille principalement utilisé pour l'allocation mémoire des variables ou encore lors de l'appel de  la fonction sequence_complementaire.
	char* cds  = malloc(sizeof(char)*taille);//  La cds à remplir
	char* sequence_comp = malloc(sizeof(char)*taille); //la sequence complémentaire qu'on va remplir lors de l'appel de la fonction sequence_complementaire

	int k =0; // position du premier nucléotide afin de pouvoir initier l'écriture de notre cds la plus grande lors de la fin du traitement de notre séquence

	int j = 0; //compteur nombres de nt
	int i =0; // compteur en respectant le cadre de lecture et la lecture de codon(+3) à chaque tour
	int max =0; // valeur max de la taille de la CDS
	int brin_sens = TRUE; //Valeur 0 si on est dans le cas du brin sens et 1 si brin anti-sens
	int cadre_lecture= 0; // Indique à l'utilisateur dans qu'elle cadre de lecture se trouve la  plus grande CDS

	int max_brin=TRUE;	//permet de connaître le brin pris en compte pour notre cds la plus grane
	int position = 0; //position définitif de la plus grande cds
	int cadre_max;

	sequence_complementaire(sequence,taille,sequence_comp);
	//ici on sauvegarde la séquence complémentaire afin d'avoir un témoin que la séquence fonctionne bien et pouvoir comparer lors de la correction de notre programme si la cds renvoyer est correct
	char path_output[21] = "complementaire.fasta";
	save_sequence(path_output,sequence_comp);
	if(brin_sens == TRUE){ // on travaille dans un premier lieu sur le brin sens
		j = recherche_max_cds(sequence,&k,cadre_lecture);
		if(max<j){ // ici va comparer si le max trouvé lors de l'appel de la fonction correspond au max sauvegarder ici lors de la lecture en fonction du cadre de lecture et du brin utiliser
			max=j;
			position =k;
			cadre_max =cadre_lecture;
			max_brin = brin_sens;
		}
		cadre_lecture++; //on augmente le cadre de lecture
		j = recherche_max_cds(sequence,&k,cadre_lecture);
		if(max<j){
			max=j;
			position= k;
			cadre_max = cadre_lecture;
			max_brin = brin_sens;

		}
		cadre_lecture++;
		j = recherche_max_cds(sequence,&k,cadre_lecture);
		if(max<j){
			max=j;
			position=k;
			cadre_max = cadre_lecture;
			max_brin = brin_sens;
		}
		brin_sens = FALSE;
	}
	if(brin_sens == FALSE){
		cadre_lecture = 0; //on réinitialise le cadre de lecture car il ne sert à rien d'aller au delà de cadre_lecture = 2
		j = recherche_max_cds(sequence_comp,&k,cadre_lecture);
                if(max<j){
                        max=j;
                        position=k;
                        cadre_max =cadre_lecture;
                        max_brin = brin_sens;
                }
                cadre_lecture++;
                j = recherche_max_cds(sequence_comp,&k,cadre_lecture);
                if(max<j){
                        max=j;
                        position=k;
                        cadre_max = cadre_lecture;
                        max_brin = brin_sens;
                }
                cadre_lecture++;
                j = recherche_max_cds(sequence_comp,&k,cadre_lecture);
                if(max<j){
                        max=j;
                        position=k;
                        cadre_max = cadre_lecture;
                        max_brin = brin_sens;
                }
	}

		if(max!=0){// on verifie que notre fonction fonctionne en ayant trouvé au moins une CDS
			i=0;	//on réinitialise notre compteur
			int x = position; //compteur utilisé pour le remplissage de notre cds définitif (position aurait très bien pu jouer ce rôle mais la déclaration de la variable x est plus un jeu d'ésthétique étant donner que notre code est relativement court celà me semble acceptable).
			if(max_brin == TRUE){ // on regarde dans quel brin la plus grande cds à été trouvé afin de la remplir avec la bonne séquence

				while (i<max){	// j étant le nombre de nucléotides tant que notre compteur est infrieur ou égal au nombre de nucléotide max on boucle
					if(sequence[x] == '\n'){
						cds[i] = sequence[x];
						x++;
					}
					cds[i] = sequence[x];
					x++;
					i++;

				}
				cds[i]='\0';
			}
			else{ //même principe qu'au dessus juste ici on prend la sequence complémentaire
				while (i<max){	// j étant le nombre de nucléotides tant que notre compteur est infrieur ou égal au nombre de nucléotide max on boucle
					if (sequence_comp[x] =='\n'){
						cds[i] = sequence[x];
						x++;
					}
					cds[i] = sequence_comp[x];
					i++;
					x++;
				}
				cds[i]='\0';
			}
			//affichage des information relatif à la cds
			printf("\nLa CDS se situe sur le brin: %d\t (0 si brin sens et 1 si brin complémentaire)\nEt sur le cadre de lecture: +%d\n",max_brin,cadre_max);
			printf("\nCDS:5'-%s-3'\n",cds);
			char path_output[10]="CDS.fasta";
			save_sequence(path_output,cds);
		}
		else{
			printf("Aucune CDS trouvée, ou le programme n'a pas fonctionné!!\n");
		}
}

int module_1(){
	printf("\n MODULE 1: Recherche de la séquence codante de taille maximale .\n");
	char* nom_fichier1 = malloc(sizeof(char));
	//if() a rajouter apres chaque malloc
	stocker_nom_fichier(nom_fichier1);
		FILE* fichier1 = fopen(nom_fichier1,"r");
		if(!fichier1){
			fprintf(stderr, "L'ouverture à échoué.\n");
			return EXIT_FAILURE;
		}
		else{
			printf("Le fichier:\t%s à été charger avec succès\n",nom_fichier1);
		}
		int taille_fichier1= calcul_taille_fichier(fichier1);

		char* sequence= malloc(sizeof(char)*taille_fichier1);// taille maximum qui seras réduit plus tard
		extract_sequence(fichier1, sequence);
		//printf("test bis");
		fclose(fichier1);

		recherche_sequence_codante(sequence,taille_fichier1);
		free(sequence);
		return 0;
}


int main(){
	module_1();
}
