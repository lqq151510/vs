#include<stdio.h>
int main()
{
  
 int a=520;
 int *p=&a;
 int **q=&p;
 printf("%d\n",*p);
 printf("%d\n",**q);
 printf("%p\n",p);
 printf("%p\n",*q);
 printf("%p\n",&a);

    return 0; 
}