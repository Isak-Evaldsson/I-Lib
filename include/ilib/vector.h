#ifndef ILIB_VECTOR_H
#define ILIB_VECTOR_H

#include <stddef.h>

/**
 * Simple expandable array, allows pushing new elements but not deletion,
 * ideal for when you simply need an arbitrary long array that you can iterate
 * over/access by index
 */
typedef struct vector_t vector_t;

/**
 * Allocates a new vector
 * @returns pointer to the new vector, NULL on failure
 */
vector_t *vector_new();

/**
 * Frees the vector and its array.
 * @param vec the vector, does nothing if NULL (as all proper free methods should)
 */
void vector_free(vector_t *vec);

/**
 * Get size for a give vector
 * @param vec the vector
 * @returns the numbers of elements in array.
 */
size_t vector_size(vector_t *vec);

/**
 * Added element to end of array, resize the underlying array if necessary
 * @param vec the vector
 * @param data the data to insert
 * @returns the index for the newly inserted element, -1 on failure
 */
size_t vector_push(vector_t *vec, void *data);

/**
 * Gets the element at a certain index
 * @param vec the vector
 * @param index the index
 * @returns the element, NULL on failure
 */
void *vector_get(vector_t *vec, size_t index);

/**
 * Gets a pointer to the start of the array and stores the size in the supplied
 * pointer, allowing easy iteration
 * @param vec the vector
 * @param size pointer to store the array size
 * @returns the index for the newly inserted element, -1 on failure
 */
void **vector_array_ptr(vector_t *vec, size_t *size);

#endif /* ILIB_VECTOR_H */