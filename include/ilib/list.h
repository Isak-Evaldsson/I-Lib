/*
    Generic linked list implementation
*/
#ifndef ILIB_LIST_H
#define ILIB_LIST_H

#include <stdbool.h>

/**
 * @brief Generic linked list implementation, giving a broad range of methods for list manipulation.
 * Implements interator methods, allowing fast list iteration without exposing the internal list
 * implementation, similar to other languages with built in iterator support.
 */
typedef struct list_t list_t;

/**
 * Creates empty list
 * @return the new list
 */
list_t *list_empty();

/**
 * @brief Frees the memory of the list, however, it does not free the list contents
 */
void list_free(list_t *list);

/**
 * Adds element to end of list
 * @param list - the list to push to
 * @param data - the data to add to the list. Trying to add NULL elements will results in failure.
 * @returns if successful operations
 */
bool list_push(list_t *list, void *data);

/**
 * Pops element at the beginning of the list
 * @param list - the list to pop from
 * @returns the popped element, NUll if list is empty
 */
void *list_pop(list_t *list);

/**
 * @brief Resets list iterator and returns the first element of the list.
 * @param list - the list that's iterated
 * @returns the first element of the list, NULL if list is empty */
void *list_iter_begin(list_t *list);

/**
 * @brief Gives next element of the list
 * @param list - the list that's iterated
 * @returns the next element of the list, NULL if we have reached the end of the list
 */
void *list_iter_next(list_t *list);

/**
 * @brief Removes the element returned form the last iterator call (list_iter_next(...) or
 * list_iter_begin(...)). If called before list_iter_begin(...) or after we reached end of list,
 * undefined behavior.
 * @param list - the list that's iterated
 * @return the removed element
 */
void *list_iter_remove(list_t *list);

/**
 * @brief Inserts data before the element returned form the last iterator call (list_iter_next(...)
 * or list_iter_begin(...)). If called before list_iter_begin(...) or after we reached end of list,
 * undefined behavior.
 * @param list - the list that's iterated
 * @param data - the data to insert, trying to add NULL elements will results in failure.
 * @returns if insertion is successful
 */
bool list_iter_insert_before(list_t *list, void *data);

/**
 * @brief Inserts data after the element returned form the last iterator call (list_iter_next(...)
 * or list_iter_begin(...)). If called before list_iter_begin(...) or after we reached end of list,
 * undefined behavior.
 * @param list - the list that's iterated
 * @param data - the data to insert, trying to add NULL elements will results in failure.
 * @returns if insertion is successful
 */
bool list_iter_insert_after(list_t *list, void *data);

#endif /* ILIB_LIST_H */
