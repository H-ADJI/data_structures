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
binary_tree *create_binary_tree(int data);
