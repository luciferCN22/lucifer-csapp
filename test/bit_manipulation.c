#include<stdlib.h>
#include<stdio.h>

// 力扣T307
uint64_t leastBitPos(uint64_t x) {
    // opposite(x) = 1 + (~x)
    // lowBit(x) = x & (-x)
    return x & (1 + (~x));
}

uint64_t hexAllLetters(uint64_t x) {
    uint64_t x1 = (x & 0x2222222222222222) >> 1;
    uint64_t x2 = (x & 0x4444444444444444) >> 2;
    uint64_t x3 = (x & 0x8888888888888888) >> 3;

    x = x3 & (x1 | x2);
    x = x & (x >> 32);
    x = x & (x >> 16);
    x = x & (x >>  8);
    x = x & (x >>  4);
    return x;
}

uint64_t bitCount(uint64_t x) {
    uint64_t c;
    c = (x & 0x5555555555555555) + ((x >>  1) & 0x5555555555555555);
    c = (c & 0x3333333333333333) + ((c >>  2) & 0x3333333333333333);
    c = (c & 0x0f0f0f0f0f0f0f0f) + ((c >>  4) & 0x0f0f0f0f0f0f0f0f);
    c = (c & 0x00ff00ff00ff00ff) + ((c >>  8) & 0x00ff00ff00ff00ff);
    c = (c & 0x0000ffff0000ffff) + ((c >> 16) & 0x0000ffff0000ffff);
    c = (c & 0x00000000ffffffff) + ((c >> 32) & 0x00000000ffffffff);
    return c;
}

int main(){
    printf("%llu",bitCount(0x2));
    return 0;
}