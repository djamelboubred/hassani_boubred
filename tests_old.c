#include <stdio.h>

int main(){
  char sequence1= "AA--TCACGT";
  char sequence2= "AAGCTTAGTT";
  int i=0;/*compteur sequence 1*/
  int j=0;/*compteur sequence 2*/
  int k=0;/*compteur résultat alignement*/
  int nb_identique=0;
  int taille=0; /*calcul de: taille sequence1= taille sequence2*/
  alignement = malloc(taille * sizeof(int));/*alignement=résultat de la séquence alignée*/
  if (taille == NULL){
        exit(0);
  }
  taille=calcul_taille(sequence1,sequence2);

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

  int pourcentage;
  pourcentage=(nb_identique/taille)*100;
  printf("Identité de séquence:%d/%d, soit %f%\n",nb_identique,taille,pourcentage");
  printf("seq1 %s\n seq2 %s\n",sequence1*,sequence2*);
  printf("-id- %s\n",alignement);
}
}
