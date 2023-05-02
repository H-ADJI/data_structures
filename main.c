#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include "linked_list.h"

int main(void)
{
    stack *s = create_stack();
    queue *q = create_queue();
    linked_list *list = create_linked_list();
    printf("hello, its working\n");
}