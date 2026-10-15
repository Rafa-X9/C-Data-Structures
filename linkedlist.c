#include <stdio.h>
#include <stdlib.h>
#include "datastructures.h"

linkedlist *linkedlist_create() {
    linkedlist *list = malloc(sizeof(linkedlist));
    if (list == NULL) return NULL;

    list->count = 0;
    list->first = NULL;
    list->last = NULL;
    return list;
}

void linkedlist_add(linkedlist *list, int item) {

}

void linkedlist_print(const linkedlist *list) {

}

void linkedlist_destroy(linkedlist *list) {

}