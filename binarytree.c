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
    if (tree->root == NULL) {
        treenode *root = malloc(sizeof(treenode));
        root->item = item;
        root->left = NULL;
        root->right = NULL;
        tree->root = root;
        return;
    }

    for (treenode *node = tree->root; node != NULL;) {
        if (item < node->item) {
            if (node->left != NULL) {
                node = node->left;
                continue;
            }

            treenode *newnode = malloc(sizeof(treenode));
            newnode->item = item;
            newnode->left = NULL;
            newnode->right = NULL;
            node->left = newnode;
            return;
        }
        else {
            if (node->right != NULL) {
                node = node->right;
                continue;
            }

            treenode *newnode = malloc(sizeof(treenode));
            newnode->item = item;
            newnode->left = NULL;
            newnode->right = NULL;
            node->right = newnode;
            return;
        }
    }
}

void binarytree_print(binarytree *tree) {

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