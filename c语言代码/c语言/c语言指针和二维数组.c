#include <stdio.h>
int main()
{int a[4][5]={{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
// printf("%d\n",sizeof(a));
// printf("%p\n",a);
// printf("%p\n",a+1);i

int i,j,k=0;
for (i=0;i<4;i++)
{
    for(j=0;j<5;j++)
    {
        a[i][j]=k++;
    }

}
printf("%p\n",*(a+1));
printf("%p\n",a[1]);
printf("%p\n",&a[1][0]);
printf("%d\n",**(a+1));
printf("%d\n",*(*(a+1)+3));
printf("%d\n",a[1][3]);
}
