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

struct tree_node *bst_insert(struct tree_node **root, int data)
{
    struct tree_node *node = node_new(data);

    if (*root == NULL)
    {
        *root = node;
        return node;
    }

    struct tree_node *current = *root;
    struct tree_node *parent = NULL;

    while (current != NULL)
    {
        parent = current;

        if (data < current->data)
        {
            current = current->left;
        }
        else if (data > current->data)
        {
            current = current->right;
        }
        else
        {
            free(node);
            return NULL;
        }
    }

    node->parent = parent;

    if (data < parent->data)
    {
        parent->left = node;
    }
    else
    {
        parent->right = node;
    }

    return node;
}

// Traverse itératif

void preorder_iterative(struct tree_node *root, process_fn process)
{
    if (!root)
        return;

    struct tree_node *current = root;
    struct tree_node *prev = NULL;

    while (current != NULL)
    {
        if (prev == current->parent)
        {
            process(current);

            if (current->left)
            {
                prev = current;
                current = current->left;
            }
            else if (current->right)
            {
                prev = current;
                current = current->right;
            }
            else
            {
                prev = current;
                current = current->parent;
            }
        }
        else if (prev == current->left)
        {
            if (current->right)
            {
                prev = current;
                current = current->right;
            }
            else
            {
                prev = current;
                current = current->parent;
            }
        }
        else
        {
            prev = current;
            current = current->parent;
        }
    }
}

void inorder_iterative(struct tree_node *root, process_fn process)
{
    if (!root)
        return;

    struct tree_node *current = root;
    struct tree_node *prev = NULL;

    while (current != NULL)
    {
        if (prev == current->parent)
        {
            if (current->left)
            {
                prev = current;
                current = current->left;
            }
            else
            {
                process(current);
                if (current->right)
                {
                    prev = current;
                    current = current->right;
                }
                else
                {
                    prev = current;
                    current = current->parent;
                }
            }
        }
        else if (prev == current->left)
        {
            process(current);
            if (current->right)
            {
                prev = current;
                current = current->right;
            }
            else
            {
                prev = current;
                current = current->parent;
            }
        }
        else
        {
            prev = current;
            current = current->parent;
        }
    }
}

void free_node_callback(struct tree_node *n)
{
    free(n);
}

void tree_free(struct tree_node *root)
{
    postorder(root, free_node_callback);
}