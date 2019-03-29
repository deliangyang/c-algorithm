//
// Created by Administrator on 2019/3/27.
//

#include <stdio.h>

void insert_sort(int *arr, int l) {
    int i, tmp, j;
    for (i = 1; i < l; i++) {
        if (arr[i - 1] > arr[i]) {
            tmp = arr[i];
            j = i;
            while (j > 0 && tmp < arr[j - 1]) {
                arr[j] = arr[j - 1];
                j--;
            }
            arr[j] = tmp;
        }
    }
}

int binary_search(int *arr, int item, int l) {
    int left, right, mid;
    left = 0;
    right = l - 1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (item == arr[mid]) {
            return mid;
        } else if (item < arr[mid]) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int binary_search_recursion(int *arr, int item, int left, int right) {
    int mid = left + (right - left) / 2;
    if (left > right) {
        return -1;
    } else if (item > arr[mid]) {
        return binary_search_recursion(arr, item, mid + 1, right);
    } else if (item < arr[mid]) {
        return binary_search_recursion(arr, item, left, mid - 1);
    } else if (item == arr[mid]) {
        return mid;
    } else {
        return -1;
    }
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

void quick_sort_rc(int *arr, int left, int right) {
    int i, j, tmp, t;
    i = left;
    j = right;
    tmp = arr[left];

    if (left > right) {
        return;
    }

    while (i != j) {
        while (arr[j] >= tmp && i < j) j--;
        while (arr[i] <= tmp && i < j) i++;

        if (i < j) {
            t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    arr[left] = arr[i];
    arr[i] = tmp;

    quick_sort_rc(arr, left, i - 1);
    quick_sort_rc(arr, i + 1, right);
}

int main(int argc, char* argv[])
{
    int arr[] = {2, 23, 3, 4, 22, 7, 5, 623, 234, 234};
    int len = sizeof(arr) / sizeof(int);
    quick_sort_rc(arr, 0, len - 1);
    int i;
    for (i = 0; i < len; i++) {
        printf("arr[%d]:%d\n", i, arr[i]);
    }

    for (i = 0; i < len; i++) {
        printf("result index: arr[%d] = %d => %d\n", i, arr[i], binary_search_recursion(arr, arr[i], 0, len));
    }
    return 0;
}