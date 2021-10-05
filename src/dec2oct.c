/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/dec2oct.h"

#include <stdlib.h>
#include <math.h>

int dec2oct_input_ok(long decimal);

/* converts a string of decimal digits to octal*/
long dtoo(long decimal)
{
    long result;
    int power;

    if(!dec2oct_input_ok(decimal))
        return -1;

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

int dec2oct_input_ok(long decimal)
{
    if(decimal > pow(2,32))
        return 0;

    if(decimal < 0)
        return 0;

    return 1;
}
