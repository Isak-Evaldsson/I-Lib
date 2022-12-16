/*
    Generic hash set implementation using chaining
*/

#include "ilib/set.h"

#define INITIAL_SIZE (10)

/* Internal structure holding the table chains */
typedef struct bucket_t bucket_t;

struct bucket_t {
    void     *value;
    bucket_t *next;
};

/* Hash set data structure */
struct set_t {
    size_t     size;
    size_t     entries; /* allows table to grow when its to well-filled */
    bucket_t **array;
};

/* creates new bucket and appends it to the next */
static bucket_t *create_bucket(void *value, bucket_t *next)
{
    bucket_t *b = malloc(sizeof(bucket_t));
    if (b == NULL) {
        return NULL;
    }

    b->value = value;
    b->next  = next;
    return b;
}

static void free_bucket(bucket_t *bucket)
{
    bucket_t *tmp, *b = bucket;

    if (bucket == NULL) {
        return;
    }

    while (b != NULL) {
        tmp = b;
        b   = b->next;
        free(tmp);
    }
}

/* expand tables, returns true if successful */
static bool expand_table(set_t *set)
{
    size_t     new_size  = 2 * set->size;
    bucket_t **old_array = set->array;
    bucket_t **new_array = calloc(new_size, sizeof(bucket_t));

    // Failed to expand table
    if (new_array == NULL) {
        free(new_array);
        return false;
    }

    // re-balance table
    for (size_t i = 0; i < set->size; i++) {
        size_t    new_index;
        bucket_t *b = old_array[i];
        bucket_t *prev, *tmp;

        // Iterate over linked list and re-insert elements
        while (b != NULL) {
            tmp = b;
            b   = b->next;

            // Compute place in array
            new_index = (size_t)tmp->value % new_size;
            prev      = new_array[new_index];

            // prepend bucket tmp to the previous one
            new_array[new_index] = tmp;
            tmp->next            = prev;
        }
    }

    // assign the new table
    set->array = new_array;
    set->size  = new_size;

    // clean-up
    free(old_array);
    return true;
}

/* Constructs set */
set_t *set_new()
{
    set_t     *set;
    bucket_t **array;

    if ((set = malloc(sizeof(set_t))) == NULL) {
        return NULL;
    }

    if ((array = calloc(sizeof(bucket_t *), INITIAL_SIZE)) == NULL) {
        free(set);
        return NULL;
    }

    set->size    = INITIAL_SIZE;
    set->entries = 0;
    set->array   = array;

    return set;
}

/* Adds a new value to the set, returns false if value already exits */
bool set_add(set_t *set, void *value)
{
    size_t    index = (size_t)value % set->size;
    bucket_t *head  = set->array[index];

    // check if element already exits
    for (bucket_t *b = head; b != NULL; b = b->next) {
        if (b->value == value) return false;
    }

    set->array[index] = create_bucket(value, head);
    set->entries++;

    if (set->entries / set->size >= 2) {
        expand_table(set);
    }

    return true;
}

/* Checks if set contians the specified value */
bool set_contains(set_t *set, void *value)
{
    bucket_t *b;
    int       index = (size_t)value % set->size;

    for (b = set->array[index]; b != NULL; b = b->next) {
        if (b->value == value) return true;
    }
    return false;
}

/* Returns number of elements in set */
size_t set_size(set_t *set)
{
    return set->entries;
}

/* Returs a vector containg all elements of the set */
vector_t *set_to_vector(set_t *set)
{
    vector_t *vec = vector_new();
    if (vec == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < set->size; i++) {
        bucket_t *b = set->array[i];
        void     *data;

        for (bucket_t *b = set->array[i]; b != NULL; b = b->next) {
            vector_push(vec, b->value);
        }
    }

    return vec;
}

/* Frees set */
void set_free(set_t *set)
{
    if (set == NULL) {
        return;
    }

    for (size_t i = 0; i < set->size; i++) {
        free_bucket(set->array[i]);
    }
    free(set->array);
    free(set);
}
