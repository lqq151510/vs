#include<stdio.h>//静态
#define maxsize 10//定义最大长度
typedef int ElemType;
typedef struct{
    ElemType data[maxsize];//数组存放元素
    int length;//定义长度
}Sqlist;//类型定义
void InitList(Sqlist *L)//初始化顺序表
{

   L->length=9;//默认长度为0
}
void Listinsert(Sqlist *L,int i,int e)//插入
{
    if(L->length==maxsize)
    {
        printf("满了");
        return;
    }
    else if (i>L->length+1||i<1)//条件 i > L->length + 1 表示插入位置不能超过当前顺序表长度的下一个位置（即插入只能在现有元素范围内或在表尾追加）。
    {//条件 i < 1 表示插入位置不能小于 1，因为顺序表的索引从 1 开始。
        printf("i不合法");
        return;
    }//最好情况,时间复杂度=o(1)
    //最坏情况,时间复杂度=o(n)
    
    for(int j=L->length;j>=i;j--)
    {
        L->data[j]=L->data[j-1];//第i个及以后得元素后移
    }
    L->data[i-1]=e;
    L->length++;
}
int Listdelete(Sqlist *L,int i,int *e)//删除
{
    if (i > L->length || i < 1)
    {
        printf("i不合法");
        return 0;
    }
    *e = L->data[i-1];
    for(int j = i; j < L->length; j++)
    {
        L->data[j-1] = L->data[j];
    }
    L->length--;
    return 1;
}
ElemType GetElem(Sqlist *L,int i)//按位查找
{
    return L->data[i-1];
}
int LocateElem(Sqlist *L,int e)//按值查找
{
    for(int i=0;i<=L->length;i++)
    {
        if(L->data==e)
        {
            return i+1;//返回索引
        }
    }
    return 0;
}
int main()
{   int e=-1;
    Sqlist L;//声明一个顺序表
    InitList(&L);
    Listinsert(&L, 3, 3);
    if(Listdelete(&L, 3, &e))
    {
        printf("删除成功，删除的元素为：%d\n", e);
    }
    return 0;
}


// #include<stdio.h>//动态
// #include<string.h>
// #include<stdlib.h>
// #define InitSize 10//定义初始长度
// typedef int ElemType;
// typedef struct{
//     ElemType *data;//动态分配数组指针
//     int MaxSize;//顺序表最大容量
//     int length;//定义长度
// }Seqlist;//类型定义
// void InitList(Seqlist *L)//初始化顺序表
// {
//    L->data=(ElemType*)malloc(sizeof(ElemType)*InitSize);// (ElemType*) 是强制类型转换，将 malloc 返回的 void* 指针转换为 ElemType* 类型。
//    L->length=0;//默认长度为0
//    L->MaxSize=InitSize;//最大长度
// }
// void IncreaseSize(Seqlist *L,int len)
// {
//     int *p=L->data;//将当前顺序表的 data 指针保存到临时指针 p 中，以便后续复制数据和释放旧内存。
//     L->data=(int*)malloc(sizeof(int)*(L->MaxSize+len));
//     for(int i=0;i<L->length;i++)
//     {
//         L->data[i]=p[i];
//     }
//     L->MaxSize=L->MaxSize+len;
//     free(p);
// }
// int main()
// {
//     Seqlist L;//声明一个顺序表
//     InitList(&L);//初始化顺序表
//     IncreaseSize(&L,5);
//     return 0;
// }