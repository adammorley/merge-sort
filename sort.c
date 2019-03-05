#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

#include "sort.h"

/*
    take a pointer to range of memory with integers, and the length of the location
    perform a merge sort
*/
int* mergeSort(int* ptr, int len) {
    if (len==1 || len==0) return ptr;
    int frontLen = len/2, backLen = len/2; // even case
    if (len%2 != 0) { // not even, have to handle odd case
        frontLen = len/2 + 1;
        backLen = len/2;
    }
    int* front = malloc(sizeof(int)*frontLen);
    int* back = malloc(sizeof(int)*backLen);
    for (int i=0; i<frontLen;i++) {
        front[i] = ptr[i];
    }
    int j=0;
    for (i=frontLen; i<len; i++) {
        back[j] = ptr[i];
        j++;
    }
    free(ptr);
    return merge(mergeSort(front, frontLen), mergeSort(back, backLen), frontLen, backLen);
}
/*
    merge the pieces together by iterating
*/
int* merge(int* ptr0, int* ptr1, int ptr0L, int ptr1L){
    int size = ptr0L + ptr1L;
    int* new = malloc(sizeof(int)*size);
    int i = 0, 0i = 0, 1i = 0;
    for (i=0; i<size; i++) {
        if (0i >= ptr0L) {
            new[i] = ptr1[1i];
            1i++;
        } else if (1i >= ptr1L) {
            new[i] = ptr0[0i];
            0i++;
        } else if (ptr0[0i] < ptr1[1i]) {
            new[i] = ptr0[0i];
            0i++;
        } else if (ptr0[0i] >= ptr1[1i]) {
            new[i] = ptr1[1i];
            1i++;
        } else assert(true);
    }
    free(ptr0);
    free(ptr1);
    return new;
}
