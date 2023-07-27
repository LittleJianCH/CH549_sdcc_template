#include "func.h"

void delay(int t) {
    while (t--);
}

__sbit reverse_bit(__sbit bit) {
    return !bit;
}
