#include <stdio.h>
#include "structure.h"
#include "tree.h"

void print_node_int(struct tree_node *n)
{
    printf("%d ", n->data);
}

int main()
{
    // PARTIE EVALUATION POSTFIXE
    char expression[] = "3 4 + 2 *";

    printf(" TESTS : EVALUATION POSTFIXE \n");
    printf("Expression a evaluer : %s\n", expression);

    int resultat = eval_postfix(expression);

    printf("Resultat theorique attendu : 14\n");
    printf("Resultat calcule par le C  : %d\n", resultat);

    if (resultat == 14)
    {
        printf("SUCCES : La fonction eval_postfix est valide \n\n");
    }
    else
    {
        printf("ERREUR : Il y a un probleme dans la logique.\n\n");
    }

    //  PARTIE  ARBRE BST

    printf("TESTS : CREATION  BST STATIQUE \n");

    TreeNode root = {
        .data = 'F',
        .parent = NULL,
        .left = &(TreeNode){
            .data = 'B',
            .parent = NULL,
            .left = &(TreeNode){
                .data = 'A',
                .parent = NULL,
                .left = NULL,
                .right = NULL,
            },
            .right = &(TreeNode){
                .data = 'D',
                .parent = NULL,
                .left = &(TreeNode){
                    .data = 'C',
                    .parent = NULL,
                    .left = NULL,
                    .right = NULL,
                },
                .right = &(TreeNode){
                    .data = 'E',
                    .parent = NULL,
                    .left = NULL,
                    .right = NULL,
                },
            },
        },
        .right = &(TreeNode){
            .data = 'G',
            .parent = NULL,
            .left = NULL,
            .right = &(TreeNode){
                .data = 'I',
                .parent = NULL,
                .left = &(TreeNode){
                    .data = 'H',
                    .parent = NULL,
                    .left = NULL,
                    .right = NULL,
                },
                .right = NULL,
            },
        },
    };

    printf("SUCCES : Arbre statique cree racine lettre : %c\n", root.data);
    printf("Enfant gauche de la racine : %c\n", root.left->data);
    printf("Enfant droit de la racine  : %c\n", root.right->data);

    printf("\n TESTS PARCOURS RECURSIFS \n");

    printf("Parcours Prefixe (Preorder)  : ");
    preorder(&root, print_node);
    printf("\n");

    printf("Parcours Infixe (Inorder)    : ");
    inorder(&root, print_node);
    printf("\n");

    printf("Parcours Postfixe (Postorder): ");
    postorder(&root, print_node);
    printf("\n");

    // PARTIE  BST DYNAMIQUE

    printf("\n TESTS : CREATION  BST DYNAMIQUE \n");

    struct tree_node *dynamic_root = NULL;

    int valeurs[] = {10, 2, 25, 15, 30, 12, 20, 16, 24, 17, 22};
    int nb_valeurs = sizeof(valeurs) / sizeof(valeurs[0]);

    for (int j = 0; j < nb_valeurs; j++)
    {
        bst_insert(&dynamic_root, valeurs[j]);
    }

    printf("SUCCES : Arbre dynamique avec malloc.\n");

    printf("Parcours Infixe (croissant) : ");
    inorder(dynamic_root, print_node_int);
    printf("\n");

    // PARTIE  PARCOURS ITERATIFS

    printf("\n TESTS PARCOURS ITERATIFS  \n");
    printf("Parcours Prefixe Iteratif : ");
    preorder_iterative(dynamic_root, print_node_int);
    printf("\n");

    printf("Parcours Infixe Iteratif  : ");
    inorder_iterative(dynamic_root, print_node_int);
    printf("\n");

    // PARTIE  SUPPRESSION DANS LE BST
    
    printf("\n TESTS : SUPPRESSION DANS LE BST  \n");

    printf("Arbre avant suppression : ");
    inorder_iterative(dynamic_root, print_node_int);
    printf("\n");

    printf("Suppression de 24,  1 enfant : ");
    tree_delete(&dynamic_root, 24);
    inorder_iterative(dynamic_root, print_node_int);
    printf("\n");

    printf("Suppression de 15,  2 enfants  : ");
    tree_delete(&dynamic_root, 15);
    inorder_iterative(dynamic_root, print_node_int);
    printf("\n");

    tree_free(dynamic_root);
    printf("\n SUCCES : Memoire liberee  avec tree_free.\n");

    return 0;
}