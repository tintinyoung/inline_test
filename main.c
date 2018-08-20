#include <stdio.h>
#include "utils.h"

int main(void)
{
    int x = 1;
    printf("%s inline %d->%d, func=%p\n", __FILE__, x, convert2(x), convert2);

    CONVERT convert = convert2;
    show_non_inline_in_utils(x, convert, __FILE__);

    show_utils(x);

    return 0;
}