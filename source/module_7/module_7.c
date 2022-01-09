#include "module_7.h"

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
/*Permet d'afficher une variable de type AA, plus precisement son id(=lettre acide amine)
entrée: une variable sequence de type AA
sortie: aucune*/
void afficher_sequence_proteine(AA sequence[]){
  int i=0;
  while(sequence[i].id!='\0'){//tant que la sequence n'est pas fini
    printf("%c",sequence[i].id);//On affiche lettre par lettre
    i++;
  }
  printf("\n");
}

/*Permet de remplir une variable de type AA par le contenu d'un fichier
entrée: un fichier deja ouvert  et une variable sequence de type AA
sortie: aucune*/
void extract_sequence_de_proteine(FILE* fichier, AA sequence[]){
  int i=-1;//pour avoir la bonne taille
  char lettre_lu;// variable optionnelle, juste pour rendre le code plus lisible, represente la lettre lu par la fonction fgetc
  fseek(fichier,0,SEEK_SET);//on place le curseur au tout debut du fichier
  if(fgetc(fichier)=='>'){/*On avance le curseur jusqu'au premier saut de ligne*/
    while(fgetc(fichier)!='\n'){ /*On avance le curseur jusqu'au premier saut de ligne*/
    }
  }
  else{
    fseek(fichier,0,SEEK_SET);
  }
  while((lettre_lu=fgetc(fichier))!=EOF){//tant que la lettre lu n'est pas EOF qui indique fin d'un fichier
    if(lettre_lu!='\n'){//si on ne se trouve pas a la fin d'une ligne on incremente i
      i++;
      sequence[i]=*creation_AA(lettre_lu);//on remplit pour chaque lettre lu l'id, la polarite et le code_lettre de la sequence[i] de type AA
    }
  }
}

/*Permet de retourner le nombre le plus petit entre deux nombres
entrée: deux variable de type int
sortie: la plus petite d'entre elles*/
int min(int a,int b){
  if (a<b) return a;
  return b;
}

/*Permet de trouver la plus grande sous chaine commune entre deux sequences
entrée: deux  sequences de type AA pas foecement de meme taille, taille de la sequence 1 et la taille de la sequence 2
sortie: rien*/
void plus_grande_sschaine_polarite(AA sequence1[],AA sequence2[],int taille1,int taille2){
    int i,j;//compteurs de la matrice, i pour les lignes et j colonnes
    int max = 0;//le plus grand nombre de la matrice qui correspond au nombre de caractere dans la sous chaine en commun la plus grande
    int max_i = 0;// indice du max
    AA sous_chaine[min(taille1,taille2)];//sous-chaine de taille= taille la plus petite entre les 2 sequences
    int matrice[taille1+1][taille2+1];//Matrice resultat, de taille+1 car on va laisser premiere ligne et premiere colonne remplit de 0
    for (i=0;i <= taille1; i++){ //on initialise toute la matrice a 0
        for (j=0;j <= taille2; j++){
          matrice[i][j] = 0;
        }
    }


    for(i=1; i <= taille1; i++){// on commence avec i = 1 car on laisse la premiere ligne avec des 0
        for(j=1; j <= taille2; j++){// on commence avec j = 1 car on laisse la premiere colonne avec des 0
            if(sequence1[i-1].polarite == sequence2[j-1].polarite){
                matrice[i][j] = matrice[i-1][j-1] + 1; // on applique la formule quand polarite identique
                if(max < matrice[i][j]){
                    max = matrice[i][j];// on sauvegarde le max
                    max_i = i;// on sauvegarde l'indice max
                }
            }
        }
    }
    printf("\nsequence 1: ");
    afficher_sequence_proteine(sequence1);
    printf("\nsequence 2: ");
    afficher_sequence_proteine(sequence2);

    if (max == 0){
      printf("Aucune sequence consensus\n");// si aucune polarite n'a ete trouve
    }
    else{
      /*On remplit la sous chaine en commencant par l'element a l'indice (max_i-max) qui correspond dans la sequence a la premiere lettre de la sous chaine commune, puis on avance jusqu'au max pour avoir l'integralite de la sous chaine */
      for (i=0;i<max;i++){
       sous_chaine[i] = *creation_AA(sequence1[max_i - (max - i)].id);
      }
      sous_chaine[max] = *creation_AA('\0');// si on ne remplit pas toute la place de sous_chaine on met \0 qui correspond à la fin de la chaine de caractere
      printf("\nsous-chaine commune: ");
      afficher_sequence_proteine(sous_chaine);
      printf("(");//pour affichage
      for (i=0;i<max;i++){
        printf("%s-",sous_chaine[i].code_lettre);//Pour afficher la sequence sous chaine
      }
      printf(")\n");//pour affichage
      printf("polarite: ");
      for (i=0;i<max;i++){
        printf("%d",sous_chaine[i].polarite);
      }
      printf("\n");
    }
}

/* fonction qui permet d'executer a la chaine les fonctions precedente du module 7,
elle ne prend pas d'entrée et renvoie une erreur si le ou les fichiers n'ont pas pu etre ouvert*/
int module_7(){
   printf("\n MODULE 7: Recherche de la plus grande sous-chaîne de polarité commune à 2 séquences \n");
   printf("L'ordinateur va vous demander à une seule reprise de taper le chemin menant à votre fichier contenant vos sequences\n");
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
   AA sequence1[taille1 + 1];
   AA sequence2[taille2 + 1];
   sequence1[taille1] = *creation_AA('\0');
   sequence2[taille2] = *creation_AA('\0');
   extract_sequence_de_proteine(fichier1,sequence1);
   extract_sequence_de_proteine(fichier2,sequence2);
   plus_grande_sschaine_polarite(sequence1,sequence2,taille1,taille2);
   fclose(fichier1);
   fclose(fichier2);
   return 0;
 }

 int main(){
   module_7();
 }
