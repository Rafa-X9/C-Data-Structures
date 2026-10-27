#include <stdio.h>
#include <stdlib.h>
#include "datastructures.h"

binarytree *binarytree_create() {
    binarytree *tree = malloc(sizeof(binarytree));
    if (tree == NULL) return NULL;
    tree->count = 0;
    tree->root = NULL;
    return tree;
}

void binarytree_add(binarytree *tree) {

}

void binarytree_print(binarytree *tree) {

}

void binarytree_destroy(binarytree *tree) {

}