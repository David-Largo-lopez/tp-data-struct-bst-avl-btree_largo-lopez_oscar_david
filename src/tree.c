#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Préfixe (preorder) : Nœud → Gauche → Droite
void preorder(struct tree_node *n, process_fn process) {
    if (!n) return; 
    process(n);     
    preorder(n->left, process);  
    preorder(n->right, process); 
}

// Infixe (inorder) : Gauche → Nœud → Droite
void inorder(struct tree_node *n, process_fn process) {
    if (!n) return;
    inorder(n->left, process);
    process(n);
    inorder(n->right, process);
}

// Postfixe (postorder) : Gauche → Droite → Nœud
void postorder(struct tree_node *n, process_fn process) {
    if (!n) return;
    postorder(n->left, process);
    postorder(n->right, process);
    process(n);
}

void print_node(struct tree_node *n) {
    printf("%c ", n->data); 
}