#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TRUE 0
#define FALSE 1

typedef struct proteine
{
  char id;
  int polarite;
  char code_lettre[4]; // ne pas oublier le '/0'

}proteine;

void stocker_nom_fichier(char* nom_fichier);
void extract_sequence(FILE* fichier, char sequence[]);
void save_sequence(const char* path_output, char* sequence);
int calcul_taille_fichier(FILE* fichier);


/*MODULE 1
void sequence_complementaire(char sequence[], int taille,char sequence_comp[]);
void recherche_sequence_codante(char sequence[],int taille);
int recherche_max_cds(char sequence[], int* position, int i);
int module_1();

//MODULE 2
void transcription(char* sequence, int taille);
int module_2();

//MODULE 3
void traduction(char sequence[], int taille);
int module_3();

//MODULE 4
int calcul_taille(char sequence[]);
void Calcul_element_identique(char sequence1[],char sequence2[]);
int module_4();

//MODULE 5
typedef struct proteine
{
  char id;
  int polarite;
}proteine;

proteine* creation_proteine(char lettre);
int calcul_taille_proteine(proteine sequence[]);
void extract_sequence_de_proteine(FILE* fichier, proteine sequence[]);
void afficher_sequence_proteine(proteine sequence[]);
void Calcul_polarite(proteine sequence1[],proteine sequence2[]);
int module_5();

//MODULE 6
bool verification_sequence_ADN(FILE* fichier);
bool sequences_memes_tailles(FILE* fichier);
int calcul_taille_sequence(FILE* fichier);
void extract_tableau_sequence(FILE* fichier, char sequence[]);
char afficher_sequence_consensus(char tableau_sequence[],int taille,int nb_sequence);
int calcul_nb_sequences(FILE* fichier);
int module_6();*/
