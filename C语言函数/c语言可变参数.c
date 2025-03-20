#include <stdio.h>
#include <stdarg.h>

int sum(int n, ...);

// 定义一个函数sum，用于计算可变参数的总和
// 参数n表示可变参数的数量
// ...表示可变参数列表
int sum(int n, ...)
{
    // 定义变量i用于循环计数
    // 定义变量total_sum用于存储总和，初始值为0
    int i, total_sum = 0;
    // 定义一个va_list类型的变量ap，用于存储可变参数列表
    va_list ap;
    // 初始化可变参数列表ap，n是可变参数之前的固定参数
    va_start(ap, n);
    // 使用for循环遍历可变参数列表
    // 循环次数为n，即可变参数的数量
    for (i = 0;i < n;i++)
    {
        // 使用va_arg宏获取可变参数列表中的下一个参数，类型为int
        // 将获取到的参数值累加到total_sum中
        total_sum += va_arg(ap, int);
    }
    // 结束可变参数列表的使用
    va_end(ap);
    // 返回计算得到的总和
    return total_sum;
}

// 定义主函数，程序从这里开始执行
int main()
{
    // 调用sum函数，传入4个参数3, 1, 2, 3，并将返回值存储在result变量中
    // 假设sum函数已经定义，用于计算多个整数的和
    int result = sum(3, 1, 2, 3);
    // 使用printf函数输出result变量的值，格式为"Sum: "后跟result的值
    // %d是格式化字符串，用于表示整数
    printf("Sum: %d\n", result);
    // 返回0，表示程序正常结束
    return 0;
}
