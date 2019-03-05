#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

/*
    divide the unsorted list into n sublists, each containing one element
    repeatedly merge the sublists to produce new sorted sublists until there is
    only one sublist remaining.  this list will be sorted.
*/
#define SIZE 7
void printList(int* ptr);
int* mergeSort(int* ptr, int len);
int* merge(int* ptr0, int* ptr1, int ptr0L, int ptr1L);
int main(void) {
    int list[SIZE] = {4,3,7,1,3,2,8};
    printList(list);
    int* new = mergeSort(list, SIZE);
    printf("\n");
    printList(new);
}
void printList(int* ptr){
    int i;
    for (i=0; i<SIZE; i++) {
        printf("%i\n", ptr[i]);
    }
}

