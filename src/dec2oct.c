/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/dec2oct.h"

#include <stdlib.h>
#include <math.h>

/* converts a string of decimal digits to octal*/
int dtoo(int decimal)
{
    int result;
    int power;

    /* convert decimal to octal by division */
    power = result = 0;
    while(decimal / 8 != 0) {
        result += decimal % 8 * pow(10, power);
        decimal /= 8;
        ++power;
    }
    result += decimal % 8 * pow(10,power);
    return result;
}
