#include <stdio.h>
#include <stdlib.h>

/*Pour calculer la taille de la sequence present dans un fichier*/
int calcul_taille_fichier(FILE* fichier)
{
  int i=0;
  char lettre_lu;
  while(fgetc(fichier)!='\n')
  {

  }


  while((lettre_lu=fgetc(fichier))!=EOF)
  {
  if(lettre_lu!='\n') i++;
  }
  return i;/*  */
  fseek(fichier,0,SEEK_SET);
}

/*Pour extraire une sequence d'un fichier en la placant dans une variable sequence*/
void extract_sequence(FILE* fichier, char sequence[])
{
  int i=-1;
  char lettre_lu;
  fseek(fichier,0,SEEK_SET);
  while(fgetc(fichier)!='\n') /*On avance le curseur jusqu'au premier saut de ligne*/
  {

  }

  while((lettre_lu=fgetc(fichier))!=EOF)
  {
    if(lettre_lu!='\n')
    {
      i++;
      sequence[i]=lettre_lu;
    }
  }
}

/*Pour calculer la taille d'une sequence ( pas dans un fichier mais dans un tableau)*/
int calcul_taille(char sequence[])
{
  int i=0;
  while(sequence[i]!='\0') i++; /*Le dernier i sera la taille de la séquence*/
  return i;
}

/*Fonction principale, pour calculer le score d'identite*/
 int Calcul_element_identique(char sequence1[],char sequence2[])
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

  char sequence1[taille1];
  char sequence2[taille2];

  extract_sequence(fichier1,sequence1);
<<<<<<< Updated upstream

  extract_sequence(fichier2,sequence2);

  Calcul_element_identique(sequence1,sequence2);
  fclose(fichier1);
  fclose(fichier2);
}
