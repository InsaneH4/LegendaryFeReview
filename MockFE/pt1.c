#include <stdlib.h>

//Q1

typedef struct item {
    int x;
}item;

typedef struct inventory {
    int capacity;
    item* items;
} inventory;

typedef struct player {
    char* name;
    int level;
    int exp;
    inventory playerInventory;
} player;

player* newPlayer(char tempname[]) {
    player* p = (player*)malloc(sizeof(player));
    p->name = tempname;
    p->level = 1;
    p->exp = 0;
    p->playerInventory.capacity = 5;
    p->playerInventory.items = (item*)malloc(sizeof(item) * p->playerInventory.capacity);
    return p;
}

//Q2

typedef struct node {
    int data;
    struct node* next;
} node;

int findDivisibleSum(node* head, int k) {
    if (head == NULL) {
        return 0;
    }
    if (head->data % k == 0) {
        return head->data + findDivisibleSum(head->next, k);
    }
    return findDivisibleSum(head->next, k);
}
