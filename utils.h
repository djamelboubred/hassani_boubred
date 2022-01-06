#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//utils.c 

void stocker_nom_fichier(char* nom_fichier);
void extract_sequence(FILE* fichier, char sequence[]);
void save_sequence(const char* path_output, char* sequence);	
int calcul_taille_fichier(FILE* fichier);


// recherche de sequence codante
void sequence_complementaire(char sequence[], int taille,char sequence_comp[]);
void recherche_sequence_codante(char sequence[],int taille);
int recherche_max_cds(char sequence[], int* position, int i);
// traduction
//void traduction(char sequence[], int taille);

// transcription
void transcription(char* sequence, int taille);

