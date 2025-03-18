#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t[5]={1,2,3,4,5};
    int (*p1)[5]=&t;
    int i;
    for (i=0;i<5;i++)
    {
        printf("%d\n",*(*p1+i));

    }
    return 0;
}