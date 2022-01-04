#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void stocker_nom_fichier(char* nom_fichier)
{
  printf("Veuillez saisir le nom de votre fichier contenant la ou les séquences à analyser: ");
  scanf("%s",nom_fichier);
  printf("%s\n",nom_fichier);
}

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
//pas du tout testé et puis c'est nimportequoi je vais essayer de repenser differemment l'algo
char recherche_plus_grande_sous_chaine_commune(char sequence1[],char sequence2[]){
  int taille_seq1;
  int taille_seq2;
  int arret_boucle;
  taille_seq1=calcul_taille_sequence(fichier1);
  taille_seq2=calcul_taille_sequence(fichier2);
  if(taille_seq1<=taille_seq2){
  arret_boucle=taille_seq2;
  }
  else{
    arret_boucle=taille_seq1;
  }
  while(i<arret_boucle){
    for(i=0,i<arret_boucle,i++){
      if(sequence1[i].polarite==sequence2[i].polarite){
        compteur++;
        resultat[j]=sequence1[i];
    }
  }


}



int main(){
  int taille_seq1;
  int taille_seq2;
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

  taille_seq1=calcul_taille_sequence(fichier1);
  taille_seq2=calcul_taille_sequence(fichier2);
  char sequence1[taille_seq1];
  char sequence2[taille_seq2];
  sequence1=extract_tableau_sequence(fichier1,sequence1);
  sequence2=extract_tableau_sequence(fichier2,sequence2);



}
