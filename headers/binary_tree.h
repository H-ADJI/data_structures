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
tree_node *insert_left(tree_node *node, int value);
tree_node *insert_right(tree_node *node, int value);
void inorder_traversal(binary_tree *tree);
void preorder_traversal(binary_tree *tree);
void postorder_traversal(binary_tree *tree);
