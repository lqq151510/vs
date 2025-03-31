#include <stdio.h>
#include<stdlib.h>
// typedef int in;
// // #define in int
// int main()
// {
//     in a;
//     int b;
//     a=520;
//     b=a;
//     printf("a=%d\n",a);
//     printf("b=%d\n",b);
//     printf("size of a=%d\n",sizeof(a));
//     return 0;

// }

// typedef int in;
// typedef  int  *pi;
// // #define pi int*
// int main()
// {
//     in a=520;
//     pi b,c;//若用define  则 int *b,c c不是指针    
//     b=&a;
//     c=b;
//     printf("address a=%p\n",c);
//     return 0;
// }

typedef struct Date
{
    int year;
    int month;
    int day;
}DATE;//,*PDATE;
int main()
{
    struct Date *date;
    date=( DATE*)malloc(sizeof( DATE));//date=( PDATE)malloc(sizeof( DATE))
    if (date==NULL)
    {
        printf("malloc failed\n");
        exit(1);
    }
    date->year=2022;
    date->month=11;
    date->day=12;
    printf("date->year=%d\n",date->year);
    printf("date->month=%d\n",date->month);
    printf("date->day=%d\n",date->day);
} 