#include <stdio.h>
#include <stdlib.h>

void printArr(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void print2D(int** arr, int size, int size2) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size2; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

//Fall 2018 Q1
int** makeArray(int* lengths, int numArrays) {
    if (lengths == NULL) {
        return NULL;
    }
    if (sizeof(lengths) / sizeof(int) != numArrays) {
        return NULL;
    }
    int** arr = (int**)calloc(numArrays, sizeof(int*));
    for (int i = 0; i < numArrays; i++) {
        arr[i] = (int*)calloc(lengths[i], sizeof(int));
    }
    return arr;
}

int main(void) {
    printf("\n1D Arrays\n\n");
    //declare array with size of 5    
    int arr1[5];
    for (int i = 0; i < 5; i++) {
        arr1[i] = i;
    }
    //array literal    
    int arr2[] = { 0, 1, 2, 3, 4 };
    int* arr3 = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) {
        arr3[i] = i;
    }
    printArr(arr1, sizeof(arr1) / sizeof(int));
    printArr(arr2, sizeof(arr2) / sizeof(int));
    printArr(arr3, sizeof(arr3) / sizeof(int));

    //2D array
    printf("\n2D Arrays\n\n");
    //Allocate space for the rows
    int** arr4 = (int**)malloc(5 * sizeof(int*));
    // int** arr5 = (int**)calloc(5, sizeof(int*));
    arr4[0] = (int*)malloc(10 * sizeof(int));
    free(arr4[0]);
    for (int i = 0; i < 5; i++) {
        //Allocate space for the columns
        arr4[i] = (int*)malloc(5 * sizeof(int));
        //Initialize each index to i * j
        for (int j = 0; j < 5; j++) {
            arr4[i][j] = i * j;
        }
    }
    print2D(arr4, 5, 5);

    //Free the memory
    free(arr3);
    //Free each row in the 2d array
    for (int i = 0; i < 5; i++) {
        free(arr4[i]);
    }
    //Free the array itself
    free(arr4);
    return 0;
}
