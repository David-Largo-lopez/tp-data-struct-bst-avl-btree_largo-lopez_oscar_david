#ifndef TREE_H
#define TREE_H


struct tree_node {
    int data; 
    struct tree_node *parent;
    struct tree_node *left;
    struct tree_node *right;
};

typedef struct tree_node TreeNode;
typedef void (*process_fn)(struct tree_node *);

#endif