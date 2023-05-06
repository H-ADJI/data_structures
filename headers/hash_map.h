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

int hash(char *key);
int get_value_from_dict(dict *table, char *key);
void insert_to_dict(dict *d, char *key, int value);
dict *create_hash_map();
