
/*
    Generic hash set implementation
*/
#ifndef ILIB_SET_HEADER
#define ILIB_SET_HEADER

#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>

#include "ilib/vector.h"

typedef struct set_t set_t;

/* Constructs set */
set_t *set_new();

/* Adds a new value to the set, returns false if value already exits */
bool set_add(set_t *set, void *value);

/* Checks if set contians the specified value */
bool set_contains(set_t *set, void *value);

/* Returns number of elements in set */
size_t set_size(set_t *set);

/* Returs a vector containg all elements of the set */
vector_t *set_to_vector(set_t *set);

/* Frees hashset */
void set_free(set_t *set);

#endif /* ILIB_SET_HEADER */
