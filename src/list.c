#include "ilib/list.h"

#include <stdio.h>
#include <stdlib.h>

/*
    Internal data structures
*/
typedef struct list_node_t list_node_t;

struct list_node_t {
    void        *data;
    list_node_t *next;
    list_node_t *prev;
};

struct list_t {
    /* Pointers to start/end of list*/
    list_node_t *head;
    list_node_t *tail;

    // Current iterator object
    list_node_t *iter;
};

list_t *list_empty()
{
    list_t *list = calloc(1, sizeof(list_t));
    return list;
}

void list_free(list_t *list)
{
    list_node_t *node;
    list_node_t *next = list->head;

    // free list elements
    while (next != NULL) {
        node = next;
        next = next->next;
        free(node);
    }

    free(list);
}

bool list_push(list_t *list, void *data)
{
    list_node_t *new;

    if (data == NULL || (new = calloc(1, sizeof(list_node_t))) == NULL) {
        return false;
    }

    // prepend
    new->data  = data;
    new->next  = list->head;
    list->head = new;

    // set head = tail if list was previously empty
    if (list->tail == NULL) {
        list->tail = new;
    }

    return true;
}

void *list_pop(list_t *list)
{
    void        *data = NULL;
    list_node_t *node = list->tail;

    // Empty list
    if (node == NULL) goto end;

    // Single list entry
    if (node == list->head) {
        // make list empty
        list->head = (list->tail = NULL);
        goto end;
    }

    // Remove last object from list
    data             = node->data;
    node->prev->next = NULL;
    list->tail       = node->prev;

end:
    free(node);
    return data;
}

void *list_iter_begin(list_t *list)
{
    if (list->head == NULL) {
        return NULL;
    }

    list->iter = list->head;
    return list->iter->data;
}

void *list_iter_next(list_t *list)
{
    if (list->iter->next == NULL) {
        return NULL;
    }

    list->iter = list->iter->next;
    return list->iter->data;
}

void *list_iter_remove(list_t *list)
{
    list_node_t *node = list->iter;

    // handle first element/empty list/one item list
    if (list->head == node) return list_pop(list);

    // remove entry
    node->prev->next = node->next;
    node->next->prev = node->prev;

    free(node);
    return node->data;
}