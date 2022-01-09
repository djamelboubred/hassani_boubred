#include "module_5.h"

/*Permet de remplir la structure AA (id,polarite,code_lettre)
entrée: une lettre lu dans le fichier
sortie: un acide amine de type AA*/

AA* creation_AA(char lettre){
  AA* nvl_AA=malloc(sizeof(AA));
  if(nvl_AA==NULL) { // si l'allocation memoire n'a pas fonctionné renvoie une erreur
    printf("Erreur d'allocation de memoire");
    exit(1);
  }
  nvl_AA->id=lettre;// mettre lettre lu dans id du nouvel Acide amine
  //ajout polarite
  if(lettre=='A'||lettre=='F'||lettre=='L'||lettre=='I'||lettre=='M'||lettre=='W'||lettre=='P'||lettre=='V'||lettre=='G'){
    nvl_AA->polarite=1;
  }
  else{
    nvl_AA->polarite=0;
  }
  //ajout du code à 3 lettres
  if(lettre=='A'){
    nvl_AA->code_lettre[0]='A';
    nvl_AA->code_lettre[1]='l';
    nvl_AA->code_lettre[2]='a';
  }
  else if(lettre=='R'){
    nvl_AA->code_lettre[0]='A';
    nvl_AA->code_lettre[1]='r';
    nvl_AA->code_lettre[2]='g';
  }
  else if(lettre=='N'){
    nvl_AA->code_lettre[0]='A';
    nvl_AA->code_lettre[1]='s';
    nvl_AA->code_lettre[2]='n';
  }
  else if(lettre=='D'){
    nvl_AA->code_lettre[0]='A';
    nvl_AA->code_lettre[1]='s';
    nvl_AA->code_lettre[2]='p';
  }
  else if(lettre=='C'){
    nvl_AA->code_lettre[0]='C';
    nvl_AA->code_lettre[1]='y';
    nvl_AA->code_lettre[2]='s';
  }
  else if(lettre=='E'){
    nvl_AA->code_lettre[0]='G';
    nvl_AA->code_lettre[1]='l';
    nvl_AA->code_lettre[2]='u';
  }
  else if(lettre=='Q'){
    nvl_AA->code_lettre[0]='G';
    nvl_AA->code_lettre[1]='l';
    nvl_AA->code_lettre[2]='y';
  }
  else if(lettre=='G'){
    nvl_AA->code_lettre[0]='G';
    nvl_AA->code_lettre[1]='l';
    nvl_AA->code_lettre[2]='y';
  }
  else if(lettre=='H'){
    nvl_AA->code_lettre[0]='H';
    nvl_AA->code_lettre[1]='y';
    nvl_AA->code_lettre[2]='s';
  }
  else if(lettre=='I'){
    nvl_AA->code_lettre[0]='I';
    nvl_AA->code_lettre[1]='l';
    nvl_AA->code_lettre[2]='e';
  }
  else if(lettre=='L'){
    nvl_AA->code_lettre[0]='L';
    nvl_AA->code_lettre[1]='e';
    nvl_AA->code_lettre[2]='u';
  }
  else if(lettre=='K'){
    nvl_AA->code_lettre[0]='L';
    nvl_AA->code_lettre[1]='y';
    nvl_AA->code_lettre[2]='s';
  }
  else if(lettre=='M'){
    nvl_AA->code_lettre[0]='M';
    nvl_AA->code_lettre[1]='e';
    nvl_AA->code_lettre[2]='t';
  }
  else  if(lettre=='F'){
    nvl_AA->code_lettre[0]='P';
    nvl_AA->code_lettre[1]='h';
    nvl_AA->code_lettre[2]='e';
  }
  if(lettre=='P'){
    nvl_AA->code_lettre[0]='P';
    nvl_AA->code_lettre[1]='r';
    nvl_AA->code_lettre[2]='o';
  }
  else if(lettre=='S'){
    nvl_AA->code_lettre[0]='S';
    nvl_AA->code_lettre[1]='e';
    nvl_AA->code_lettre[2]='r';
  }
  else if(lettre=='T'){
    nvl_AA->code_lettre[0]='T';
    nvl_AA->code_lettre[1]='h';
    nvl_AA->code_lettre[2]='r';
  }
  else if(lettre=='W'){
    nvl_AA->code_lettre[0]='T';
    nvl_AA->code_lettre[1]='r';
    nvl_AA->code_lettre[2]='p';
  }
  else if(lettre=='Y'){
    nvl_AA->code_lettre[0]='T';
    nvl_AA->code_lettre[1]='y';
    nvl_AA->code_lettre[2]='r';
  }
  if(lettre=='V'){
    nvl_AA->code_lettre[0]='V';
    nvl_AA->code_lettre[1]='a';
    nvl_AA->code_lettre[2]='l';
  }
  return nvl_AA;
}

/*Permet de calculer la taille d'une variable de type AA
entrée: une variable sequence de type AA
sortie: taille de la sequence proteique*/
int calcul_taille_proteine(AA sequence[]){
  int i=0;//compteur
  while(sequence[i].id!='\0'){
    i++; //Tant que la sequence n'est pas fini
  }
  return i;//Le dernier i sera la taille de la séquence
}

