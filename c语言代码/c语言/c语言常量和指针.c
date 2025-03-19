#include<stdio.h>
int main()
{
    // const float pi=3.14;
    // printf("%.2lf\n",pi);
// pi=3.15;
int num=520;
const int cnum=880;
const int *p=&cnum;
printf("%d,%p\n",cnum,&cnum);
printf("%d,%p\n",*p,p);
p=&num;
printf("%d,%p\n",num,&num);
printf("%d,%p\n",*p,p);
num=1024;
printf("%d,%p\n",num,&num);
printf("%d,%p\n",*p,p);

return 0;

}