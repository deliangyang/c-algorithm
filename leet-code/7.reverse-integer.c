//
// Created by Administrator on 2019/4/1.
//


#include <stdio.h>
#include <math.h>

int reverse(int x) {
    long rev = 0;
    int tmp;

    while (x != 0) {
        tmp = x % 10;
        x /= 10;
        rev = rev * 10 + tmp;
    }
    if (rev > 2147483647 || rev < -2147483648) {
        return 0;
    }
    return rev;
}

int main(int argc, char* argv[]) {
    printf("len: %d\n", reverse(36469));
// 32121
    return 0;
}