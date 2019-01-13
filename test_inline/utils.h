#pragma once

#include <string.h>

#define TU_NAME_LEN  32

static const int g_desc[] = {
    1,
    2,
    3,
    4,
    5
};

static const int g_descNum = sizeof(g_desc) / sizeof(g_desc[0]);

typedef void (*TU_NAME)(char *tu);

inline void get_tu_name(char *tu)
{
    if (!tu) return;
    strcpy(tu, TU);
}

#if 0
inline int convert2(int x)
{
    return x + 100;
}
#endif

// 源文件或者头文件中定义静态函数
// gcc4.3.4中wdwd
// 打开-O1优化开关后，如果静态函数没有调用，编译后的目标文件不会包含此函数，也不会生成符号；如果有调用，则会编译成独立函数，并生成局部符号
// 打开-O2优化开关后，静态函数会自动内联，不会编译成独立的函数，也没有符号
static int cube(int x)
{
    return x * x * x;
}

void show_utils(void);
void show_non_inline_in_utils(TU_NAME tu_name, const char *file);