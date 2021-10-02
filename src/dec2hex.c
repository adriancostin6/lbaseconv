/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/dec2hex.h"

#include <stdlib.h>

#include "lbaseconv/util/string.h"
#include "lbaseconv/util/ascii_hex.h"

string_t dtoh(int decimal)
{
    int i;
    int copy;
    char *result;
    int remainder;
    string_t str;

    copy = decimal;

    /* count numberatoi(s); of divisions */
    i = 0;
    while (copy / 16 != 0) {
        ++i;
        copy /= 16;
    }
    ++i; /* null termination character */

    /* allocate memory for result array */
    result = malloc(i * sizeof(char));
    result[i] = '\0'; /* add null termination character */

    /* convert decimal to hex by division */
    i = 0;
    while(decimal / 16 != 0) { 
        insert_hex_char(result, decimal, i);
        decimal /= 16;
        ++i;
    }
    insert_hex_char(result, decimal, i);

    str.data = result;
    str.len = i;

    return str;
}

/* inserts char in array based on value of hex num */
void insert_hex_char(char *s, int num, int pos)
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
