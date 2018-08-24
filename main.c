#include <stdio.h>
#include "utils.h"

int main(void)
{
    char tu[TU_NAME_LEN] = {0};
    get_tu_name(tu);
    printf("%s inline tu name=%s, func=%p\n", __FILE__, tu, get_tu_name);

    TU_NAME tu_name = get_tu_name;
    show_non_inline_in_utils(tu_name, __FILE__);

    show_utils();

    return 0;
}