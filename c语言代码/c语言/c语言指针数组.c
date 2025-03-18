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
    char *p1[5]={"hello",
        "world",
        "c",
        "language",
        "pointer"};
        int i;
        for (i=0;i<5;i++){
            printf("%s\n",p1[i]);
        }

    return 0;
}