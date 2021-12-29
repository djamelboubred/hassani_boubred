#include <stdlib.h>
#include <stdio.h>

typedef struct proteine
{
  char id;
  int polarite;
}proteine;

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


int calcul_taille_fichier(FILE* fichier)
{
  int i=0;
  char lettre_lu;
  if(fgetc(fichier)=='>')
  {
    while(fgetc(fichier)!='\n')
    {

    }
  }
  else
  {
    fseek(fichier,0,SEEK_SET);
  }

  while((lettre_lu=fgetc(fichier))!=EOF)
  {
  if(lettre_lu!='\n') i++;
  }
  return i;/*  */
  fseek(fichier,0,SEEK_SET);
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

int main(){

  FILE* fichier1=fopen("fichier1.txt","r");
  FILE* fichier2=fopen("fichier2.txt","r");
  if (!fichier1 || !fichier2)
  {
			fprintf(stderr, "L'ouverture a échoué");
			return EXIT_FAILURE;
	}

  int taille1= calcul_taille_fichier(fichier1);
  int taille2= calcul_taille_fichier(fichier2);
  if(taille1!=taille2)
  {
    printf("Erreur : Comparaison de séquences de tailles differentes\n");
    exit(1);
  }

  proteine sequence1[taille1];
  proteine sequence2[taille2];
  extract_sequence_de_proteine(fichier1,sequence1);
  extract_sequence_de_proteine(fichier2,sequence2);
  Calcul_polarite(sequence1,sequence2);
}
