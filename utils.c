#include <stdio.h>
#include "utils.h"

extern void get_tu_name(char *tu);

void show_inline_in_utils(void);

void show_utils(void)
{
    show_inline_in_utils();

    TU_NAME tu_name = get_tu_name;
    show_non_inline_in_utils(tu_name, __FILE__);
}

void show_inline_in_utils(void)
{
    char tu[TU_NAME_LEN] = {0};
    get_tu_name(tu);
    printf("%s:%s, func=%p\n", __FILE__, tu, get_tu_name);
}

void show_non_inline_in_utils(TU_NAME tu_name, const char *file)
{
    char tu[TU_NAME_LEN] = {0};
    tu_name(tu);
    printf("%s:%s, func=%p\n", file, tu_name(), tu_name);
}