#include "module_6.h"

 /* permet de verifier que le fichier ne contient rien d’autre que des séquences d'acide nucléiques
 entrée: un fichier deja ouvert
 sortie: un booleen FALSE ou TRUE,si le fichier ne contient que des acides nucleiques ou des gaps renvoie TRUE */
bool verification_sequence_ADN(FILE* fichier){
  bool isvalid=false;
  char lettre_lu;
  fseek(fichier,0,SEEK_SET);// curseur debut du fichier
  while((lettre_lu=fgetc(fichier))!=EOF){// tant que la lettre lu n'est pas EOF cest a dire ce qui marque la fin du fichier
    if(lettre_lu=='A'||lettre_lu=='T'||lettre_lu=='C'||lettre_lu=='G'||lettre_lu=='-'||lettre_lu=='\n'){
        isvalid=true;
    }
  }
  if(isvalid==false){
    printf("Erreur, votre fichier ne contient pas uniquement des sequences ADN\n");
  }
  return isvalid;
}

/*permet de verifier que toutes les séquences present dans le fichier ont la meme taille
entrée: un fichier deja ouvert
sortie: un booleen FALSE ou TRUE ,si les sequences presentes dans le fichier ont memes tailles renvoie TRUE*/
bool sequences_memes_tailles(FILE* fichier){
  bool isvalid=true;
  int taille_premiere_ligne=0;
  int taille_sequence_tmp;//taille de chaque sequence que l'on calcule pregressivement, d'abord la deuxieme ligne puis la 3 eme si notre booleen est TRUE etc
  // Calcul de la taille de la premiere ligne
  fseek(fichier,0,SEEK_SET);
  while(fgetc(fichier)!='\n'){//tant que l'on se trouve sur la premiere ligne
    taille_premiere_ligne++;
  }
// Calcul de la taille de la ieme ligne
  while(fgetc(fichier)!=EOF){
    taille_sequence_tmp=1;// pour avoir la bonne taille puisque le curseur est avancé de 1 deja
    while(fgetc(fichier)!='\n'){
      taille_sequence_tmp++;
    }
    if (taille_sequence_tmp!=taille_premiere_ligne){//pour ne pas continuer de calculer les tailles suivantes car il suffit qu'une sequence soit de taille differente
      isvalid=false;
    }
  }
  if(isvalid==false){//on renvoie un message d'erreur
  printf("Erreur,les sequences ne sont pas de meme tailles\n");
  exit(1);
  }
  return isvalid;
}

/*permet de calculer la taille d'une sequence present dans un fichier qui contient une ou plusieurs sequences
entrée: un fichier deja ouvert
sortie: la taille de la premiere sequence */
int calcul_taille_sequence(FILE* fichier){
  int taille_sequence=0;
  fseek(fichier,0,SEEK_SET);
  while(fgetc(fichier)!='\n'){//calcule la taille de la premiere sequence
    taille_sequence++;
  }
  return taille_sequence;
}

/*permet de calculer la taille d'une sequence present dans un fichier qui contient une ou plusieurs sequences
entrée: un fichier deja ouvert
sortie: la taille de la premiere sequence */
void extract_tableau_sequence(FILE* fichier, char sequence[]){
  int i=0;
  char lettre_lu;
  fseek(fichier,0,SEEK_SET);
  while((lettre_lu=fgetc(fichier))!=EOF){
    sequence[i]=lettre_lu;
    i++;
  }
}

