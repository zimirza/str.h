#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "str.h"

String *string(const char *input) {
    String *str;
    size_t length;

    if (input == NULL) {
        return NULL;
    }

    length = strlen(input);
    str = (String *)malloc(sizeof(String));
    if (str == NULL) {
        return NULL;
    }

    str->data = (char *)malloc(length + 1);
    if (str->data == NULL) {
        free(str);
        return NULL;
    }

    strcpy(str->data, input);
    str->length = length;

    return str;
}

void free_string(String *str) {
    free(str->data);
    free(str);
}
