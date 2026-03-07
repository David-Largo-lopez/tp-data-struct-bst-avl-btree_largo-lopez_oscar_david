#include <stdio.h>
#include "structure.h" 
#include "tree.h" 

int main() {
    // PARTIE 1 : EVALUATION POSTFIXE
    char expression[] = "3 4 + 2 *";

    printf("DEBUT DES TESTS : EVALUATION POSTFIXE \n");
    printf("Expression a evaluer : %s\n", expression);
    
    int resultat = eval_postfix(expression);
    
    printf("Resultat theorique attendu : 14\n");
    printf("Resultat calcule par le C  : %d\n", resultat);
    
    if (resultat == 14) {
        printf("SUCCES : La fonction eval_postfix est valide !\n\n");
    } else {
        printf("ERREUR : Il y a un probleme dans la logique.\n\n");
    }
    
    //  PARTIE 2 : ARBRE  BST
    
    printf("DEBUT DES TESTS : CREATION DU BST STATIQUE \n");
    
   
    TreeNode root = {
        .data = 'F',
        .parent = NULL,
        .left = &(TreeNode){
            .data = 'B',
            .parent = NULL,
            .left = &(TreeNode){ .data = 'A', .parent = NULL, .left = NULL, .right = NULL, },
            .right = &(TreeNode){
                .data = 'D',
                .parent = NULL,
                .left = &(TreeNode){ .data = 'C', .parent = NULL, .left = NULL, .right = NULL, },
                .right = &(TreeNode){ .data = 'E', .parent = NULL, .left = NULL, .right = NULL, },
            },
        },
        .right = &(TreeNode){
            .data = 'G',
            .parent = NULL,
            .left = NULL,
            .right = &(TreeNode){
                .data = 'I',
                .parent = NULL,
                .left = &(TreeNode){ .data = 'H', .parent = NULL, .left = NULL, .right = NULL, },
                .right = NULL,
            },
        },
    };

    printf("SUCCES : Arbre statique cree ! La racine contient la lettre : %c\n", root.data);
    printf("Enfant gauche de la racine : %c\n", root.left->data);
    printf("Enfant droit de la racine  : %c\n", root.right->data);
    
    return 0;
}