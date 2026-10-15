#include <stdio.h>
#include <stdlib.h>
#include "datastructures.h"
#define INITIAL_LENGTH 10

stack *stack_create() {
    stack *stack = malloc(sizeof(stack));
    if (stack == NULL) return NULL;
    int *array = malloc(INITIAL_LENGTH * sizeof(int));
    if (array == NULL) {
        free(stack);
        return NULL;
    }

    stack->array = array;
    stack->count = 0;
    stack->capacity = 0;
    return stack;
}

int stack_pop(stack *stack) {

}

int stack_peek(stack *stack) {

}

int stack_push(stack *stack) {

}

void stack_print(stack *stack) {

}

void stack_destroy(stack *stack) {

}