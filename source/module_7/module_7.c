#include "module_7.h"

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
  if(lettre=='A'){
    nvl_proteine->code_lettre[0]='A';
    nvl_proteine->code_lettre[1]='l';
    nvl_proteine->code_lettre[2]='a';
  }
  else if(lettre=='R'){
    nvl_proteine->code_lettre[0]='A';
    nvl_proteine->code_lettre[1]='r';
    nvl_proteine->code_lettre[2]='g';
  }
  else if(lettre=='N'){
    nvl_proteine->code_lettre[0]='A';
    nvl_proteine->code_lettre[1]='s';
    nvl_proteine->code_lettre[2]='n';
  }
  else if(lettre=='D'){
    nvl_proteine->code_lettre[0]='A';
    nvl_proteine->code_lettre[1]='s';
    nvl_proteine->code_lettre[2]='p';
  }
  else if(lettre=='C'){
    nvl_proteine->code_lettre[0]='C';
    nvl_proteine->code_lettre[1]='y';
    nvl_proteine->code_lettre[2]='s';
  }
  else if(lettre=='E'){
    nvl_proteine->code_lettre[0]='G';
    nvl_proteine->code_lettre[1]='l';
    nvl_proteine->code_lettre[2]='u';
  }
  else if(lettre=='Q'){
    nvl_proteine->code_lettre[0]='G';
    nvl_proteine->code_lettre[1]='l';
    nvl_proteine->code_lettre[2]='y';
  }
  else if(lettre=='G'){
    nvl_proteine->code_lettre[0]='G';
    nvl_proteine->code_lettre[1]='l';
    nvl_proteine->code_lettre[2]='y';
  }
  else if(lettre=='H'){
    nvl_proteine->code_lettre[0]='H';
    nvl_proteine->code_lettre[1]='y';
    nvl_proteine->code_lettre[2]='s';
  }
  else if(lettre=='I'){
    nvl_proteine->code_lettre[0]='I';
    nvl_proteine->code_lettre[1]='l';
    nvl_proteine->code_lettre[2]='e';
  }
  else if(lettre=='L'){
    nvl_proteine->code_lettre[0]='L';
    nvl_proteine->code_lettre[1]='e';
    nvl_proteine->code_lettre[2]='u';
  }
  else if(lettre=='K'){
    nvl_proteine->code_lettre[0]='L';
    nvl_proteine->code_lettre[1]='y';
    nvl_proteine->code_lettre[2]='s';
  }
  else if(lettre=='M'){
    nvl_proteine->code_lettre[0]='M';
    nvl_proteine->code_lettre[1]='e';
    nvl_proteine->code_lettre[2]='t';
  }
  else  if(lettre=='F'){
    nvl_proteine->code_lettre[0]='P';
    nvl_proteine->code_lettre[1]='h';
    nvl_proteine->code_lettre[2]='e';
  }
  if(lettre=='P'){
    nvl_proteine->code_lettre[0]='P';
    nvl_proteine->code_lettre[1]='r';
    nvl_proteine->code_lettre[2]='o';
  }
  else if(lettre=='S'){
    nvl_proteine->code_lettre[0]='S';
    nvl_proteine->code_lettre[1]='e';
    nvl_proteine->code_lettre[2]='r';
  }
  else if(lettre=='T'){
    nvl_proteine->code_lettre[0]='T';
    nvl_proteine->code_lettre[1]='h';
    nvl_proteine->code_lettre[2]='r';
  }
  else if(lettre=='W'){
    nvl_proteine->code_lettre[0]='T';
    nvl_proteine->code_lettre[1]='r';
    nvl_proteine->code_lettre[2]='p';
  }
  else if(lettre=='Y'){
    nvl_proteine->code_lettre[0]='T';
    nvl_proteine->code_lettre[1]='y';
    nvl_proteine->code_lettre[2]='r';
  }
  if(lettre=='V'){
    nvl_proteine->code_lettre[0]='V';
    nvl_proteine->code_lettre[1]='a';
    nvl_proteine->code_lettre[2]='l';
  }
  return nvl_proteine;
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
}


void afficher_matrice(int matrice[4][4],int ligne,int colonne){
  int i,j;
  for (i = 0; i < ligne; i++)
    {
      for (j = 0; j < colonne; j++) printf("%d  ", matrice[i][j]);
        printf("\n");
    }
}

int min(int a,int b){
  if (a<b) return a;
  return b;
}

void plus_grande_sschaine_polarite(proteine sequence1[],proteine sequence2[],int taille1,int taille2){
    int i,j;
    int max_i = 0;
    int max = 0;
    proteine sous_chaine[min(taille1,taille2)];
    int matrice[taille1+1][taille2+1];//Matrice resultat
    for (i=0;i <= taille1; i++) //on initialise la matrice a 0
    {
        for (j=0;j <= taille2; j++) matrice[i][j] = 0;
    }


    for(i=1; i <= taille1; i++){//on saute la premiere ligne car on commence avec i = 1
        for(j=1; j <= taille2; j++){// de meme
            if(sequence1[i-1].polarite == sequence2[j-1].polarite){
                matrice[i][j] = matrice[i-1][j-1] + 1;
                if(max < matrice[i][j]){
                    max = matrice[i][j];
                    max_i = i;

                }
            }
        }
    }
    afficher_sequence_proteine(sequence1);
    afficher_sequence_proteine(sequence2);

    if (max == 0) printf("Aucune sequence consensus\n");

    else
    {
      for (i=0;i<max;i++) sous_chaine[i] = *creation_proteine(sequence1[max_i - (max - i)].id);
      sous_chaine[max] = *creation_proteine('\0');// si on ne remplie pas toute la place de sous_chaine on met \0 qui correspond à la fin de la chaine de caractere

      afficher_sequence_proteine(sous_chaine);

      for (i=0;i<max;i++) printf("%d",sous_chaine[i].polarite);
      printf("\n");
      for (i=0;i<max;i++) printf("%s-",sous_chaine[i].code_lettre);
      printf("\n");
    }

}

int module_7()
{
   printf("\n MODULE 7: Recherche de la plus grande sous-chaîne de polarité commune à 2 séquences \n");
   printf("L'ordinateur va vous demander à une seule reprise de taper le chemin menant à votre fichier contenant vos sequences\n");
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
   proteine sequence1[taille1 + 1];
   proteine sequence2[taille2 + 1];
   sequence1[taille1] = *creation_proteine('\0');
   sequence2[taille2] = *creation_proteine('\0');
   extract_sequence_de_proteine(fichier1,sequence1);

   extract_sequence_de_proteine(fichier2,sequence2);

   plus_grande_sschaine_polarite(sequence1,sequence2,taille1,taille2);


   fclose(fichier1);
   fclose(fichier2);
   //afficher_matrice(matrice,2,2);
   return 0;
 }

 int main()
 {
   module_7();
 }
