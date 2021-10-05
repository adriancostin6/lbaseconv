/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/dec2hex.h"

#include <stdlib.h>
#include <math.h>

#include "lbaseconv/util/string.h"
#include "lbaseconv/util/ascii_hex.h"
#include "lbaseconv/util/invert_string.h"

int dec2hex_input_ok(long decimal);

string_t dtoh(long decimal)
{
    int i;
    long copy;
    int remainder;
    string_t result;

    if(!dec2hex_input_ok(decimal)) {
        result.data = NULL;
        result.len = 0;
        return result;
    }

    /* count numberatoi(s); of divisions */
    i = 0;
    copy = decimal;
    while(copy / 16 != 0) {
        ++i;
        copy /= 16;
    }
    ++i; /* null termination character */

    result = string_t_ctor(i);

    /* convert decimal to hex by division */
    i = 0;
    while(decimal / 16 != 0) { 
        insert_hex_char(result.data, decimal, i);
        decimal /= 16;
        ++i;
    }
    insert_hex_char(result.data, decimal, i);

    invert_string(result.data, result.len);

    return result;
}

/* inserts char in array based on value of hex num */
void insert_hex_char(char *s, long num, int pos)
{
    int remainder;

    remainder = num % 16;
    if (remainder < 10)
        s[pos] = remainder + '0';
    else
        s[pos] = get_ascii_hex(remainder);
}

ascii_hex_t get_ascii_hex(int n)
{
    switch(n){
        case 10:
            return HEX_A;
        case 11:
            return HEX_B;
        case 12:
            return HEX_C;
        case 13:
            return HEX_D;
        case 14:
            return HEX_E;
        case 15:
            return HEX_F;
    }
}

int dec2hex_input_ok(long decimal)
{
    if(decimal > pow(2,32))
        return 0;

    if(decimal < 0)
        return 0;

    return 1;
}
