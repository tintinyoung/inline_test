#include <stdio.h>
#include "utils.h"

int swap(int arg)
{
    short * s = (short *)&arg;
    short hi = s[0];
    short lo = s[1];

    s[1] = hi;
    s[0] = lo;

    return arg;
}

int test(void)
{
    int x = 0x1234;
    int y = swap(x);
    printf("x=%#x,y=%#x\n", x, y);
#if 0
    int i = 100;
    short *s = (short *)&i;
    const int n = 10;
    char tu[TU_NAME_LEN] = {0};
    int a[n];
    get_tu_name(tu);
    printf("%s inline tu name=%s, func=%p\n", __FILE__, tu, get_tu_name);

    for (int i = 0; i < 3; ++i) {
        printf("count %u\n", i);
    }

    for (int i = 0; i < g_descNum; ++i) {
        printf("#%u-%d\n", i, g_desc[i]);
    }

    TU_NAME tu_name = get_tu_name;
    show_non_inline_in_utils(tu_name, __FILE__);

    show_utils();
#endif
    return 0;
}