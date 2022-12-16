#include "ilib/list.h"

#include <stdio.h>
#include <stdlib.h>

list_t *list_new(void *data)
{
    list_t *list = calloc(1, sizeof(list_t));
    if (list == NULL) {
        return NULL;
    }
    list->data = data;
    list->prev = list->next = list;

    return list;
}

void list_free(list_t **list)
{
    list_t *head = *list;
    list_t *next = head;
    list_t *tmp;

    if (head == NULL) {
        return;
    }

    do {
        tmp  = next;
        next = next->next;
        free(tmp);
    } while (next != head);

    *list = NULL;
}

bool list_push(list_t **list, void *data)
{
    list_t *head = *list;
    list_t *new  = list_new(data);
    list_t *tmp;

    if (new == NULL) {
        return false;
    }

    if (head == NULL) {
        *list = new;
        return true;
    }

    tmp        = head->prev;  // previous last element
    tmp->next  = new;         // set new to last
    new->next  = head;        // make ciruclar reference to head
    new->prev  = tmp;         // set new to succed tmp
    head->prev = new;         // make ciruclar reference to new

    return true;
}

void *list_pop(list_t **list)
{
    list_t *head = *list;
    list_t *tmp;
    void   *data;

    if (head == NULL) {
        return NULL;
    }

    // 1 element in list;
    if (head == head->next) {
        *list = NULL;
    } else {
        tmp              = head->next;  // new head
        tmp->prev        = head->prev;  // tmp->prev = last
        head->prev->next = tmp;         // last->next = tmp
        *list            = tmp;         // set head
    }

    data = head->data;
    free(head);

    return data;
}

size_t list_size(list_t *list)
{
    list_t *head = list;
    list_t *next = head;
    size_t  size = 0;

    if (head == NULL) {
        return size;
    }

    do {
        size++;
        next = next->next;
    } while (next != head);

    return size;
}