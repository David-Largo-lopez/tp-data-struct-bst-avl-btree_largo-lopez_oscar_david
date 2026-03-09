#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

// Préfixe (preorder) : Nœud → Gauche → Droite
void preorder(struct tree_node *n, process_fn process)
{
    if (!n)
        return;
    process(n);
    preorder(n->left, process);
    preorder(n->right, process);
}

// Infixe (inorder) : Gauche → Nœud → Droite
void inorder(struct tree_node *n, process_fn process)
{
    if (!n)
        return;
    inorder(n->left, process);
    process(n);
    inorder(n->right, process);
}

// Postfixe (postorder) : Gauche → Droite → Nœud
void postorder(struct tree_node *n, process_fn process)
{
    if (!n)
        return;
    postorder(n->left, process);
    postorder(n->right, process);
    process(n);
}

void print_node(struct tree_node *n)
{
    printf("%c ", n->data);
}

struct tree_node *node_new(int data)
{
    struct tree_node *new_node = (struct tree_node *)malloc(sizeof(struct tree_node));

    if (new_node == NULL)
    {
        printf("ERREUR : Echec de l'allocation memoire.\n");
        exit(1);
    }

    new_node->data = data;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

struct tree_node *bst_insert(struct tree_node *root, struct tree_node *node)
{
    if (root == NULL)
    {
        return node;
    }

    struct tree_node *current = root;
    struct tree_node *parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (node->data < current->data)
        {
            current = current->left;
        }
        else if (node->data > current->data)
        {
            current = current->right;
        }
        else
        {
            free(node);
            return root;
        }
    }

    node->parent = parent;

    if (node->data < parent->data)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }

    return root;
}