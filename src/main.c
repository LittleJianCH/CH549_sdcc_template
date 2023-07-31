#include <CH549_sdcc.h>
#include <CH549_pwm.h>

#include "func.h"

#define led P2_2
#define key1 P3_2 

void Int0Init() {
    IT0 = 1;
    EX0 = 1;
    EA = 1;
}

BOOL state = 0;
void Int0() __interrupt(0) {
    delay(10);
    if (!key1) {
        state = reverse_bool(state);
    }
}

void PWM3Init() {
    SetPWMClkDiv(4);
    SetPWMCycle256Clk();
    PWM_SEL_CHANNEL(CH3, Enable);
}

void main() {
    Int0Init();
    PWM3Init();

    while (true) {
        for (int i = 0; i <= 256; i++) {
            SetPWM3Dat(state ? i : 0);
            delay(1);
        }

        for (int i = 255; i >= 0; i--) {
            SetPWM3Dat(state ? i : 0);
            delay(1);
        }
    }
}
