#include <stdio.h>
#include "headers/queue.h"
#include "headers/stack.h"
#include "headers/linked_list.h"
#include "headers/hash_map.h"

int main(void)
{
    stack *s = create_stack();
    queue *q = create_queue();
    dict *age_map = create_hash_map();
    insert_to_dict(age_map, "khalil", 23);
    int age = get_value_from_dict(age_map, "khalil");
    printf("%d\n", age);
}