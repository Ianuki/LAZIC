#pragma once

#include <cstring>

#ifndef TOKEN
#define TOKEN

enum token_type {
    TOKEN_KEYWORD,
    TOKEN_IDENTIFIER,
    TOKEN_NUMBER,
    TOKEN_OPERATOR,
    TOKEN_STRING,
    TOKEN_END_LINE,
    TOKEN_UNKNOWN
};

union token_value {
    int int_value;
    char string_value[16];
    char identifier_value[8];
};

struct token {
    token_type type;
    token_value value;
};

#endif 