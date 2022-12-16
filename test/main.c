#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include "ilib.h"

void vec_test_fill()
{
    printf("Fill array...");
    size_t    i, j;
    int     **ptr;
    int       data[100];
    size_t    count = sizeof(data) / sizeof(data[0]);
    vector_t *vec   = vector_new();

    for (i = 0; i < count; i++) {
        data[i] = i;
        vector_push(vec, data + i);
    }

    ptr = (int **)vector_array_ptr(vec, &j);
    for (i = 0; i < j; i++) {
        assert(*ptr[i] == data[i]);
    }
    assert(i == count);
    vector_free(vec);
    printf("Success\n");
}

void list_test_push_pop()
{
    size_t n;
    int    e[] = {1, 2, 3};

    list_t *list = NULL;

    printf("Push and pop...");

    // Initial insert
    list_push(&list, e);
    assert(list->next = list);
    assert(list->prev = list);

    list_push(&list, e + 1);
    list_push(&list, e + 2);
    assert(list->next->next = list);
    assert(list->next->next = list->prev);
    assert((n = list_size(list)) == 3);

    for (int i = 0; i < n; i++) {
        int *elem = list_pop(&list);
        assert(*elem == e[i]);
    }

    // List should be empty efter poping
    assert(list == NULL);
    printf("Success\n");
}

void list_test_free()
{
    printf("Free list...");
    list_t *list = NULL;
    size_t  n    = 100;

    for (size_t i = 0; i < n; i++) {
        list_push(&list, NULL);
    }
    assert(list_size(list) == n);
    list_free(&list);
    assert(list == NULL);

    printf("Success\n");
}

int main()
{
    printf("Vector tests:\n");
    vec_test_fill();

    printf("\nList tests:\n");
    list_test_push_pop();
    list_test_free();
}