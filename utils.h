#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//utils.c 

void stocker_nom_fichier(char* nom_fichier);
void extract_sequence(FILE* fichier, char sequence[]);
void save_sequence(const char* path_output, char* sequence);	


// recherche de sequence codante toujours incorrect erreur de segmentation ligne 92

void sequence_complementaire(char sequence[], int taille,char sequence_comp[]);
void recherche_sequence_codante(char sequence[],int taille);

// traduction
//void traduction(char sequence[], int taille);

// transcription correct
//void transcription(char* sequence, int taille);

