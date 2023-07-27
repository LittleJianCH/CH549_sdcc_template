#include <CH549_sdcc.h>

SBIT(led, 0x90, 0);

#include "func.h"

int main() {
    while (true) {
        led = reverse_bit(led);
        delay(50000);
    }

    return 0;
}
