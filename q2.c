#include <stdlib.h>

struct queue {
    int* array;
    int num_elements;
    int front;
    int capacity;
};

int dequeue(struct queue* q) {
    if (q == NULL) {
        return 0;
    }
    int deQ = q->array[q->front];
    q->front = (q->front + 1) % q->capacity;
    return deQ;
}
