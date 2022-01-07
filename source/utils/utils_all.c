#include"utils.h"
//MODULE 1
int recherche_max_cds(char sequence[], int* position, int cadre){
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
			if(seq_complet==FALSE){
                        	j=0;
                                seq_complet = TRUE;
                        }
                	if(maximum<j){ // si on a une cds de taille plus importante
                 		maximum = j;
                        	*position =k;
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

	char* cds  = malloc(sizeof(char)*taille);//  La cds à remplir
	char* sequence_comp = malloc(sizeof(char)*taille);

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
	char path_output[21] = "complementaire.fasta";
	save_sequence(path_output,sequence_comp);
	if(brin_sens == TRUE){
		j = recherche_max_cds(sequence,&k,cadre_lecture);
		if(max<j){
			max=j;
			position =k;
			cadre_max =cadre_lecture;
			max_brin = brin_sens;
		}
		cadre_lecture++;
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
		cadre_lecture = 0; //on réinitialise le cadre de lecture
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
			int x = position;
			if(max_brin == TRUE){

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
			else{
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
		char* nom_fichier1= malloc(sizeof(char));
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
		return 0;
}

//MODULE 2
void transcription(char* sequence,int taille){
	char path_output[18]="sequenceARN.fasta";
	int i=0;
	int j=0;

	char* sequence_ARN = malloc(sizeof(sequence_ARN)*taille);
	while(j<taille){
		if(sequence[i]=='T'){		//procéde à la transcription
			sequence_ARN[j]='U';
		}
		else{		//sinon reprend juste le nucléotide de la séquence
			sequence_ARN[j]=sequence[i];
		}
		j++;
		i++;
	}
	sequence_ARN[j]='\0';
	printf("\ntranscription effectué:\n=>\nsequence:5'-%s-3'\n",sequence_ARN);
	save_sequence(path_output,sequence_ARN);
}

int module_2(){
	printf("\n MODULE 2: Transcription d’une séquence ADN en séquence ARN \n");
	char* nom_fichier2 = malloc(sizeof(char));
	stocker_nom_fichier(nom_fichier2);
	FILE* fichier2 = fopen(nom_fichier2,"r");
	if(!fichier2){
		fprintf(stderr, "L'ouverture à échoué.\n");
		return EXIT_FAILURE;
	}
	else{
		printf("Le fichier:\t%s à été charger avec succès\n",nom_fichier2);
	}
	int taille_fichier2 = calcul_taille_fichier(fichier2);

	char* cds = malloc(sizeof(char)*taille_fichier2);
	extract_sequence(fichier2,cds);
	transcription(cds,taille_fichier2);
	return 0;
}

//MODULE 3
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
	return 0;
}

//MODULE 4
int calcul_taille(char sequence[])
{
  int i=0;
  while(sequence[i]!='\0') i++; /*Le dernier i sera la taille de la séquence*/
  return i;
}

/*Fonction principale, pour calculer le score d'identite*/
 void Calcul_element_identique(char sequence1[],char sequence2[])
 {
   int i=0;/*compteur séquence 1*/
   float nb_identique=0;
   int taille = calcul_taille(sequence1);
   float score_identite;
   char id[taille];
   id[taille]='\0';

   while(sequence1[i]!='\0')/* sequence1 et sequenc2 sont de taille identique*/
   {
      if(sequence1[i]==sequence2[i] && sequence1[i]!='-')/*pour eviter de compter un nbr identique si on compare 2 Gap*/
      {
        nb_identique++;
        id[i]=sequence1[i];/*on remplit tableau alignement avec nucleotide de sequence 1, on aurait pu prendre seuqence 2 c'est le meme nucleotide*/
      }
      else
      {
        id[i]='-';/*sinon on remplit le tableau alignement avec un tiret*/
      }
      i++; /*on incremente de 1 chaque compteur pour passer a la case suivante du tableau*/
   }

   score_identite=(nb_identique/taille)*100;
   printf("Identité de séquence : %.0f/%d, soit %.1f %% \n",nb_identique,taille,score_identite);
   printf("seq1 %s\n",sequence1);
   printf("seq2 %s\n",sequence2);
   printf("-id- %s\n",id);
 }


int module_4(){
  printf("\n MODULE 4: Calcul de score d'identite entre deux sequences.\n");
  printf("L'ordinateur va vous demander à deux reprises de taper les 2 chemins menant à vos fichiers contenant vos sequences\n");
  char* nom_fichier1=malloc(sizeof(char));
  char* nom_fichier2=malloc(sizeof(char));
  stocker_nom_fichier(nom_fichier1);
  stocker_nom_fichier(nom_fichier2);

  FILE* fichier1=fopen(nom_fichier1,"r");
  FILE* fichier2=fopen(nom_fichier2,"r");
  if (!fichier1 || !fichier2)
  {
			fprintf(stderr, "L'ouverture a échoué");
			return EXIT_FAILURE;
	}

  int taille1= calcul_taille_fichier(fichier1);
  int taille2= calcul_taille_fichier(fichier2);
  if(taille1!=taille2)
  {
    printf("Attention : Comparaison de séquences de tailles differentes\n");
  }
  char* sequence1= malloc(sizeof(char)*taille1);
  char* sequence2= malloc(sizeof(char)*taille2);

  extract_sequence(fichier1,sequence1);

  extract_sequence(fichier2,sequence2);

  Calcul_element_identique(sequence1,sequence2);
  fclose(fichier1);
  fclose(fichier2);
  return 0;
}

//MODULE 5
proteine* creation_proteine(char lettre)
{
  proteine* nvl_proteine=malloc(sizeof(proteine));
  if(nvl_proteine==NULL)
  {
    printf("Erreur d'allocation de memoire");
    exit(1);
  }
  nvl_proteine->id=lettre;
  if(lettre=='A'||lettre=='F'||lettre=='L'||lettre=='I'||lettre=='M'||lettre=='W'||lettre=='P'||lettre=='V'||lettre=='G')
  {
    nvl_proteine->polarite=1;
  }
  else
  {
    nvl_proteine->polarite=0;
  }
  return nvl_proteine;
}


int calcul_taille_proteine(proteine sequence[])
{
  int i=0;
  while(sequence[i].id!='\0') i++; /*Le dernier i sera la taille de la séquence*/
  return i;
}

void extract_sequence_de_proteine(FILE* fichier, proteine sequence[])
{
  int i=-1;
  char lettre_lu;
  fseek(fichier,0,SEEK_SET);
  if(fgetc(fichier)=='>')
  {
    while(fgetc(fichier)!='\n') /*On avance le curseur jusqu'au premier saut de ligne*/
    {

    }
  }
  else
  {
    fseek(fichier,0,SEEK_SET);
  }
  while((lettre_lu=fgetc(fichier))!=EOF)
  {
    if(lettre_lu!='\n')
    {
      i++;
      sequence[i]=*creation_proteine(lettre_lu);
    }
  }
  sequence[i+1]=*creation_proteine('\0');
}

void afficher_sequence_proteine(proteine sequence[])
{
  int i=0;
  while(sequence[i].id!='\0')
  {
    printf("%c",sequence[i].id);/*Le dernier i sera la taille de la séquence*/
    i++;
  }
  printf("\n");
}

void Calcul_polarite(proteine sequence1[],proteine sequence2[])
{
  int i=0;/*compteur séquence 1*/
  int polarite_identique=0;
  int taille = calcul_taille_proteine(sequence1);
  char score_identite[taille];
  score_identite[taille]='\0';
  while(sequence1[i].id!='\0')/* sequence1 et sequence2 sont de taille identique*/
  {
     if(sequence1[i].polarite==sequence2[i].polarite && sequence1[i].id!='-' && sequence2[i].id!='-')/*pour eviter de compter un nbr identique si on compare 2 Gap*/
     {
       polarite_identique++;
       if(sequence1[i].polarite==0) score_identite[i]='0';
       else score_identite[i]='1';
     }
     else score_identite[i]='-';/*sinon on remplit le tableau alignement avec un tiret*/
     i++; /*on incremente de 1 chaque compteur pour passer a la case suivante du tableau*/
  }
   printf("0:hydrophiles , 1:hydrophobes , -:différents\n");
   afficher_sequence_proteine(sequence1);
   afficher_sequence_proteine(sequence2);
   printf("%s\n",score_identite);
   printf("Polarite identique:%d\n",polarite_identique);
}


int module_5(){

  printf("\n MODULE 5: Calcul du score de similarité de polarité entre deux séquences protéiques \n");
  printf("L'ordinateur va vous demander à deux reprises de taper les 2 chemins menant à vos fichiers contenant vos sequences\n");
  char* nom_fichier1=malloc(sizeof(char));
  char* nom_fichier2=malloc(sizeof(char));
  stocker_nom_fichier(nom_fichier1);
  stocker_nom_fichier(nom_fichier2);

  FILE* fichier1=fopen(nom_fichier1,"r");
  FILE* fichier2=fopen(nom_fichier2,"r");
  if (!fichier1 || !fichier2)
  {
			fprintf(stderr, "L'ouverture a échoué");
			return EXIT_FAILURE;
	}

  int taille1= calcul_taille_fichier(fichier1);
  int taille2= calcul_taille_fichier(fichier2);
  printf("%d   %d \n",taille1,taille2);
  if(taille1!=taille2)
  {
    printf("Attention : Comparaison de séquences de tailles differentes\n");
  }

  proteine sequence1[taille1];
  proteine sequence2[taille2];
  extract_sequence_de_proteine(fichier1,sequence1);
  extract_sequence_de_proteine(fichier2,sequence2);
  Calcul_polarite(sequence1,sequence2);
  fclose(fichier1);
  fclose(fichier2);
  return 0;
}

//MODULE 6
bool verification_sequence_ADN(FILE* fichier)
{
  bool isvalid=false;
  char lettre_lu;

  fseek(fichier,0,SEEK_SET);
  while((lettre_lu=fgetc(fichier))!=EOF)
  {
    if(lettre_lu=='A'||lettre_lu=='T'||lettre_lu=='C'||lettre_lu=='G'||lettre_lu=='-'||lettre_lu=='\n')
      {
        isvalid=true;
      }
  }
  if(isvalid==false)
  {
    printf("Erreur, votre fichier ne contient pas uniquement des sequences ADN\n");
  }
  return isvalid;
}

/*permet de verifier que toutes les séquences present dans le fichier ont la meme taille*/
bool sequences_memes_tailles(FILE* fichier)
{
  bool isvalid=true;
  int taille_premiere_ligne=0;
  int taille_sequence_tmp;
  // Calcul de la taille de la premiere ligne
  fseek(fichier,0,SEEK_SET);
  while(fgetc(fichier)!='\n')
  {
    taille_premiere_ligne++;
  }

  while(fgetc(fichier)!=EOF)
  {
    taille_sequence_tmp=1;// pour avoir la bonne taille puisque le curseur est avancé de 1 deja
    while(fgetc(fichier)!='\n')
    {
      taille_sequence_tmp++;
    }
    if (taille_sequence_tmp!=taille_premiere_ligne)
    {
      isvalid=false;
    }
  }
  if(isvalid==false)
  {
  printf("Erreur,les sequences ne sont pas de meme tailles\n");
  }
  return isvalid;
}

int calcul_taille_sequence(FILE* fichier)
{
  int taille_sequence=0;

  fseek(fichier,0,SEEK_SET);
  while(fgetc(fichier)!='\n')
  {
    taille_sequence++;
  }
  return taille_sequence;
}

//permet de stocker les sequences alignées presentes dans un fichier dans une variable tableau
void extract_tableau_sequence(FILE* fichier, char sequence[])
{
  int i=0;
  char lettre_lu;

  fseek(fichier,0,SEEK_SET);
  while((lettre_lu=fgetc(fichier))!=EOF)
  {
    sequence[i]=lettre_lu;
    i++;
  }
}

// fonction principale du module: permet de calculer le score identite pour chaque nucleotide de chaque sequence et affiche la sequence consensus
 char afficher_sequence_consensus(char tableau_sequence[],int taille,int nb_sequence)
{
  int nb_A=0, nb_T=0, nb_C=0, nb_G=0, nb_gap=0;
  int i; //indice colonne
  int k=0;//indice ligne
  float nb_element_maj=0;//nbr AA majoritaire par colonne
  float score_identite=0;
  char sequence_consensus[taille];
  sequence_consensus[taille]='\0';
  taille ++; // On prend en compte le retour à la ligne pour ne pas avoir de decalage(=\n)
  while(k!=taille) // boucle qui permet d'avancer au sein de chaque ligne de k element
  {
    for(i=0;i<nb_sequence;i++) // boucle qui traite chaque element du tableau par colonne
    {
      if(tableau_sequence[i*taille+k]=='A') nb_A++;
      if(tableau_sequence[i*taille+k]=='T') nb_T++;
      if(tableau_sequence[i*taille+k]=='C') nb_C++;
      if(tableau_sequence[i*taille+k]=='G') nb_G++;
      if(tableau_sequence[i*taille+k]=='-') nb_gap++;
    }

    //On prend le nombre de l'element majoritaire pour chaque colonne
    if(nb_A>=nb_T && nb_A>=nb_C && nb_A>=nb_G && nb_A>=nb_gap) nb_element_maj=nb_A;
    if(nb_T>=nb_A && nb_T>=nb_C && nb_T>=nb_G && nb_T>=nb_gap) nb_element_maj=nb_T;
    if(nb_C>=nb_T && nb_C>=nb_A && nb_C>=nb_G && nb_C>=nb_gap) nb_element_maj=nb_C;
    if(nb_G>=nb_T && nb_G>=nb_C && nb_G>=nb_A && nb_G>=nb_gap) nb_element_maj=nb_G;
    if(nb_gap>=nb_T && nb_gap>=nb_C && nb_gap>=nb_G && nb_gap>=nb_A) nb_element_maj=nb_gap;

    score_identite=(nb_element_maj/nb_sequence)*100;
    //critere d'affichage pour la sequence consensus
    if(score_identite<60) sequence_consensus[k]=' ';
    if(score_identite>=60) sequence_consensus[k]='-';
    if(score_identite>=80) sequence_consensus[k]='*';
    if(score_identite==100) sequence_consensus[k]=tableau_sequence[k];

    k++;//on incremente k pour passer a la colonne suivante(=nucleotide suivant)
    nb_A=0; nb_T=0; nb_C=0; nb_G=0; nb_gap=0; score_identite=0;//
  }
  printf("%s\n",sequence_consensus);
  return 0;
}

//permet de calculer nombre de ligne dans un fichier =nbr de sequence
int calcul_nb_sequences(FILE* fichier)
{
  int nb_sequence=0;
  char lettre_lu;
  fseek(fichier,0,SEEK_SET);
  while((lettre_lu=fgetc(fichier))!=EOF)
  {
    if(lettre_lu=='\n') nb_sequence++;
  }
  return nb_sequence;
}

int module_6()
{
  printf("\n MODULE 6: Recherche d’une séquence consensus à partir d’un alignement multiple \n");
  printf("L'ordinateur va vous demander à une seule reprise de taper le chemin menant à votre fichier contenant vos sequences\n");
  char* nom_fichier=malloc(sizeof(char));
  stocker_nom_fichier(nom_fichier);
  int taille_sequence=0;//taille de chaque sequence (taille d'une ligne dans un fichier)
  int nb_sequence=0;//nombre de ligne dans un fichier
  FILE* fichier=fopen(nom_fichier,"r");
  if (!fichier)
  {
      fprintf(stderr, "L'ouverture a échoué");
      return EXIT_FAILURE;
  }
  int taille_tableau_sequence=calcul_taille_fichier(fichier);//on calcule la taille total du fichier pour creer ensuite un tableau de cette taille
  char tableau_sequence[taille_tableau_sequence];// tableau_sequences comportera toutes les sequences presents dans le fichier donné par l'utilisateur

  verification_sequence_ADN(fichier);//on verifie que le fichier contient sequence ADN seulement
  calcul_nb_sequences(fichier);// on verifie que toutes les sequences ont la meme taille
  taille_sequence=calcul_taille_sequence(fichier);
  nb_sequence=calcul_nb_sequences(fichier);
  extract_tableau_sequence(fichier,tableau_sequence);

  afficher_sequence_consensus(tableau_sequence,taille_sequence,nb_sequence);
  return 0;
}
