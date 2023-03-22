#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*2) (10 pts) DSN (Linked Lists)
Suppose we have a singly linked list implemented with the structure below.
Write a function that will convert it into a circular linked list and return
the pointer to the beginning of the circle. */
typedef struct node {
    int num;
    struct node* next;
}node;

struct node* make_circle(struct node* head) {
    node* temp = head;
    if (temp == NULL)
        return head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = head;
    return head;
}

/*) (10 pts) DSN (Dynamic Memory Management in C)
Suppose we have a stack implemented with an array as shown in the structure below.
Write a function called grow_stack that will increase the stack’s capacity while
preserving the exact values currently in the stack and their current locations.
Your function should take 2 parameters: a pointer to the current stack
and an integer representing the amount to increase the stack’s capacity by. You may
not use the realloc function. You may assume s isn't NULL and pts to a valid struct
stack. You may assume that capacity stores the current size of the array that the
pointer array is pointing to and that top represents the number of items currently in
the stack (items are stored in indexes 0 through top-1).*/

typedef struct Stack {
    int* array;
    int top;
    int capacity;
}Stack;

void grow_stack(struct Stack* s, int increase) {
    //Increase capacity of stack
    s->capacity += increase;
    //Allocate space for new array
    int* newArr = (int*)calloc(s->capacity, sizeof(int));
    //Copies data from old array into new array
    for (int i = 0; i < s->capacity - increase; i++) {
        newArr[i] = s->array[i];
    }
    //get rid of old array
    free(s->array);
    //set array in the stack to new array
    s->array = newArr;
}
//prints whats in the array
void printArray(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    //initializes the stack
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->capacity = 3;
    stack->array = (int*)malloc(sizeof(int) * stack->capacity);
    stack->array[0] = 1; stack->array[1] = 2; stack->array[2] = 3;
    printArray(stack->array, stack->capacity);
    //calls our function
    grow_stack(stack, 2);
    //initialize newly created space
    stack->array[3] = 4; stack->array[4] = 5;
    //prints the array with new size 
    printArray(stack->array, stack->capacity);
    return 0;

}
