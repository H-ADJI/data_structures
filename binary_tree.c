#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

typedef struct binary_tree
{
    node *root;
} binary_tree;
