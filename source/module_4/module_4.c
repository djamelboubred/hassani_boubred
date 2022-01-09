#include "module_4.h"

/*Permet de calculer la taille d'une sequence ( pas dans un fichier mais dans un tableau)
entrée: sequence sous forme de tableau
sortie: taille de la sequence */
int calcul_taille(char sequence[])
{
  int i=0;
  while(sequence[i]!='\0') i++; /*Le dernier i sera la taille de la séquence*/
  return i;
}

/*Fonction principale du module, prermet de calculer le score d'identite
entrée: 2 sequences sous forme de tableau
sortie: ne renvoie rien */
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

 /* fonction qui permet d'executer a la chaine les fonctions precedente du module 4,
elle ne prend pas d'entrée et renvoie une erreur si le ou les fichiers n'ont pas pu etre ouvert*/
int module_4(){
  printf("\n MODULE 4: Calcul du score d’identité entre deux séquences \n");
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
  printf("test7\n");

  int taille2= calcul_taille_fichier(fichier2);
  printf("test8   \n");

  if(taille1!=taille2)
  {
    printf("Attention : Comparaison de séquences de tailles differentes\n");
  }
  char* sequence1= malloc(sizeof(char)*taille1);
  char* sequence2= malloc(sizeof(char)*taille2);
  extract_sequence(fichier1,sequence1);
  extract_sequence(fichier2,sequence2);

  Calcul_element_identique(sequence1,sequence2);
  free(sequence1);
  free(sequence2);
  fclose(fichier1);
  fclose(fichier2);
  return 0;
}

/*fonction main du module 4*/
int main(){
  module_4();
}
