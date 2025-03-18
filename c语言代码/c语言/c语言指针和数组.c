#include <stdio.h>
int main()
{
    // 定义一个整型数组a，包含5个元素，分别为1, 3, 5, 7, 9
    int a[5] = {1, 3, 5, 7, 9};
    // 定义一个整型指针p，并将其指向数组a的首元素
    int *p = a;
    // 定义一个整型变量i，用于循环控制
    int i;
    // 使用for循环遍历数组a
    for (i = 0; i < 5; i++)
    {
        printf("%d ", *(p+ i));
    }
    return 0;
}