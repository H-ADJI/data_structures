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
    node->right = right_node;
    right_node->data = value;
    return right_node;
}
void inorder_traversal(tree_node *tree_root)
{
    if (tree_root->left != NULL)
        inorder_traversal(tree_root->left);

    printf("%d \n", tree_root->data);

    if (tree_root->right != NULL)
        inorder_traversal(tree_root->right);
}
void preorder_traversal(tree_node *tree_root)
{
    printf("%d\n", tree_root->data);
    if (tree_root->left != NULL)
        preorder_traversal(tree_root->left);

    if (tree_root->right != NULL)
        preorder_traversal(tree_root->right);
}
void postorder_traversal(tree_node *tree_root)
{
    if (tree_root->left != NULL)
        postorder_traversal(tree_root->left);

    if (tree_root->right != NULL)
        postorder_traversal(tree_root->right);

    printf("%d\n", tree_root->data);
}
int get_tree_height(tree_node *root)
{
    if (root == NULL)
        return 0;
    int left_height = get_tree_height(root->left);
    int right_height = get_tree_height(root->right);
    if (right_height > left_height)
        return right_height + 1;
    return left_height + 1;
}
