#include "module_4.h"

/*Permet de calculer la taille d'une sequence ( pas dans un fichier mais dans un tableau)
entrée: sequence sous forme de tableau
sortie: taille de la sequence */
int calcul_taille(char sequence[]){
  int i=0;//i est un compteur pour calculer la taille de la sequence
  while(sequence[i]!='\0'){
    i++; /*Tant que la lecture de la sequence n'est pas fini, on incremente i de 1 */
  }
  return i;
}

/*Fonction principale du module, prermet de calculer le score d'identite
entrée: 2 sequences sous forme de tableau
sortie: ne renvoie rien */
 void Calcul_element_identique(char sequence1[],char sequence2[]){
   int i=0;/*compteur séquence 1 et 2 car elles sont de memes tailles*/
   float nb_identique=0;//nombre d'element identique entre les deux sequences à l'indice i
   int taille = calcul_taille(sequence1);// taille de la sequence 1(=taille sequence2)
   float score_identite;//entre les deux sequences
   char id[taille];// sequence final: represente le score d'identite à chaque indice i
   id[taille]='\0';//on initialise la sequence final avec le symbole de fin de chaine de caractere

   while(sequence1[i]!='\0'){// Tant que la sequence 1 (et 2 puisque meme taille) n'est pas fini
      if(sequence1[i]==sequence2[i] && sequence1[i]!='-'){/*2eme condition permet d'eviter de compter un nbr identique si on compare 2 Gap*/
        nb_identique++;
        id[i]=sequence1[i];/*on remplit la sequence final avec le nucleotide de la sequence 1, on aurait pu prendre seuqence 2 c'est le meme nucleotide*/
      }
      else{ //donc si sequence1[i]=!sequence2[i] ou (sequence1[i]='-' et sequence2[i]='-') ou (sequence1[i]='-' et sequence2[i]=!'-') ou (sequence1[i]=!'-' et sequence2[i]='-')
        id[i]='-';/*sinon on remplit la sequence resultat avec un tiret*/
      }
      i++; /*on incremente de 1 chaque compteur pour passer a l'element suivant*/
   }

   score_identite=(nb_identique/taille)*100;//formule du score identite
   printf("Identité de séquence : %.0f/%d, soit %.1f %% \n",nb_identique,taille,score_identite);
   printf("seq1 %s\n",sequence1);
   printf("seq2 %s\n",sequence2);
   printf("-id- %s\n",id);
 }

 /* fonction qui permet d'executer a la chaine les fonctions precedente du module 4,
elle ne prend pas d'entrée et renvoie une erreur si le ou les fichiers n'ont pas pu etre ouvert*/
int module_4(){
  printf("\n MODULE 4: Calcul du score d’identité entre deux séquences \n");
  printf("L'ordinateur va vous demander à deux reprises de taper les 2 chemins menant à vos fichiers contenant vos sequences\n");

  char* nom_fichier1=malloc(sizeof(char)*30);
  char* nom_fichier2=malloc(sizeof(char)*30);//allocation dynamique pour les noms de fichiers car on utilise ici des pointeurs
  stocker_nom_fichier(nom_fichier1);
  stocker_nom_fichier(nom_fichier2);//on recupere les noms de fichiers donnés par l'utilisateur
  FILE* fichier1=fopen(nom_fichier1,"r");
  FILE* fichier2=fopen(nom_fichier2,"r");
  if (!fichier1 || !fichier2){//si le fichier 1 ou 2 ne s'ouvre pas, afficher un message d'erreur
  		fprintf(stderr, "L'ouverture a échoué");
  		return EXIT_FAILURE;
  }
  int taille1= calcul_taille_fichier(fichier1);
  int taille2= calcul_taille_fichier(fichier2);
  if(taille1!=taille2){//si taille des fichiers ne sont pas egales, sortir du programme
    printf("Erreur: Comparaison de séquences de tailles differentes\n");
    return EXIT_FAILURE;
  }
  char* sequence1= malloc(sizeof(char)*taille1);//allocation dynamique car pointeurs
  char* sequence2= malloc(sizeof(char)*taille2);
  extract_sequence(fichier1,sequence1);
  extract_sequence(fichier2,sequence2);

  Calcul_element_identique(sequence1,sequence2);
  free(sequence1);//on libere l'allocation dynamique
  free(sequence2);
  fclose(fichier1);//fermeture des fichiers
  fclose(fichier2);
  return 0;// car on est dans une fonction
}

/*fonction main du module 4*/
int main(){
  module_4();
}
