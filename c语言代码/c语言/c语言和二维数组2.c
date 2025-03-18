#include<stdio.h>
int main()
{
    // 定义一个二维数组array，大小为2行3列，并初始化前两行
    int array[][3]={{1,2,3},{4,5,6}};
    // 定义一个指向包含3个整数的数组的指针p，并将其指向array
    int (*p)[3]=array;
    // 打印p指向的数组的第二行第二列的元素，即array[1][1]
    // p+1指向第二行，*(*(p+1)+1)解引用得到第二行第二列的元素
    printf("%d\n",*(*(p+1)+1));
    // 直接打印array数组的第二行第二列的元素
    printf("%d\n",array[1][1]);
    // 返回0，表示程序正常结束
    printf("%d\n",*(*(array+1)+1));
    printf("%d\n",**p);
    return 0;

}