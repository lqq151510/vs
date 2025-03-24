#include <stdio.h>
#include <stdlib.h>
int main()
{
    // 定义一个整型指针p
    int *p;
    // 使用malloc函数为p分配一个整型大小的内存空间
    p=(int*)malloc(sizeof(int));
    // 检查malloc函数是否成功分配内存
    if (p==NULL)
    {
        // 如果分配失败，输出错误信息
        printf("申请内存失败\n");
        // 返回0，表示程序异常终止
        return 0;
    }
    else
    {
        // 如果分配成功，输出成功信息
        printf("申请内存成功\n");
       printf("请输出一个值：");
       scanf("%d",p);
        // 输出p指向的内存空间中的值
        printf("输出%d\n",*p);
        // 使用free函数释放p指向的内存空间

        free(p);
    }
    // 返回0，表示程序正常结束
    return 0;

}