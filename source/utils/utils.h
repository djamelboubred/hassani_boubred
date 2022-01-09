#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TRUE 0
#define FALSE 1

// type AA (acide amine) utilisé dans plusieurs module et permet d'enregistrer toutes les caracteristiques que l'on a besoin pour decrir un acide amine
typedef struct AA
{
  char id;
  int polarite;
  char code_lettre[4]; // ne pas oublier le '/0'

}AA;

void stocker_nom_fichier(char* nom_fichier);
void extract_sequence(FILE* fichier, char sequence[]);
void save_sequence(const char* path_output, char* sequence);
int calcul_taille_fichier(FILE* fichier);
