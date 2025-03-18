#include <stdio.h>
int main()
{
    // 定义两个整型变量i和j
    int i,j;
    // 外层循环，从1到9
    for (i=1;i<10;i++)
    {
        // 内层循环，从1到i
        for (j=1;j<=i;j++)
        {
            // 输出i*j的结果
            printf("%d*%d=%-2d\t",i,j,i*j);
        }
        // 每次内层循环结束后换行
        printf("\n");
    }
    // 返回0，表示程序正常结束
    return 0;
}