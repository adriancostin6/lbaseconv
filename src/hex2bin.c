/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#include "lbaseconv/hex2bin.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "lbaseconv/util/string.h"

#define BINARY_GROUP_LENGTH_HEX 4

string_t htob(const char *s)
{
    int i, k;
    int output_array_len, input_array_len;
    char bits[BINARY_GROUP_LENGTH_HEX];
    string_t result_str;

    input_array_len = strlen(s);

    /* accounts for prefix */
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')){
        input_array_len -= 2;
        i = 2;
    } else i = 0;

    
    output_array_len = BINARY_GROUP_LENGTH_HEX * input_array_len;
    result_str = string_t_ctor(output_array_len);

    k = 0;
    while (i < input_array_len) {
        if(isdigit(s[i])) {
            make_binary(s[i] - '0', bits);
            put_binary(result_str, bits, &k);
        } else {
            switch(s[i]) {
                case 'A':
                case 'a': 
                    make_binary(10, bits);
                    put_binary(result_str, bits, &k);
                    break;
                case 'B':
                case 'b':
                    make_binary(11, bits);
                    put_binary(result_str, bits, &k);
                    break;
                case 'C':
                case 'c':
                    make_binary(12, bits);
                    put_binary(result_str, bits, &k);
                    break;
                case 'D':
                case 'd':
                    make_binary(13, bits);
                    put_binary(result_str, bits, &k);
                    break;
                case 'E':
                case 'e':
                    make_binary(14, bits);
                    put_binary(result_str, bits, &k);
                    break;
                case 'F':
                case 'f':
                    make_binary(15, bits);
                    put_binary(result_str, bits, &k);
                    break;
            }
        }
        ++i;
    }
    result_str.data[output_array_len] = '\0'; /* add null termination character */

    return result_str;
}

/* make binary output string from hex character */
void make_binary(int c, char* res)
{
    int i, j;

    i = 0;
    do {
        res[i] = c % 2 + '0';
        c /= 2;
        ++i;
    } while (c != 0);

    while(i < BINARY_GROUP_LENGTH_HEX){
        res[i] = '0';
        ++i;
    }
}

/* copy source bits into destination, updating destination index */
void put_binary(string_t destination, char  *source, int *dest_index)
{
    int i, j;

    for(j = BINARY_GROUP_LENGTH_HEX - 1; j >= 0; --j)
        destination.data[(*dest_index)++] = source[j];
}
