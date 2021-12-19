#include <stdio.h>
#include "utils.h"


/*permet de compter le nombre de caractères identiques à la même place dans les deux séquences*/
float Calcul_score_identite( FILE* fichier1, FILE* fichier 2){
  void extract_sequence(fichier1, sequence1*);
  void extract_sequence(fichier2, sequence2*);
  int i=0;/*compteur sequence 1*/
  int j=0;/*compteur sequence 2*/
  int k=0;/*compteur résultat alignement*/
  int nb_identique=0;
  int taille=0; /*taille sequence 1 et 2*/
  alignement = malloc(taille * sizeof(int));
	if (taille == NULL){
        exit(0);
  }
  while(sequence1[i]!="\0" && sequence2[j]!="\0" ){
    if(sequence1[i]==sequence2[j]){
      nb_identique=nb_identique++;
      alignement[k]=sequence1[i];/*on remplit tableau alignement avec nucleotide de sequence 1, on aurait pu prendre seuqence 2 c'est le meme nucleotide*/
    else{
      alignement[k]="-";/*sinon on remplit le tableau alignement avec un tiret*/
    }
    i=i++; /*on incremente de 1 chaque compteur pour passer a la case suivante du tableau*/
    j=j++;
    k=k++;
    taille=taille+1;/* i,j,k et taille auront la meme valeur à la fin, mais je decide de rajouter une variable du nom de taille pour que le code soit plus claire*/
  }
  int pourcentage;
  pourcentage=(nb_identique/taille)*100;
  printf("Identité de séquence:%d/%d, soit %f%\n",nb_identique,taille,pourcentage");
  printf("seq1 %s\n seq2 %s\n",sequence1*,sequence2*);
  printf("-id- %s\n",alignement);
}
