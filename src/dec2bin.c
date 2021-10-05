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

int dtob_input_ok(long decimal);
int dec2bin_input_ok(const char *s, size_t len);

/* converts a string of decimal digits to binary */
string_t dec2bin(const char *s, size_t len)
{
    string_t result;

    if (!dec2bin_input_ok(s, len)) {
        result.data = NULL;
        result.len = 0;
        return result;
    }

    result = dtob(atol(s));
    return result;
}

/* converts a decimal number to a binary string */
string_t dtob(long decimal)
{
    int i;
    long copy;
    string_t result;

    if(!dtob_input_ok(decimal)){
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

int dtob_input_ok(long decimal)
{
    if(decimal > pow(2,32))
        return 0;

    if(decimal < 0)
        return 0;

    return 1;
}

int dec2bin_input_ok(const char *s, size_t len)
{
    int i;

    if (!s || len == 0 || *s == '\0')
        return 0;

    for (i = 0; s[i] != '\0'; ++i)
        if(s[i] - '0' > 9 || s[i] - '0' < 0)
            return 0;
    
    return 1;
}
