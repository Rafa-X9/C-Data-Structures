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

void binarytree_add(binarytree *tree, int item) {
    treenode **nullnode = &tree->root;

    while (*nullnode != NULL) {
        if (item < (*nullnode)->item) {
            nullnode = &(*nullnode)->left;
        }
        else {
            nullnode = &(*nullnode)->right;
        }
    }

    //nullnode points to a pointer to the null node
    treenode *newnode = malloc(sizeof(treenode));
    newnode->item = item;
    newnode->left = NULL;
    newnode->right = NULL;
    *nullnode = newnode;
    tree->count++;
}

void treenode_print(treenode *node) {
    if (node == NULL) return;
    treenode_print(node->left);
    printf("%i ", node->item);
    treenode_print(node->right);
}

void binarytree_print(binarytree *tree) {
    treenode_print(tree->root);
    printf("\n");
}

void treenode_destroy(treenode *node) {
    if (node == NULL) return;
    treenode_destroy(node->left);
    treenode_destroy(node->right);
    free(node);
}

void binarytree_destroy(binarytree *tree) {
    treenode_destroy(tree->root);
    free(tree);
}