/* fonction principale du module: permet de calculer le score identite pour chaque nucleotide de chaque sequence et affiche la sequence consensus
entrée: un tableau comportant un alignement de sequence, la taille d'une sequence (toutes identiques), et le nombre de sequence
sortie: rien  */
void afficher_sequence_consensus(char tableau_sequence[],int taille,int nb_sequence){
  int nb_A=0, nb_T=0, nb_C=0, nb_G=0, nb_gap=0;//nombre de chaque element dans chaque sequence a l'incide i
  int i; //indice ligne
  int k=0;//indice colonne
  float nb_element_maj=0;//nbr AA majoritaire par colonne donc par indice i
  float score_identite=0;
  char sequence_consensus[taille];// sequence final representant score d'identite
  sequence_consensus[taille]='\0';
  taille ++; // On prend en compte le retour à la ligne (=\n) pour ne pas avoir de decalage
  while(k!=taille){ // boucle qui permet d'avancer au sein de la colonne k(en descendant dans les sequences)
    for(i=0;i<nb_sequence;i++){ // boucle qui traite chaque element de la ligne a indice i
      if(tableau_sequence[i*taille+k]=='A') nb_A++;// i*taille permet d'avancer de 1 a chaque colonne, l'ajout de k permet d'avancer de 1 dans chaque ligne
      if(tableau_sequence[i*taille+k]=='T') nb_T++;
      if(tableau_sequence[i*taille+k]=='C') nb_C++;
      if(tableau_sequence[i*taille+k]=='G') nb_G++;
      if(tableau_sequence[i*taille+k]=='-') nb_gap++;
    }

    //On prend le nombre de l'element majoritaire pour chaque colonne, si deux elements sont majoriatires,l'un des deux sera pris selon l'ordre des if car ecrasement du premier
    if(nb_A>=nb_T && nb_A>=nb_C && nb_A>=nb_G && nb_A>=nb_gap) nb_element_maj=nb_A;
    if(nb_T>=nb_A && nb_T>=nb_C && nb_T>=nb_G && nb_T>=nb_gap) nb_element_maj=nb_T;
    if(nb_C>=nb_T && nb_C>=nb_A && nb_C>=nb_G && nb_C>=nb_gap) nb_element_maj=nb_C;
    if(nb_G>=nb_T && nb_G>=nb_C && nb_G>=nb_A && nb_G>=nb_gap) nb_element_maj=nb_G;
    if(nb_gap>=nb_T && nb_gap>=nb_C && nb_gap>=nb_G && nb_gap>=nb_A) nb_element_maj=nb_gap;

    score_identite=(nb_element_maj/nb_sequence)*100;
    //critere d'affichage pour la sequence consensus
    if(score_identite<60) sequence_consensus[k]=' ';
    if(score_identite>=60) sequence_consensus[k]='-';
    if(score_identite>=80) sequence_consensus[k]='*';
    if(score_identite==100) sequence_consensus[k]=tableau_sequence[k];

    k++;//on incremente k pour passer a la colonne suivante(=nucleotide suivant)
    nb_A=0; nb_T=0; nb_C=0; nb_G=0; nb_gap=0; score_identite=0;//
  }
  printf("sequence consensus:\n%s\n",sequence_consensus);
}

/* permet de calculer nombre de ligne dans un fichier =nbr de sequence
entrée: fichier deja ouvert
sortie: nombre de sequence dans un fichier */

int calcul_nb_sequences(FILE* fichier){
  int nb_sequence=0;
  char lettre_lu;
  fseek(fichier,0,SEEK_SET);
  while((lettre_lu=fgetc(fichier))!=EOF){
    if(lettre_lu=='\n'){
      nb_sequence++;
    }
  }
  return nb_sequence;
}

/* fonction qui permet d'executer a la chaine les fonctions precedente du module 6,
elle ne prend pas d'entrée et renvoie une erreur si le ou les fichiers n'ont pas pu etre ouvert*/
int module_6(){
  printf("\n MODULE 6: Recherche d’une séquence consensus à partir d’un alignement multiple \n");
  printf("L'ordinateur va vous demander à une seule reprise de taper le chemin menant à votre fichier contenant vos sequences\n");
  char* nom_fichier=malloc(sizeof(char));
  stocker_nom_fichier(nom_fichier);
  int taille_sequence=0;//taille de chaque sequence (taille d'une ligne dans un fichier)
  int nb_sequence=0;//nombre de ligne dans un fichier
  FILE* fichier=fopen(nom_fichier,"r");
  if (!fichier){
      fprintf(stderr, "L'ouverture a échoué");
      return EXIT_FAILURE;
  }
  int taille_tableau_sequence=calcul_taille_fichier(fichier);//on calcule la taille total du fichier pour creer ensuite un tableau de cette taille
  char tableau_sequence[taille_tableau_sequence];// tableau_sequences comportera toutes les sequences presents dans le fichier donné par l'utilisateur

  verification_sequence_ADN(fichier);//on verifie que le fichier contient sequence ADN seulement
  calcul_nb_sequences(fichier);// on verifie que toutes les sequences ont la meme taille
  taille_sequence=calcul_taille_sequence(fichier);
  nb_sequence=calcul_nb_sequences(fichier);
  extract_tableau_sequence(fichier,tableau_sequence);

  afficher_sequence_consensus(tableau_sequence,taille_sequence,nb_sequence);
  return 0;
}

int main(){
  module_6();
}
