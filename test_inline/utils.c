#include <stdio.h>
#include "utils.h"

// c99: 源文件中以下三种方式声明内联函数，内联函数会编译成独立的函数，并生成全局符号
// extern void get_tu_name(char *tu);
void get_tu_name(char *tu);
// extern inline void get_tu_name(char *tu);

void show_inline_in_utils(void);

#if 1
int convert2(int x)
{
    return x + 100;
}
#endif

void show_utils(void)
{
    show_inline_in_utils();

    TU_NAME tu_name = get_tu_name;
    show_non_inline_in_utils(tu_name, __FILE__);
}

void show_inline_in_utils(void)
{
    int x = convert2(1);
    char tu[TU_NAME_LEN] = {0};
    get_tu_name(tu);
    printf("%s inline:tu name=%s, func=%p, x=%d\n", __FILE__, tu, get_tu_name, x);
}

void show_non_inline_in_utils(TU_NAME tu_name, const char *file)
{
    char tu[TU_NAME_LEN] = {0};
    tu_name(tu);
    printf("%s non inline:tu name=%s, func=%p\n", file, tu, tu_name);

    for (int i = 0; i < g_descNum; ++i) {
        printf("#%u-%d\n", i, g_desc[i]);
    }
}