#include <stdio.h>
#include <string.h>

void bubbleSort(int* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void printArr(int* arr, int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

typedef struct student {
    char first[20];
    char last[20];
    int ID;
} student;

void sort(student** list, int len) {
    int i, j;
    for (i = len - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (cmp(list[j], list[j + 1]) > 0) {
                student* tmp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = tmp;
            }
        }
    }
}

int cmp(student* a, student* b) {
    if (a == NULL || b == NULL) {
        return 0;
    }

    int fnCmp = strcmp(a->first, b->first);
    int lnCmp = strcmp(a->last, b->last);
    int idCmp = a->ID - b->ID;

    if (fnCmp == 0 && lnCmp == 0) {
        return idCmp;
    }

    if (fnCmp == 0) {
        return lnCmp;
    }

    return fnCmp;
}

int main(void) {
    int array[] = { 5, 2, 7, 1, 0, 9, 13, 3, 4, 20 };
    printArr(array, 10);
    bubbleSort(array, 10);
    printArr(array, 10);
    return 0;
}
