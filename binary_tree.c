#include <stdio.h>
#include <stdlib.h>

typedef struct tree_node
{
    int data;
    struct tree_node *left;
    struct tree_node *right;
} tree_node;

typedef struct binary_tree
{
    tree_node *root;
} binary_tree;

binary_tree *create_binary_tree(int data)
{
    binary_tree *tree = malloc(sizeof(binary_tree));
    tree_node *root = malloc(sizeof(tree_node));
    root->data = data;
    tree->root = root;
    return tree;
}

tree_node *insert_left(tree_node *node, int value)
{
    tree_node *left_node = malloc(sizeof(tree_node));
    node->left = left_node;
    left_node->data = value;
    return left_node;
}

tree_node *insert_right(tree_node *node, int value)
{
    tree_node *right_node = malloc(sizeof(tree_node));
    node->left = right_node;
    right_node->data = value;
    return right_node;
}
void inorder_traversal(binary_tree *tree)
{
}
void preorder_traversal(binary_tree *tree)
{
}
void postorder_traversal(binary_tree *tree)
{
}
