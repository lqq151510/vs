#include <stdio.h>
void arry(int a[10]);
// 定义一个名为arry的函数，接受一个包含10个整数的数组作为参数
void arry(int a[10])
{
    // 将数组a的第6个元素（索引为5）赋值为520
    a[5]=520;
    // 使用for循环遍历数组a的每个元素
for (int i = 0; i <10; i++)
{
        // 打印当前元素的索引和值
    printf("函数a[%d]=%d\n",i,a[i]);
}
    // 打印数组a的大小（以字节为单位）
    // 注意：这里打印的结果是8
printf("sizeof(a)=%d\n",sizeof(a));
}
int main()
{
    // 定义一个整型数组a，包含10个元素，并初始化为1到10
    int a[10]={1,2,3,4,5,6,7,8,9,10};
    // 定义一个整型变量i，用于循环控制
    int i;
    // 使用for循环遍历数组a，并打印每个元素的值
    for (int i = 0; i <10; i++)
    {
        // 打印数组a的第i个元素的值
        printf("主函数a[%d]=%d\n",i,a[i]);
    }
    // 打印数组a的大小（以字节为单位）
    printf("sizeof(a)=%d\n",sizeof(a));
    
    // 调用arry函数，将数组a作为参数传递
    arry(a);
    // 返回0，表示程序正常结束
    return  0;
}
