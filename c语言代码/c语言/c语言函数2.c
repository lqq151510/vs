#include<stdio.h>
int func(int a,int b,int c);
int func(int a,int b,int c)
{ int s;
    s=a+b+c;
    return s;
}
int main()
{
	int a,b,c,i;
    printf("请输入三个整数：\n");

	scanf("%d %d %d",&a,&b,&c);
	i=func(a,b,c);
    printf("三个数的和为：%d\n",i);
	return 0;
}