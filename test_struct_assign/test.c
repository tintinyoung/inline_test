#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIXED_LEN 11
struct A {
    int a;
    char b[FIXED_LEN];
    int *p;
    int append_len;
    char appends[];
};

const int ARRAY_SIZE = 10;

void print_sizeof_a(struct A *a)
{
    printf("sizeof A:%lu\n", sizeof(*a));
    printf("sizeof member:a=%lu,b=%lu,p=%lu,append_len=%lu\n", sizeof(a->a), sizeof(a->b), sizeof(a->p),
                    sizeof(a->append_len)/*, sizeof(a->appends)*/);
}

void print_a(struct A *a)
{
    int i;
    int append_print_len = a->append_len > ARRAY_SIZE ? a->append_len : ARRAY_SIZE;
    printf("a=%d,b=[%d,%d,%d,%d],p=%p;append(%d)=", a->a, a->b[0], a->b[1], a->b[2], a->b[3], a->p, a->append_len);
    for (i = 0; i < append_print_len; ++i) {
        printf("%x ", a->appends[i]);
    }
    printf("\n");
}

void assign_a(struct A *a, struct A *b)
{
    *a = *b;
}

/*
_assign_a:
100000cc5:	55 	pushq	%rbp                            # 将调用函数的rbp压栈，保存调用者的rbp，函数返回时再弹出恢复
100000cc6:	48 89 e5 	movq	%rsp, %rbp              # 将rbp设置为rsp
100000cc9:	48 89 7d f8 	movq	%rdi, -8(%rbp)      # 将第一个参数a保存到栈上（rbp - 8）
100000ccd:	48 89 75 f0 	movq	%rsi, -16(%rbp)     # 将第二个参数b保存在栈上（rbp - 16）
100000cd1:	48 8b 45 f8 	movq	-8(%rbp), %rax      # 将第一个参数a赋值给寄存器rax
100000cd5:	48 8b 55 f0 	movq	-16(%rbp), %rdx     # 将第二个参数b赋值给寄存器rdx
100000cd9:	48 8b 0a 	movq	(%rdx), %rcx            # 将第二个参数b，取指针指向的结构体A的值（前64位）到寄存器rcx中
100000cdc:	48 89 08 	movq	%rcx, (%rax)            # 将rcx赋值给第一个参数a指向的结构体A（前64位）
100000cdf:	48 8b 4a 08 	movq	8(%rdx), %rcx       # 取b指向的结构体A的第二个64位到寄存器rcx
100000ce3:	48 89 48 08 	movq	%rcx, 8(%rax)       # 将rcx赋值给a指向的结构体的第二个64位
100000ce7:	48 8b 52 10 	movq	16(%rdx), %rdx      # 取b指向的结构体A的第三个64位到寄存器rdx
100000ceb:	48 89 50 10 	movq	%rdx, 16(%rax)      # 将rdx赋值给a指向的结构体的第三个64位
100000cef:	90 	nop                                     # 空指令
100000cf0:	5d 	popq	%rbp                            # 弹出rbp，恢复调用者的rbp
100000cf1:	c3 	retq                                    # 函数返回
*/

int test(void)
{
    const unsigned long size = sizeof(struct A) + ARRAY_SIZE * sizeof(char);
    int x = 100;
    struct A *a = malloc(size);

    int x1 = -9;
    unsigned char y = (x1 & 0xf0000000UL);
    printf("x=%d(%x),y=%x\n", x1, (unsigned int)x1, y);

    a->a = 1;
    a->b[0] = 0;
    a->b[1] = 2;
    a->b[2] = 3;
    a->b[3] = 4;
    a->p    =  &x;
    a->append_len = ARRAY_SIZE;
    memset(a->appends, 0xa, ARRAY_SIZE * sizeof(char));

    struct A *b = malloc(size);
    memset(b->appends, 0xb, ARRAY_SIZE * sizeof(char));

    assign_a(b, a);

    print_sizeof_a(a);

    printf("a:");
    print_a(a);
    printf("b:");
    print_a(b);

    free(a);
    free(b);
    return 0;
}

