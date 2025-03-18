#include <stdio.h>
int main()
{
    // 定义变量i和sum，i用于循环计数，sum用于累加
    int i=1,sum=0;
    // 当i小于等于100时，循环执行
    while (i<=100)
    {
        // 将i的值累加到sum中
        sum+=i;
        // i的值加1
        i++;
    }
    // 输出sum的值
    printf("%d\n",sum);
    // 返回0，表示程序正常结束
    return 0;
}