/*Permet de remplir une variable de type AA par le contenu d'un fichier
entrée: un fichier deja ouvert  et une variable sequence de type AA
sortie: aucune*/
void extract_sequence_de_proteine(FILE* fichier, AA sequence[]){
  int i=-1;//pour avoir la bonne taille
  char lettre_lu;// variable optionnelle, juste pour rendre le code plus lisible, represente la lettre lu par la fonction fgetc
  fseek(fichier,0,SEEK_SET);//on place le curseur au tout debut du fichier
  if(fgetc(fichier)=='>'){//on saute la premiere ligne si elle commence par >
    while(fgetc(fichier)!='\n'){
      /*On avance le curseur jusqu'au premier saut de ligne*/
    }
  }
  else{
    fseek(fichier,0,SEEK_SET);
  }
  while((lettre_lu=fgetc(fichier))!=EOF){//tant que la lettre lu n'est pas EOF qui indique fin d'un fichier
    if(lettre_lu!='\n'){//si on ne se trouve pas a la fin d'une ligne on incremente i
      i++;
      sequence[i]=*creation_AA(lettre_lu);//on remplit pour chaque lettre lu l'id, la polarite et le code_lettre de la sequence[i] de type proteine
    }
  }
}

/*Permet d'afficher une variable de type AA, plus precisement son id(=lettre acide amine)
entrée: une variable sequence de type AA
sortie: aucune*/
void afficher_sequence_proteine(AA sequence[]){
  int i=0;//compteur
  while(sequence[i].id!='\0'){//tant que la sequence n'est pas fini
    printf("%c",sequence[i].id);//On affiche lettre par lettre
    i++;//on incremente pour passer a la lettre suivante
  }
  printf("\n");
}

/*Permet de calculer un score d'identite de polarite entre 2 sequences proteiques
entrée: 2 variables sequences de type AA a comparer
sortie: aucune*/
void Calcul_polarite(AA sequence1[],AA sequence2[]){
  int i=0;//compteur séquence 1 et 2
  int polarite_identique=0;//nombre d'endroit ou la polarite des acide amine est identique entre les 2 sequences
  int taille = calcul_taille_proteine(sequence1);
  char score_identite[taille];//sequence final qui represente le score d'identite de polarite
  score_identite[taille]='\0';//on initialise
  while(sequence1[i].id!='\0'){ //Tant que la sequence 1 n'est pas fini, puisque sequence 2 meme taille pas besoin de l'ajouter à la condition
     if(sequence1[i].polarite==sequence2[i].polarite && sequence1[i].id!='-' && sequence2[i].id!='-'){//pour eviter de compter un nbr identique si on compare 2 Gap
       polarite_identique++;//on incremente pour chaque nombre de polarite que l'on trouve identique
       if(sequence1[i].polarite==0) score_identite[i]='0';//on remplit la sequence final de score d'identite selon si polarite identique ou pas
       else score_identite[i]='1';//polarités egales
     }
     else score_identite[i]='-';// pas egales
     i++; //on incremente de 1 le compteur pour passer a l'element suivant
  }
   printf("0:hydrophiles , 1:hydrophobes , -:différents\n");
   afficher_sequence_proteine(sequence1);
   afficher_sequence_proteine(sequence2);
   printf("%s\n",score_identite);
   printf("Polarite identique:%d\n",polarite_identique);
}

/* fonction qui permet d'executer a la chaine les fonctions precedente du module 5,
elle ne prend pas d'entrée et renvoie une erreur si le ou les fichiers n'ont pas pu etre ouvert*/
int module_5(){
  printf("\n MODULE 5: Calcul du score de similarité de polarité entre deux séquences protéiques \n");
  printf("L'ordinateur va vous demander à deux reprises de taper les 2 chemins menant à vos fichiers contenant vos sequences\n");
  char* nom_fichier1=malloc(sizeof(char));
  char* nom_fichier2=malloc(sizeof(char));
  stocker_nom_fichier(nom_fichier1);
  stocker_nom_fichier(nom_fichier2);

  FILE* fichier1=fopen(nom_fichier1,"r");
  FILE* fichier2=fopen(nom_fichier2,"r");
  if (!fichier1 || !fichier2){
			fprintf(stderr, "L'ouverture a échoué");
			return EXIT_FAILURE;
	}
  int taille1= calcul_taille_fichier(fichier1);
  int taille2= calcul_taille_fichier(fichier2);
  if(taille1!=taille2){
    printf("Attention : Comparaison de séquences de tailles differentes\n");
  }

  AA sequence1[taille1 + 1];
  AA sequence2[taille2 + 1];
  sequence1[taille1] = *creation_AA('\0');
  sequence2[taille2] = *creation_AA('\0');
  extract_sequence_de_proteine(fichier1,sequence1);
  extract_sequence_de_proteine(fichier2,sequence2);
  Calcul_polarite(sequence1,sequence2);
  fclose(fichier1);
  fclose(fichier2);
  return 0;
}

int main(){
  module_5();
}
