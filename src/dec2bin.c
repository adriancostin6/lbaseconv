/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/dec2bin.h"

#include <stdlib.h>

#include "lbaseconv/util/string.h"

/* converts a string of decimal digits to binary */
string_t dtob(int decimal)
{
    int i;
    int copy;
    char *result;
    int remainder;
    string_t str;

    copy = decimal;

    /* count number of divisions */
    i = 0;
    while (copy / 2 != 0) {
        ++i;
        copy /= 2;
    }
    ++i; /* null termination character */

    /* allocate memory for result array */
    result = malloc(i * sizeof(char));
    result[i] = '\0'; /* add null termination character */

    /* convert decimal to binary by division */
    i = 0;
    while(decimal / 2 != 0) { 
        insert_binary_char(result, decimal, i);
        decimal /= 2;
        ++i;
    }
    insert_binary_char(result, decimal, i);

    str.data = result;
    str.len = i;

    return str;
}

/* inserts binary char in string based on value of decimal num */
void insert_binary_char(char *s, int num, int pos)
{
    int remainder;

    remainder = num % 2;
    s[pos] = remainder + '0';
}
