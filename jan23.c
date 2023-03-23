#include <stdio.h>

//Section A

//Question 1

int getPascalsTriangle(int n) {
    int** tri = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        tri[i] = malloc(sizeof(int) * (i + 1));
        tri[i][0] = 1; tri[i][i] = 1;
    }
}

//Question 2

typedef struct node {
    char letter;
    struct node* next;
}node;

void printMixed(node* word1, node* word2) {
    node* temp1 = word1;
    node* temp2 = word2;
    while (temp1 != NULL && temp2 != NULL) {
        if (temp1 == NULL) {
            printf("%c", temp2->letter);
            temp2 = temp2->next;
        }
        if (temp2 == NULL) {
            printf("%c", temp1->letter);
            temp1 = temp1->next;
        }
        else {
            printf("%c", temp1->letter);
            printf("%c", temp2->letter);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
}
