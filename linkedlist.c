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
    if (list->first == NULL) {
        listnode *first = malloc(sizeof(listnode));
        if (first == NULL) return;

        first->item = item;
        first->next = NULL;
        first->previous = NULL;
        
        list->first = first;
        list->last = first;
        list->count++;
        return;
    }

    listnode *last = malloc(sizeof(listnode));
    if (last == NULL) return;
    last->item = item;
    last->next = NULL;
    last->previous = list->last;
    list->last->next = last;
    list->last = last;
    list->count++;
}

int linkedlist_remove(linkedlist *list, int item) {
    for (listnode *temp = list->first; temp != NULL; temp = temp->next) {
        if (temp->item != item) continue;
        
        if (temp->previous != NULL) {
            temp->previous->next = temp->next;
        }
        else {
            list->first = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->previous = temp->previous;
        }
        else {
            list->last = temp->previous;
        }

        free(temp);
        list->count--;
        return TRUE;
    }

    return FALSE;
}

int linkedlist_removelast(linkedlist *list, int item) {
    for (listnode *temp = list->last; temp != NULL; temp = temp->previous) {
        if (temp->item != item) continue;
        
        if (temp->previous != NULL) {
            temp->previous->next = temp->next;
        }
        else {
            list->first = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->previous = temp->previous;
        }
        else {
            list->last = temp->previous;
        }

        free(temp);
        list->count--;
        return TRUE;
    }

    return FALSE;
}

int linkedlist_removeall(linkedlist *list, int item) {
    int count = 0;

    for (listnode *temp = list->last; temp != NULL; temp = temp->previous) {
        if (temp->item != item) continue;
        
        if (temp->previous != NULL) {
            temp->previous->next = temp->next;
        }
        else {
            list->first = temp->next;
        }

        if (temp->next != NULL) {
            temp->next->previous = temp->previous;
        }
        else {
            list->last = temp->previous;
        }

        free(temp);
        list->count--;
    }

    return count;
}

void linkedlist_print(const linkedlist *list) {
    printf("[");

    for (listnode *temp = list->first; temp != NULL; temp = temp->next) {
        printf("%i", temp->item);
        if (temp->next != NULL) printf(", ");
    }

    printf("]");
}

void linkedlist_destroy(linkedlist *list) {
    for (listnode *temp = list->first; temp != NULL;) {
        listnode *next = temp->next;
        free(temp);
        temp = next;
    }
    free(list);
}