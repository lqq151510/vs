#include <stdio.h>
int main()
{
    int n,i;
    printf ("请输入字符的个数：");
    scanf ("%d",&n);
    char a[n];
    printf ("请输入字符：");
    getchar ();//输入字符
    for (i=0;i<n;i++)
    {    
        scanf ("%c",&a[i]);
    }
    a[n]='\0';//字符串结束标志
    printf ("输出的字符为：%s\n",a);
    return 0;
}