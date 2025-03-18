#include <stdio.h>
#include <stdlib.h>
int main()
{
    // 定义一个整型变量a，并赋值为10
    int a = 10;
    // 定义一个整型指针p
    int *p=&a;
    // 将指针p指向变量a的地址
    
    // 输出指针p指向的变量的值
    printf("%d\n", *p);
    // 输出指针p的值，即变量a的地址
    printf("%d\n", p);
    // 输出变量a的地址
    printf("%d\n", &a);
    // 输出指针p的地址
    printf("%d\n", &p);
    // 输出指针p的大小
    printf("%d\n", sizeof(p));
    // 输出指针p指向的变量的大小
    printf("%d\n", sizeof(*p));
    // 输出变量a的大小
    printf("%d\n", sizeof(a));
}