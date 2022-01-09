#include "utils.h"

bool verification_sequence_ADN(FILE* fichier);
bool sequences_memes_tailles(FILE* fichier);
int calcul_taille_sequence(FILE* fichier);
void extract_tableau_sequence(FILE* fichier, char sequence[]);
void afficher_sequence_consensus(char tableau_sequence[],int taille,int nb_sequence);
int calcul_nb_sequences(FILE* fichier);
int module_6();
