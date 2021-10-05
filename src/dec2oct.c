/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/dec2oct.h"

#include <stdlib.h>
#include <math.h>

int dec2oct_input_ok(const char *s, size_t len);
int dtoo_input_ok(long decimal);

long dec2oct(const char *s, size_t len)
{
    long result;

    if (!dec2oct_input_ok(s, len)){
        return -1;
    }

    result = dtoo(atol(s));
    return result;
}

/* converts a string of decimal digits to octal*/
long dtoo(long decimal)
{
    long result;
    int power;

    if(!dtoo_input_ok(decimal))
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

int dec2oct_input_ok(const char *s, size_t len)
{
    int i;

    if (!s || len == 0 || *s == '\0')
        return 0;

    for (i = 0; s[i] != '\0'; ++i)
        if(s[i] - '0' > 9 || s[i] - '0' < 0)
            return 0;
    
    return 1;
}

int dtoo_input_ok(long decimal)
{
    if(decimal > pow(2,32))
        return 0;

    if(decimal < 0)
        return 0;

    return 1;
}

