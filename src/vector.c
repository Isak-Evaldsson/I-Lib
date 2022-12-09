#include "ilib/vector.h"

#include <stdlib.h>

#define INITAL_CAPACITY 10

struct vector_t {
    size_t capacity;
    size_t size;
    void **array;
};

vector_t *vector_new()
{
    vector_t *vec = vec = calloc(1, sizeof(vector_t));
    if (vec == NULL) return NULL;

    vec->array = calloc((vec->capacity = INITAL_CAPACITY), sizeof(void *));
    if (vec->array == NULL) {
        free(vec);
        return NULL;
    }

    return vec;
}

void vector_free(vector_t *vec)
{
    free(vec->array);
    free(vec);
}

size_t vector_push(vector_t *vec, void *data)
{
    if (vec->size >= vec->capacity) {
        vec->array = realloc(vec->array, (vec->capacity *= 2) * sizeof(void *));
        if (vec->array == NULL) {
            return -1;
        }
    }
    size_t index      = vec->size++;
    vec->array[index] = data;
    return index;
}

size_t vector_size(vector_t *vec)
{
    return vec->size;
}

void *vector_get(vector_t *vec, size_t index)
{
    if (index >= vec->size) return NULL;

    return vec->array[index];
}

void **vector_array_ptr(vector_t *vec, size_t *size)
{
    *size = vec->size;
    return vec->array;
}