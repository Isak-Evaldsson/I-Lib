/*
    Generic linked list implementation
*/
#ifndef ILIB_LIST_H
#define ILIB_LIST_H

#include <stdbool.h>
#include <stddef.h>

/**
 * @brief Generic circular doubly linked list
 */
typedef struct list_t list_t;

struct list_t {
    void   *data;
    list_t *next;
    list_t *prev;
};

/**
 * Creates new list containg one item
 * @param data the data to add to the list
 * @return the new list, NULL if failure
 */
list_t *list_new(void *data);

/**
 * @brief Frees the memory of the list, however, it does not free the list contents
 */
void list_free(list_t **list);

/**
 * Adds element to end of list
 * @param list - the list to push to
 * @param data - the data to add to the list. Trying to add NULL elements will results in failure.
 * @returns if successful operations
 */
bool list_push(list_t **list, void *data);

/**
 * Pops element at the beginning of the list
 * @param list - the list to pop from
 * @returns the popped element, NUll if list is empty
 */
void *list_pop(list_t **list);

/**
 * Gets numbers of elements in list
 */
size_t list_size(list_t *list);

#endif /* ILIB_LIST_H */
