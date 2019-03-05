#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

int* createArray(int len);
void validate(int* a, int* c, int l);
void testOne();
void testTwo();
void testThree();
void testSeven();
void testEight();
int main(void) {
    testOne();
    testTwo();
    testThree();
    testSeven();
    testEight();
}

int* createArray(int len) {
    int* a = malloc(sizeof(int)*len);
    if (a == NULL) assert(false);
    return a;
}

void validate(int* a, int* c, int l) {
    for (int i=0; i<l; i++) {
        if (a[i] != c[i]) assert(false);
    }
}

void testOne() {
    int l = 1;
    int* a = createArray(l);
    *a = 1;
    int* b = mergeSort(a, l);
    int* c = createArray(l);
    c[0] = 1;
    validate(b, c, l);
    free(a);
    free(b);
    free(c);
}

void testTwo() {
    int l = 2;
    int* a = createArray(l);
    a[0] = 2;
    a[1] = 1;
    int* b = mergeSort(a, l);
    int* c = createArray(l);
    c[0] = 1;
    c[1] = 2;
    validate(b, c, l);
    free(a);
    free(b);
    free(c);
}

void testThree() {
    int l = 3;
    int* a = createArray(l);
    a[0] = 4;
    a[1] = 2;
    a[2] = 5;
    int* b = mergeSort(a, l);
    int* c = createArray(l);
    c[0] = 2;
    c[1] = 4;
    c[2] = 5;
    validate(b, c, l);
    free(a);
    free(b);
    free(c);
}

void testSeven() {
    int l = 7;
    int* a = createArray(l);
    a[0] = 4;
    a[1] = 2;
    a[2] = 5;
    a[3] = 1;
    a[4] = 8;
    a[5] = 3;
    a[6] = 4;
    int* b = mergeSort(a, l);
    int* c = createArray(l);
    c[0] = 1;
    c[1] = 2;
    c[2] = 3;
    c[3] = 4;
    c[4] = 4;
    c[5] = 5;
    c[6] = 8;
    validate(b, c, l);
    free(a);
    free(b);
    free(c);
}

void testEight() {
    int l = 8;
    int* a = createArray(l);
    a[0] = 4;
    a[1] = 2;
    a[2] = 5;
    a[3] = 1;
    a[4] = 3;
    a[5] = 8;
    a[6] = 4;
    a[7] = 11;
    int* b = mergeSort(a, l);
    int* c = createArray(l);
    c[0] = 1;
    c[1] = 2;
    c[2] = 3;
    c[3] = 4;
    c[4] = 4;
    c[5] = 5;
    c[6] = 8;
    c[7] = 11;
    validate(b, c, l);
    free(a);
    free(b);
    free(c);
}
