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

void ensure_capacity(stack *stack) {
    if (stack->count < stack->capacity) return;
    int *newArray = realloc(stack->array, stack->capacity * 2 * sizeof(int));
    if (newArray == NULL) return;
    stack->capacity *= 2;
}

int stack_pop(stack *stack) {
    if (stack->count == 0) {
        perror("Error: tried to pop from an empty stack.");
        return 0;
    }
    int item = stack->array[stack->count - 1];
    stack->count--;
    return item;
}

int stack_peek(stack *stack) {
    if (stack->count == 0) {
        perror("Error: tried to peek from an empty stack.");
        return 0;
    }
    int item = stack->array[stack->count - 1];
    return item;
}

void stack_push(stack *stack, int item) {
    ensure_capacity(stack);
    stack->array[stack->count] = item;
    stack->count++;
}

void stack_print(stack *stack) {
    printf("[");
    for (int i = 0; i < stack->count; i++) {
        printf("%i", stack->array[i]);
        if (i != stack->count - 1) printf(", ");
    }
    printf("]");
}

void stack_destroy(stack *stack) {
    free(stack->array);
    free(stack);
}