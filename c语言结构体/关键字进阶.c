#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// typedef int (*o)[3];

// int main()
// {   int array[3]={1,2,3};
//     o p=&array;
//     for (int i=0;i<=2;i++)
//     {
//         printf("%d\n",(*p)[i]);
//     }
//     return 0;
// }

// typedef int (*o)(void);
// int fun();
// int fun()
// {
//     return 520;
// }

// int main()
// {   
//     o p=&fun;
//     printf("%d\n",(*p)());
//     return 0;
// }

typedef int *(*o)(int);
int *funA(int num)
{
    printf("%d\n",num);
    return &num;
}
int *funB(int num)
{
    printf("%d\n",num);
    return &num;
}
int *funC(int num)
{
    printf("%d\n",num);
    return &num;
}



int main()
{   
    o array[3]={&funA,&funB,&funC};
    int i;
    for(i=0;i<3;i++)
    {   
      
        printf("add=%p\n",(*array[i])(i));
    }
    return 0;
}