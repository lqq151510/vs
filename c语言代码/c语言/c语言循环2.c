#include <stdio.h>
int main()
{
    // 定义一个整型变量i，并初始化为0
    int i=0;
    // 输出提示信息
    printf("请输入一行字符：");
    // 当从标准输入读取的字符不是换行符时，循环执行
    while (getchar()!='\n')
    {
        // 每次循环，i的值加1
        i=i+1;
    }
    // 输出输入的字符个数
    printf("你输入了%d个字符\n",i);
    // 返回0，表示程序正常结束
    return 0;
}
