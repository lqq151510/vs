#include <stdio.h>
int main()
{
    struct A
    {
        char a;
        int b;
        char c;
    }a={'a',520,'0'};
printf("size of a=%d\n",sizeof(a));//内存对齐
    return 0;
}