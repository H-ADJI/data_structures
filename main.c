#include <stdio.h>
#include "headers/queue.h"
#include "headers/stack.h"
#include "headers/linked_list.h"
#include "headers/hash_map.h"
#include "headers/binary_tree.h"

int main(void)
{
    binary_tree *tree = create_binary_tree(1);

    printf("depth: %d \n", get_tree_height(tree->root));
}