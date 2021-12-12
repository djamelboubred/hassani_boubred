# hassani_boubred
project c collaboration between Hassani and boubred
FONCTIONS PRINCIPALES PAR MODULE:

## 1. Recherche de la séquence codante de taille maximale
``char* Recherche_sequence_codante( Char* sequence)`` renvoie char* sequence (ADN)

## 2. Transcription d’une séquence ADN en séquence ARN
``char* transcription( char* sequence)`` renvoie char* sequence (ARN)

## 3. Traduction d’une séquence codante en séquence protéique 
``char* traduction( char sequence (ARN))`` renvoie char* sequence (proteine)

## 4. Calcul du score d’identité entre deux séquences
``float Calcul_score_identite( FILE fichier1, FILE fichier 2 `` ( avec fichier1 et fichier2 contenant sequences) renvoie un nombre (=score identite)

## 5. Calcul du score de similarité de polarité entre deux séquences protéiques
``int Calcul_score_similarite( FILE* fichier1, FILE* fichier 2)`` renvoie un nombre d'AA similaires par type (=score similarite de polarite)

## 6.Recherche d’une séquence consensus à partir d’un alignement multiple  
``char* Recherche_sequence_consensus(FILE* fichier)`` renvoie un alignement multiple annoté

## 7. Recherche de la plus grande sous-chaîne de polarité commune à 2 séquences protéiques
on verra à la fin...
