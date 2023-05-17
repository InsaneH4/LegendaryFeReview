#include <stdlib.h>
#include<stdio.h>

typedef struct treenode {
    char ch;
    struct treenode* left;
    struct treenode* right;
} treenode;

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

int isConsonant(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 0;
    }
    return 1;
}

void printPassword(treenode* root) {
    if (root == NULL) {
        return;
    }

    printPassword(root->left);
    if (isConsonant(root->ch)) {
        printf("%c", root->ch);
    }
    printPassword(root->right);
}

int legacyCount(node* root) {
    if (root == NULL) return 0;

    return legacyHelper(root->left, root->data) +
        legacyHelper(root->right, root->data);
}

int legacyHelper(node* root, int minAncestor) {
    if (root == NULL) return 0;

    if ((root->right != NULL && root->right->data > root->data) ||
        (root->left != NULL && root->left->data > root->data)) {
        return 1;
    }

    return 0;
}
