#include <assert.h>
#include <stddef.h>
#include <stdio.h>

#include "ilib.h"

void vec_test()
{
    printf("Vector tests\n");

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
    printf("Success tests\n");
}

int main()
{
    vec_test();
    // Test elements
    // int count = 0;
    // int e[] = {1, 2, 3};

    // list_t *list = list_empty();
    // list_push(list, e);
    // list_push(list, e + 1);
    // list_push(list, e + 2);

    // printf("Test %d\n", count);

    // for (int *elem = list_iter_begin(list); elem != NULL; list_iter_next(list))
    // {
    //     printf("Elem %d\n", *elem);
    //     // assert(*elem == e[count]);
    //     count++;
    // }

    // // list_pop(list);
    // // list_pop(list);
    // // list_pop(list);
    // list_free(list);
}