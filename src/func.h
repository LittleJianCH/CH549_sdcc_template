#ifndef FUNC_H

#define FUNC_H

#include <CH549_sdcc.h>

#define delay(ms) \
    do { \
        for (int i = 1, e = (ms); i <= e; i++) { \
            for (int j = 1; j <= 1199; j++); \
        } \
    } while (0)

BOOL reverse_bool(BOOL bool);

#endif
