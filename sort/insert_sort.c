//
// Created by Administrator on 2019/3/27.
//

#include <stdio.h>

void insert_sort() {

}

void bubble_sort(int *arr, int size) {
    int i, j, tmp;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - i; j++) {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(int argc, char* argv[])
{
    int arr[7] = {2, 3, 4, 5, 623, 234, 234};
    bubble_sort(arr, 7);
    int i;
    for (i = 0; i < 7; i++) {
        printf("arr[%d]:%d\n", i, arr[i]);
    }
    return 0;
}