#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
// #define R 6371
// #define PI 3.14
// #define V PI*R*R*R*4/3
// int main()
// {
//     int r;
//     float s;
    // printf("圆输入圆的半径：");
    // scanf("%d",&r);
    // s=PI*r*r;
    // printf("圆的面积是：%.2f\n",s);
//     printf("球的体积是：%.2f\n",V);
// return 0;
// }

// 定义一个静态内联函数MAX，用于计算两个整数中的最大值
// "static"关键字表示该函数的作用域仅限于定义它的文件
// "inline"关键字建议编译器将函数调用展开为内联代码，以提高运行效率
static inline int MAX(int x, int y) {
    // 函数接受两个整数参数x和y
    // 使用三元运算符判断x和y的大小
    // 如果x大于y，则返回x；否则返回y
    return (x > y) ? x : y;
}

int main() {
    int num1, num2; // 定义两个整数变量num1和num2用于存储用户输入的整数
    
    printf("输入两个整数："); // 提示用户输入两个整数
    if (scanf("%d%d", &num1, &num2) != 2) { // 使用scanf函数读取用户输入的两个整数

        // 如果scanf返回值不是2，说明用户输入的不是两个整数
        printf("输入无效，请输入两个整数。\n"); // 提示用户输入无效
        return 1; // 返回非零值表示程序异常退出
    }
    
    printf("%d是较大的数\n", MAX(num1, num2)); // 调用MAX宏函数比较两个整数并输出较大的数
    
    return 0; // 返回0表示程序正常退出
}
