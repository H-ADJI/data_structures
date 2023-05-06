#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define CAPACITY 10
#define PRIMEFACTOR 31

typedef struct kvpair
{
    char *key;
    int value;
    struct kvpair *next;
} kvpair;

typedef struct dict
{
    kvpair *values[CAPACITY];

} dict;
dict *create_hash_map()
{
    return malloc(sizeof(dict));
}
int hash(char *key)
{

    int hash_value = 0;
    for (int i = 0; key[i] != '\0'; i++)
    {
        hash_value = (hash_value * PRIMEFACTOR + (int)key[i]) % CAPACITY;
    }
    return hash_value;
}

int get_value_from_dict(dict *d, char *key)
{
    int hash_value = hash(key);
    kvpair *pair = d->values[hash_value];
    if (pair == NULL)
    {
        printf("this key is non-existant\n");
        return -1;
    }
    char *current_key = pair->key;
    while (strcmp(current_key, key) != 0)
    {
        pair = pair->next;
        current_key = pair->key;
    }
    return pair->value;
}
void insert_to_dict(dict *d, char *key, int value)
{
    int hash_value = hash(key);

    kvpair *pair = d->values[hash_value];

    while (pair != NULL)
    {
        printf("%p\n", pair);

        pair = pair->next;
    }
    if (pair == NULL)
    {
        d->values[hash_value] = malloc(sizeof(kvpair));
        d->values[hash_value]->key = key;
        d->values[hash_value]->value = value;
    }
    else
    {
        pair->key = key;

        pair->value = value;
    }
}
