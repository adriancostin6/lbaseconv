/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/bin2oct.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "lbaseconv/util/string.h"

#define BINARY_GROUP_LENGTH_OCT 3

/* converts binary string to octal; returns octal string*/
string_t btoo(const char *s)
{
    int i, k, j;
    int prev_in_len ,in_len, out_len;

    char *temp; /* temp char array used for input string processing */
    string_t result_str; /* output string */

    in_len = strlen(s);

    /* accounts for prefix */
    if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B')){
        in_len -= 2;
        i = 2;
    } else i = 0;


    /* set up grouping conversion algorithm by making the number of bits a multiple of 3 */
    prev_in_len = in_len;
    while(in_len % BINARY_GROUP_LENGTH_OCT != 0) in_len++;

    /* allocate memory and copy input bit string */
    temp = malloc(in_len * sizeof(char));
    strcpy(temp + in_len - prev_in_len, s);
    for (j = 0; j < in_len - prev_in_len; ++j)
        temp[j] = '0';

    /* allocate memory for output string*/
    out_len = in_len / BINARY_GROUP_LENGTH_OCT;
    result_str = string_t_ctor(out_len);

    /* iterate over input string and get octal representation for each group of 3 bits */
    k = 0;
    while (i < in_len) {
        result_str.data[k] = bin2oct(temp+i) + '0';
        i += 3;
        ++k;
    }
    result_str.data[out_len] = '\0'; /* add null termination character */

    free(temp);

    return result_str;
}

/* return octal value from groups of 3 binary bits*/
int bin2oct(char *in)
{
    int i;
    int power;
    int result;

    power = BINARY_GROUP_LENGTH_OCT - 1;
    result = 0;
    for (i = 0; i < BINARY_GROUP_LENGTH_OCT; ++i){
        if(in[i] - '0')
            result += pow(2,power);
        --power;
    }
    return result;
}
