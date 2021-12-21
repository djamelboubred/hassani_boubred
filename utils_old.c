#include <stdio.h>

int main(){
  char sequence1= "AA--TCACGT";
  char sequence2= "AAGCTTAGTT";
  int calcul_taille(char sequence1,char sequence2){
    int i=0;
    int j=0;
    int taille1=0;
    int taille2=0;
    while(sequence1[i]!="\0"){
      taille1=taille1++;
      i=i++
    }
    while(sequence2[j]!="\0"){
      taille2=taille2++;
      j=j++;
    }
    if(taille1!=taille2){
      printf("Les deux séquences n'ont pas la meme taille, l'alignement est impossible");
    }
    else{
      return taille1;
    }
  }
}
