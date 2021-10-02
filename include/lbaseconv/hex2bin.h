/*
 * Copyright (c) 2021, Adrian Costin <adriancostin6@gmail.com>
 * All rights reserved.
 *
 * BSD-2-Clause License
*/
#ifndef __HEX2BIN_H__
#define __HEX2BIN_H__


struct string_t htob(const char *s);
void make_binary(int c, char *res);
void put_binary(struct string_t destination, char *source, int *dest_index);

#endif /* __HEX2BIN_H__ */
