# Project Informatique Paris Saclay

Ce projet contient le code source du logiciel d'analyse de séquences. 
Ce logiciel est issu de la collaboration entre Djamel Boubred et Maïsen HASSANI.

Il contient les éléments suivants :
- ``source/`` : Contient le code source C
- ``results/`` : Contient les fichiers produits par le code
- ``Makefile`` : Décrit les raccourcis de commande pour compiler le code
- README.md
- .gitignore


## Fonctionnalités

Il permet les fonctionnalités suivantes

1. Recherche de la séquence codante de taille maximale
2. Transcription d’une séquence ADN en séquence ARN
3. Traduction d’une séquence codante en séquence protéique 
4. Calcul du score d’identité entre deux séquences
5. Calcul du score de similarité de polarité entre deux séquences protéiques
6. Recherche d’une séquence consensus à partir d’un alignement multiple 
7. Recherche de la plus grande sous-chaîne de polarité commune à 2 séquences protéiques


## Exécution en local

Pour exécuter le logiciel, taper la commande suivante :
```make run-project```

Les 7 modules s'exécuteront les uns à la suite des autres.
