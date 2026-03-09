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

# Proposer trois arbres

R\\ : Schéma des 3 types d'arbres BST  img/Arbre_BST.jpg

# Main de base avec arbre statique

Questions : 

1 : Limites et compatibilité

Construire un arbre directement dans le code bloque sa taille au début.
Pendant que le programme tourne, on ne peut pas ajouter de nouveaux nœuds ou en supprimer vu que
l'arbre est bloqué ou statique.

Cette construction est totalement incompatible avec free(). Selon ce qu'on à vu en cours et mes recherches, La règle en C est simple, on ne 
peut utiliser free() que pour effacer une mémoire créée par malloc(). Ici, on n'a pas utilisé malloc(), donc si on essaie de faire un free(), 
le programme va planter et creér ce qu'ils appels un (Erreur de segmentation).


2 : Écrire un main de base 
Dans main.c 

3 : Est-ce un BST alphabétique ?

Oui, l'arbre respecte la règle fondamentale (Gauche - Nœud - Droite) 
Si on le regarde, on voit que la racine est 'F'.
Tout le côté gauche ('B', 'A', 'D', 'C', 'E') est avant 'F' dans l'alphabet donc c'est le cote inférieur.

Tout le côté droit ('G', 'I', 'H') est après 'F' dans l'alphabet donc c'est le cote supérieur.
Chaque sous-arbre respecte aussi cette règle  pour exemple 'B', 'A' est à gauche, 'D' est à droite.

# Fonctions de traversée d’arbre récursives

Que donne le parcours infixe sur l’arbre précédent ?

R// : Parcours Infixe (Inorder) : A B C D E F G H I

# Transformer en allocation dynamique

Construire à la main le BST résultant de cette séquence d’insertions 

R// : schéma de l'arbre résultant de cette séquence.
 img/BTS_Sequence_insertion.jpg

R// : Si la séquence avait été insérée dans l'ordre croissant, résultat aurait été un arbre dégénéré, une simple 
ligne droite comme liste chaînée.


# Fonctions de traversée d’arbre itératives

1. Stratégie 
Je me repère avec seulement deux variables pour savoir où je suis "current"  et d'où je viens "prev" et juste en regardant par quel chemin je suis arrivé depuis le parent, le fils gauche ou le fils droit, je déduis logiquement la prochaine direction.


# Mettre en œuvre tree_delete

Arbre après suppression Tree_Delete.jpg

