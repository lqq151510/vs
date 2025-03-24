#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// int main()
// {
//     int *p=NULL;
//     int num,i;
//     printf("请输入要输入的整数个数：");
//     scanf("%d",&num);
//     p=(int*)malloc(num*sizeof(int));
//     if(p==NULL)
//     {
//         printf("内存分配失败！\n");
//         exit(1);
//     }
   
//     for(i=0;i<num;i++)
//     {  printf("请输入%d个整数：\n",i+1);
//         scanf("%d",&p[i]);
//     }
//     printf("你输入的整数是：\n");
//     for (i=0;i<num;i++)
//     {
//         printf("%d ",*(p+i));
//     }
//     putchar('\n');
//     free(p);
//     return 0;
// }
// #define N 10
// int main()
// {
//     int *p=NULL;int i;
//     p=(int*)malloc(N*sizeof(int));
//     memset(p,0,N*sizeof(int));//p=(int*)calloc(N*sizeof(int));
//     {
//         printf("内存分配失败！\n");
//         exit(1);
//     }
//     for(i=0;i<N;i++)
//     {
//         printf("%d ",*(p+i));
//     }
//     putchar('\n');
//     free(p);
//     return 0;
// }

// int main()
// {
//     // 定义两个整型指针p1和p2
//     int *p1;
//     int *p2;
//     // 为p1分配10个整型大小的内存空间
//     p1=(int*)malloc(10*sizeof(int));
//     // 为p2分配20个整型大小的内存空间
//     p2=(int*)malloc(20*sizeof(int));
//     // 将p1指向的内存内容复制到p2指向的内存中，复制长度为10个整型大小
//     // 注意：这里存在潜在问题，p1指向的内存可能未初始化，复制未定义内容可能导致不确定行为
//    memcpy(p2,p1,10);
//     // 释放p1指向的内存空间
//     free(p1);
//     // 释放p2指向的内存空间
//     free(p2);
// }
int main()
{
    int i,num; // 定义变量i和num，用于循环和存储输入的整数
    int count=0; // 定义计数器count，用于记录输入的整数个数
    int *p=NULL; // 定义指针p，用于动态分配内存存储输入的整数，初始为NULL
    do
    {
        printf("输入:"); // 提示用户输入整数
        scanf("%d\n",&num); // 读取用户输入的整数，存储到num变量中
        count++; // 输入一个整数，计数器加1
        
        // 动态分配内存，存储输入的整数，每次输入增加一个整数的空间
        p=(int*)realloc(p,count*sizeof(int));
        if (p==NULL) // 检查内存分配是否成功
        {
            exit(1); // 如果内存分配失败，退出程序
        }
        p[count-1]=num; // 将输入的整数存储到动态分配的内存中

        
        
    } while (num !=-1); // 当输入的整数为-1时，结束循环
    printf("你输入的整数是：\n"); // 输出提示信息
    for (i=0;i<count;i++) // 遍历存储的整数
    {
        printf("%d ",*(p+i)); // 输出每个整数
    }
    putchar('\n'); // 输出换行符
    free(p); // 释放动态分配的内存
    return 0; // 程序正常结束
}
