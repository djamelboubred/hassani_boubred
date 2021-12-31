#include "utils_tmp.c"


int main(){
  char* nom_fichier1=malloc(sizeof(char));
  char* nom_fichier2=malloc(sizeof(char));
  stocker_nom_fichier(fichier1);
  stocker_nom_fichier(fichier2);

  FILE* fichier1=fopen(nom_fichier1,"r");
  FILE* fichier2=fopen(nom_fichier2,"r");
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

  extract_sequence(fichier2,sequence2);

  Calcul_element_identique(sequence1,sequence2);
  fclose(fichier1);
  fclose(fichier2);
}
