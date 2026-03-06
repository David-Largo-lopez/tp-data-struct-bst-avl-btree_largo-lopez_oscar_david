# TP1 - Structure de Donnees

# FIFO et LIFO
 1. Insertion de 1, 2, 3, 4, 5

* Séquence LIFO (Pile) : 5, 4, 3, 2, 1
    - Le dernier élement inséré (5) est le premier en sortir.
* Séquence FIFO (File) : 1, 2, 3, 4, 5
    - Le premier élement inséré (1) est le premier en sortir.

2. Inversion de l'ordre d'insertion (5, 4, 3, 2, 1)
  * LIFO : La sortie devient 1, 2, 3, 4, 5.
  * FIFO : La sortie devient 5, 4, 3, 2, 1.


# Évaluation Postfixe

 On parcourt l'expression de gauche à droite, Si c'est un nombre on le met sur la pile.
 Si c'est un opérateur on retire les deux derniers nombres de la pile (pop deux fois), et on fait 
 l'opération avec ces deux nombres.
 Apres on remet le résultat sur la pile.
et à la fin, le résultat final est le seul élément restant dans la pile.

1. Pour évaluer 3 4 + 2 * :

 3 -> Push(3) | Pile: [3]

 4 -> Push(4) | Pile: [3, 4]

 + -> Pop(4), Pop(3), Calcul 3+4=7, Push(7) | Pile: [7]

 2 -> Push(2) | Pile: [7, 2]

 * -> Pop(2), Pop(7), Calcul 7*2=14, Push(14) | Pile: [14]
  

# Différence de complexité spatiale 

La complexité spatiale avec malloc va créer en mémoire le nombre d'allocations demandées,
ça ralentit le traitement des données par la mémoire, et  l'espace utilisé grandit avec la taille de l'expression. 
C'est ce qu'on appelle la complexité O(N), c'est plus lourd et plus lent, parce que il faut créer et 
détruire les boîtes en permanence.

La façon proposée utilise un tableau statique, le tableau va toujours avoir la même taille, ce qui
 ne crée jamais de nouvelle mémoire en cours de route ni d'espace supplémentaire. 
 L'espace utilisé ne varie pas, c'est ce qu'on appelle la complexité O(1), c'est plus rapide et plus robuste.