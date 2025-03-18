#include <stdio.h>
int main()
{
     // 定义一个长度为10的整型数组a
     int a[10];
     // 定义一个整型变量i，用于循环
     int i,sum=0;
     // 循环10次
     for ( i=0;i<10;i++)
     {
        // 输出提示信息，要求用户输入第i+1位的成绩
        printf("请输入第%d位的成绩",i+1);
        // 从用户输入中读取一个整型数据，存储到数组a的第i位
        scanf("%d",&a[i]);
        // 将数组a的第i位的数据加到sum中
        sum+=a[i];
     }
     // 输出平均成绩，将sum除以10，并转换为double类型，保留两位小数
     printf("平均成绩为%.2f\n",(double)sum/10);
     // 返回0，表示程序正常结束
     return 0;
}