#ifndef _STR_H_
#define _STR_H_

typedef struct {
    char *data;
    size_t length;
} String;

String *string(const char *input);
size_t string_length(String *str);
void free_string(String *str);

#endif