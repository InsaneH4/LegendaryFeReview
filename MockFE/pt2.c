#include <stdlib.h>

//Q1

//Given a binary tree and two integers low and high, return the product of all values 
//NOT in the range [low, high]. (Hint: In the case of an empty tree, return 1.)

typedef struct treenode {
    int data;
    struct treenode* left;
    struct treenode* right;
} treenode;

int findProduct(treenode* root, int low, int high) {
    if (root == NULL) {
        return 1;
    }
    if (root->data > low && root->data < high) {
        return root->data * findProduct(root->left, low, high);
        return root->data * findProduct(root->right, low, high);
    }
    return findProduct(root->left, low, high);
    return findProduct(root->right, low, high);
}
