#pragma once

typedef int (*CONVERT)(int x);

inline int convert2(int x)
{
    return x + CONVERT_BASE;
}

void show_utils(int x);
void show_non_inline_in_utils(int x, CONVERT convert, const char *file);