//
// Created by Administrator on 2019/4/2.
//

#include <stdio.h>
#include <string.h>

int strStr(char* haystack, char* needle) {
    int i = 0, j = 0;
    while (haystack[i] != '\0' && needle[j] != '\0') {
        if (haystack[i] == needle[j]) {
            i++; j++;
        } else {
            i = i - j + 1;
            j = 0;
        }
    }
    if (needle[j] == '\0') {
        return i - j;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    printf("aa: %d\n", strStr("basdf", "sdf"));
    return 0;
}