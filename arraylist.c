#include <stdio.h>
#include <stdlib.h>
#include "datastructures.h"
#define INITIAL_SIZE 10

arraylist *arraylist_create() {
    arraylist *list = malloc(sizeof(arraylist));
    if (list == NULL) return NULL;

    list->array = malloc(INITIAL_SIZE * sizeof(int));
    if (list->array == NULL) {
        free(list);
        return NULL; 
    }

    list->count = 0;
    list->capacity = INITIAL_SIZE;
    return list;
}

void arraylist_ensurecapacity(arraylist *list) {
    if (list->count < list->capacity) return;

    int *newarray = realloc(list->array, (unsigned)list->capacity * (unsigned)2 * sizeof(int));
    if (newarray == NULL) return;

    list->array = newarray;
    list->capacity *= 2;
}

void arraylist_add(arraylist *list, int item) {
    list->array[list->count] = item;
    list->count++;
    arraylist_ensurecapacity(list);
}

void arraylist_print(const arraylist *list) {
    printf("[");
    for (int i = 0; i < list->count; i++) {
        printf("%i%s", list->array[i], (i == list->count - 1) ? "" : ", ");
    }
    printf("]");
}

void arraylist_destroy(arraylist *list) {
    free(list->array);
    free(list);
}