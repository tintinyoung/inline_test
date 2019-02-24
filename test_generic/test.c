#include <stdio.h>
#include "test.h"

#ifdef WAY1
#define GET_TYPE(expr) _Generic(expr, double: "double", float: "float", signed char: "schar", unsigned char: "uchar", \
                                  int:"int", unsigned int: "uint", long: "long", unsigned long: "ulong", \
                                  default: "unknown")
#endif

int test(void)
{
    char c = 100;
    int x = c + 1;
    float f = 1.1;
    int y = x + f;
    double d = 1.222;

#ifdef WAY1
    printf("%s\n", GET_TYPE(d+1));
#endif

#ifdef WAY2
    printf("%s\n", (d+1));
#endif
    return 0;
}