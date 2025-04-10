#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
typedef int Elemtype;
typedef struct Sqlist
{
    Elemtype data[MAXSIZE];
    int length;
}Sqlist;
Sqlist* initlist()
{
    Sqlist *L = (Sqlist*)malloc(sizeof(Sqlist));
    L->length = 0;
    return L;
}

void bitnil(Sqlist *L); // Function prototype for bitnil
int addw(Sqlist *L, Elemtype e); // 尾部添加数据
int insert(Sqlist *L, int p, Elemtype e); // 插入函数原型
int del(Sqlist *L, int p, Elemtype *e); // 删除函数原型
int chazhao(Sqlist *L,Elemtype e);



int main()
{
    Sqlist *L = initlist();
    printf("%d\n", L->length);
    printf("%d\n", (int)sizeof(L->data));
    addw(L, 12);
    addw(L, 22);
    addw(L, 32);
    addw(L, 42);
    bitnil(L);
    insert(L, 2, 54);
    bitnil(L);
    Elemtype d;
    del(L,2,&d);
    printf("%d\n",d);
    bitnil(L);
   int i=chazhao(L,12);
   printf("位置在%d\n",i);
   free(L);
    return 0;
}

int addw(Sqlist *L, Elemtype e) // 尾部添加数据
{
    if (L->length == MAXSIZE)
    {
        printf("已满\n");
        return 0;
    }
    L->data[L->length] = e;
    L->length++;
    return 1;
}

void bitnil(Sqlist *L) // 遍历
{
    for (int i = 0; i < L->length; i++)
    {
        printf("%d ", L->data[i]);
    }
    printf("\n");
}

int insert(Sqlist *L, int p, Elemtype e) // 插入
{
    if (L->length >= MAXSIZE)
    {
        printf("满了\n");
        return 0;
    }
    if (p < 1 || p > L->length + 1) // 修正插入位置判断
    {
        printf("插入位置错误\n");
        return 0;
    }
    for (int i = L->length; i >= p; i--) // 从后向前移动元素
    {
        L->data[i] = L->data[i - 1];
    }
    L->data[p - 1] = e; // 插入元素
    L->length++;
    return 1;
}
int del(Sqlist *L,int p,Elemtype *e)//删除
{
    if (L->length == 0)
    {
        printf("满了\n");
        return 0;
    }
    if (p < 1 || p > L->length ) // 修正插入位置判断
    {
        printf("删除位置错误\n");
        return 0;
    }
   *e=L->data[p-1];
   if(p<L->length)
   {
    for(int i=p;i<L->length;i++)
    {
      L->data[i-1]=L->data[i];
    }

   }
   L->length--;
   return 1;

}
int chazhao(Sqlist *L,Elemtype e)//查找
{
    for(int i=0;i<L->length;i++)
    {
        if(L->data[i]==e)
        {
            printf("找到了");
            return i+1;
        }
    }
    return 0;
}