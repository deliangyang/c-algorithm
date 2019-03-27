#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int max(int x, int y)
{
    return x > y ? y : x;
}

int print(void *value) {
    printf("print value: %d\n", *((int *)value));
}

int main(int argc, char* argv[]) {
    int a = 1;
    int b = 2;
    int c = 3;
    printf("size of void *value: %ld\n", sizeof(void *));
    printf("size of struct: %ld\n", sizeof(struct list));
    struct list_tail lt = {0, NULL};

    list_insert(&lt, &a);
    printf("len: %d\n", lt.len);
    printf("len: %d\n", list_len(&lt));
    tail(&lt, &print);
    destroy(&lt);
    list_insert(&lt, &a);
    list_insert(&lt, &b);
    list_insert(&lt, &c);
    tail(&lt, &print);
    destroy(&lt);
    return 0;
}