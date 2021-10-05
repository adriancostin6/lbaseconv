/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/dec2bin.h"

#include <stdlib.h>
#include <math.h>

#include "lbaseconv/util/string.h"

int dec2bin_input_ok(long decimal);

/* converts a string of decimal digits to binary */
/* TODO - make a frontend to the dtob function, takes a string a input*/

/* converts a decimal number to a binary string */
string_t dtob(long decimal)
{
    int i;
    long copy;
    string_t result;

    /* TODO - Add support for negative numbers */

    if(!dec2bin_input_ok(decimal)){
        result.data = NULL;
        result.len = 0;
        return result;
    }

    /* count number of divisions */
    i = 0;
    copy = decimal;
    while (copy / 2 != 0) {
        ++i;
        copy /= 2;
    }
    ++i; /* null termination character */

    /* allocate memory for result string */
    result = string_t_ctor(i);

    /* convert decimal to binary by division */
    i = 0;
    while(decimal / 2 != 0) { 
        insert_binary_char(result.data, decimal, i);
        decimal /= 2;
        ++i;
    }
    insert_binary_char(result.data, decimal, i);

    return result;
}

/* inserts binary char in string based on value of decimal num */
void insert_binary_char(char *s, long num, int pos)
{
    int remainder;

    remainder = num % 2;
    s[pos] = remainder + '0';
}

int dec2bin_input_ok(long decimal)
{
    if(decimal > pow(2,32))
        return 0;

    if(decimal < 0)
        return 0;

    return 1;
}
