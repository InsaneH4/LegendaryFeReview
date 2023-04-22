#include <stdlib.h>
#include <stdio.h>

struct tree_node {
    int data;
    struct tree_node* left;
    struct tree_node* right;
};

struct tree_node* insert(struct tree_node* root, struct tree_node* element) {
    // Inserting into an empty tree.
    if (root == NULL)
        return element;
    else {
        // element should be inserted to the right.
        if (element->data > root->data) {
            // There is a right subtree to insert the node.            
            // Place the node directly to the right of root.
            root->right = insert(root->right, element);
        }
        // element should be inserted to the left.
        else {
            // There is a left subtree to insert the node.            
            // Place the node directly to the left of root.
            root->left = insert(root->left, element);
        }
        // Return the root pointer of the updated tree.
        return root;
    }
}

//pre order traversal function

void preOrder(struct tree_node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

int main(void) {
    struct tree_node* root = NULL;
    struct tree_node* element = NULL;
    for (int i = 0; i < 10; i++) {
        element = (struct tree_node*)malloc(sizeof(struct tree_node));
        element->data = i;
        element->left = NULL;
        element->right = NULL;
        root = insert(root, element);
    }
    preOrder(root);
    return 0;
}
