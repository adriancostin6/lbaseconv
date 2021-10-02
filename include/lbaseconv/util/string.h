#ifndef __STRING_H__
#define __STRING_H__

typedef struct string_t{
    char* data;
    int len;
} string_t;

void string_t_dtor(string_t s);
string_t string_t_ctor(int len);

#endif /* __STRING_H__ */
