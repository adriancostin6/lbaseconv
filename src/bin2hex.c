/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/bin2hex.h"

#include <stdlib.h>
#include <string.h>

#include "lbaseconv/util/string.h"
#include "lbaseconv/bin2int.h"

#define BINARY_GROUP_LENGTH 4
#define EMPTY_STRING 0

int check_input(const char *s);

/* converts binary string to hex; returns hex value as string*/
string_t btoh(const char *s)
{
    char hex_lut[] = "0123456789ABCDEF";

    int ret;
    int i, j, k;
    int in_len_old, in_len, out_len;
    int remainder;

    char *temp; /* temp char array used for input string processing */
    string_t result_str; /* output string */

    ret = check_input(s);
    if (ret == -1){
        result_str.data = NULL;
        result_str.len = EMPTY_STRING;
        return result_str;
    }

    in_len = strlen(s);

    /* accounts for prefix */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
        in_len -= 2;
        i = 2;
    } else i = 0;

    /* account for unequeal groups of bits; example 11 1111 -> 0011 1111*/
    remainder = in_len % 4; /* remainder determines the number of leading zeros we need to add*/
    if(remainder != 0){
        in_len_old = in_len;
        while(in_len % 4 != 0) in_len++;
        /* if we need ot add leading zeros, allocate temp string and add them*/
        temp = malloc(in_len * sizeof(char));
        strcpy(temp + in_len - in_len_old, s);
        for (j = 0; j < in_len - in_len_old; ++j)
            temp[j] = '0';
    } else {
        /* if no leading zeros, create temp string and simply copy */
        temp = malloc(in_len * sizeof(char));
        strcpy(temp, s);
    }

    /* allocate memory for output string*/
    out_len = in_len / 4;
    result_str = string_t_ctor(out_len);

    /* iterate over input string and get hex representation for each group of 4 bits */
    k = 0;
    while (i < in_len) {
        result_str.data[k] = get_hex(btoi(temp+i, BINARY_GROUP_LENGTH), hex_lut);
        i += BINARY_GROUP_LENGTH;
        ++k;
    }
    result_str.data[out_len] = '\0'; /* add null termination character */

    free(temp);

    return result_str;
}

/* return hex value for input integer */
char get_hex(int in, char *c) { return c[in]; }

int check_input(const char *s)
{
    int i;

    if (!s || !strcmp(s,""))
        return -1;

    for (i = 0; s[i] != '\0'; ++i)
        if (s[i] != '0')
            if(s[i] != '1')
                return -1;

    return 0;
}
