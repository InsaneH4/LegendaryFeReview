#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} node;

typedef struct queue {
    node* front;
    node* back;
} queue;

// Initializes the queue pointed to by myQ to be an empty queue.
void initialize(queue* myQ) {
    myQ = (queue*)malloc(sizeof(queue));
    myQ->front = NULL;
    myQ->back = NULL;
}

// Enqueues the node pointed to by item into the queue pointed to by
// myQ.
void enqueue(queue* myQ, node* item) {
    if (myQ->front == NULL) {
        myQ->front = item;
        myQ->back = item;
    }
    else {
        myQ->back->next = item;
        myQ->back = item;
    }
}

// Removes and returns the front node stored in the queue pointed to
// by myQ. Returns NULL if myQ is empty.
node* dequeue(queue* myQ) {
    if (myQ->front == NULL) {
        return NULL;
    }
    else {
        node* temp = myQ->front;
        myQ->front = myQ->front->next;
        return temp;
    }
}

// Returns the number of items in the queue pointed to by myQ.
int size(queue* myQ) {
    int count = 0;
    node* temp = myQ->front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

queue* raulphMerge(queue* q1, queue* q2) {
    if (q1 == NULL) return q2;
    if (q2 == NULL) return q1;
    queue* q3;
    initialize(q3);
    while (q1 && q2 != NULL) {
        enqueue(q3->front->data, dequeue(q2->front->data));
        q2->front = q2->front->next;
        q3->front = q3->front->next;
        enqueue(q3->front->data, dequeue(q1->front->data));
        q1->front = q1->front->next;
        q3->front = q3->front->next;
    }
    if (q1 == NULL)
        while (q2 != NULL) {
            enqueue(q3->front->data, dequeue(q2->front->data));
            q3->front = q3->front->next;
        }
    else if (q2 == NULL)
        while (q1 != NULL) {
            enqueue(q3->front->data, dequeue(q1->front->data));
            q3->front = q3->front->next;
        }
    return q3;
}

queue* samMerge(queue* q1, queue* q2) {
    if (q1 == NULL && q2 == NULL) {
        return NULL;
    }

    if (q1 == NULL) {
        return q2;
    }

    if (q2 == NULL) {
        return q1;
    }

    queue* newQ;
    initialize(newQ);

    while (size(q1) != 0 && size(q2) != 0) {
        newQ->front = q1->front;
        q1->front = q1->front->next;
        newQ->front = q2->front;
        q2->front = q2->front->next;
    }

    if (size(q1) == 0) {
        newQ->front = q2->front;
    }

    if (size(q2) == 0) {
        newQ->front = q1->front;
    }

    return newQ;
}

void printQ(queue* myQ) {
    node* temp = myQ->front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    queue* q1, * q2, * q3;
    node* n1, * n2, * n3, * n4, * n5, * n6;
    n1 = (node*)malloc(sizeof(node));
    n1->data = 1;
    n2 = (node*)malloc(sizeof(node));
    n2->data = 2;
    n3 = (node*)malloc(sizeof(node));
    n3->data = 3;
    n4 = (node*)malloc(sizeof(node));
    n4->data = 4;
    n5 = (node*)malloc(sizeof(node));
    n5->data = 5;
    n6 = (node*)malloc(sizeof(node));
    n6->data = 6;
    initialize(q1);
    initialize(q2);
    q1->front = n1;
    q1->front->next = n2;
    q1->back = n3;
    q2->front = n4;
    q2->front->next = n5;
    q2->back = n6;
    q3 = samMerge(q1, q2);
    printQ(q3);
    return 0;
};
