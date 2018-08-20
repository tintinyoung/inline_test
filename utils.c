#include <stdio.h>
#include "utils.h"

extern int convert2(int x);

void show_inline_in_utils(int x);

void show_utils(int x)
{
    show_inline_in_utils(x);

    CONVERT convert = convert2;
    show_non_inline_in_utils(x, convert, __FILE__);
}

void show_inline_in_utils(int x)
{
    printf("%s inline %d->%d, func=%p\n", __FILE__, x, convert2(x), convert2);
}

void show_non_inline_in_utils(int x, CONVERT convert, const char *file)
{
    printf("%s %d->%d, func=%p\n", file, x, convert(x), convert);
}