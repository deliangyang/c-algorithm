//
// Created by Administrator on 2019/4/1.
//

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
    if (s == NULL) {
        return 0;
    }

    int res = 0;
    int last = 0;
    int i = 0;
    int j;
    int len = strlen(s);
    for (; i < len; i++) {
        j = i + 1;
        for (; j < len; j++) {
            printf("a:%c\t%c, i:j: %d\t%d\n", s[i], s[j], i, j);
            if (s[i] != s[j]) {
                res++;
            } else {
                printf("xxxxx: %d\t%d\n", res, last);
                if (res > last) {
                    last = res;
                }
                res = 0;
                break;
            }
        }
        if (i == len) {
            break;
        }
        i++;
    }
    return last + 1;
}

int main(int argc, char* argv[]) {
    printf("length: %d\n", lengthOfLongestSubstring("abcabcbb"));
    printf("length: %d\n", lengthOfLongestSubstring("bbbbb"));
    printf("length: %d\n", lengthOfLongestSubstring("pwwkew"));
    return 0;
}