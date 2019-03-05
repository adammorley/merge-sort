#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "sort.h"

int* merge(int* ptr0, int* ptr1, int ptr0L, int ptr1L);
/*
    take a pointer to range of memory with integers, and the length of the location
    perform a merge sort
*/
int* mergeSort(int* ptr, int len) {
    if (len==1 || len==0) return ptr;
    int fL = len/2, bL = len/2; // even case
    if (len%2 != 0) { // not even, have to handle odd case
        fL = len/2 + 1;
        bL = len/2;
    }
    int* front = calloc(fL, sizeof(int));
    int* back = calloc(bL, sizeof(int));
    int i;
    for (i=0; i<fL;i++) {
        front[i] = ptr[i];
    }
    int j=0;
    for (i=fL; i<len; i++) {
        back[j] = ptr[i];
        j++;
    }
    free(ptr);
    return merge(mergeSort(front, fL), mergeSort(back, bL), fL, bL);
}
/*
    merge the pieces together by iterating
*/
int* merge(int* ptr0, int* ptr1, int ptr0L, int ptr1L){
    int size = ptr0L + ptr1L;
    int* new = calloc(size, sizeof(int));
    int i = 0, j = 0, k = 0;
    for (i=0; i<size; i++) {
        if (j >= ptr0L) {
            new[i] = ptr1[k];
            k++;
        } else if (k >= ptr1L) {
            new[i] = ptr0[j];
            j++;
        } else if (ptr0[j] < ptr1[k]) {
            new[i] = ptr0[j];
            j++;
        } else if (ptr0[j] >= ptr1[k]) {
            new[i] = ptr1[k];
            k++;
        } else assert(false);
    }
    free(ptr0);
    free(ptr1);
    return new;
}
