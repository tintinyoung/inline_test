#pragma once

#include <string.h>

#define TU_NAME_LEN  32
typedef void (*TU_NAME)(char *x);

inline void get_tu_name(char *tu)
{
    if (!tu) return;
    strcpy(tu, TU);
}

void show_utils(void);
void show_non_inline_in_utils(TU_NAME tu_name, const char *file);