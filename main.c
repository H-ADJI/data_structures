#include <stdio.h>
#include "headers/queue.h"
#include "headers/stack.h"
#include "headers/linked_list.h"

int main(void)
{
    stack *s = create_stack();
    queue *q = create_queue();
    int arr[] = {1, 2, 3};

    linked_list *list = create_linked_list(arr, sizeof(arr) / sizeof(arr[0]));
    append(1, list);
    insert(3, 99, list);
    search(1, list);

    // append(2, list);
    // append(3, list);
    // append(4, list);
    // append(5, list);
    repr_linked_list(list);

    delete (2, list);
    repr_linked_list(list);
}