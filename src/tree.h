#ifndef TREE_H
#define TREE_H

struct tree_node
{
    int data;
    struct tree_node *parent;
    struct tree_node *left;
    struct tree_node *right;
};

typedef struct tree_node TreeNode;
typedef void (*process_fn)(struct tree_node *);

void preorder(struct tree_node *n, process_fn process);
void inorder(struct tree_node *n, process_fn process);
void postorder(struct tree_node *n, process_fn process);
void print_node(struct tree_node *n);

struct tree_node *node_new(int data);
struct tree_node *bst_insert(struct tree_node **root, int data);
void tree_free(struct tree_node *root);

void preorder_iterative(struct tree_node *root, process_fn process);
void inorder_iterative(struct tree_node *root, process_fn process);

#endif