#include <stdio.h>
#include <stdlib.h>
int main()
{
    // int a=1;
    // int b=2;
    // int c=3;
    // int d=4;
    // int e=5;
    // int *p[5]={&a,&b,&c,&d,&e};
    // for (int i=0;i<5;i++){ //  遍历指针数组，输出指针数组中每个指针指向的值
    //     printf("%d\n",*p[i]);
    // 定义一个字符指针数组p1，包含5个字符串常量
    char *p1[5]={"hello",
        "world",
        "c",
        "language",
        "pointer"};   
    // 定义一个整型变量i，用于循环控制
        int i;
    // 使用for循环遍历字符指针数组p1
        for (i=0;i<5;i++){
        // 输出字符指针数组p1中每个元素指向的字符串
            printf("%s\n",p1[i]);
        }

    return 0;
}