#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;
typedef struct Node
{
    ElemType data;//数据域
    struct  Node* next;//指针域
    
}Node;
typedef struct Node* LinkList;//struct Node* 是指向 Node 结构体的指针类型。
//使用 typedef 将 struct Node* 定义为一个新的类型名 LinkList，简化了代码的书写。

typedef int Status; // 定义 Status 类型，通常用 int

Status GetElem(LinkList L,int i,ElemType *e)
{
    LinkList p;
    int j;
    j=1;
    p=L->next;//p 用于遍历链表，初始指向链表的第一个节点（假设链表有头节点）。
    while(p&&j<i)
    {
        p=p->next;
        ++j;
    }
    if(!p||j>i)//如果 p 为 NULL（链表长度不足）或 j > i（位置非法），返回 -1 表示失败。
    {
        return -1;
    }
    *e=p->data;
    return 0;
}
Status insert(LinkList *L,int i, int e)//插入
{
  
   int j;
   LinkList p,s;
   j=1;
   p=*L;
   while(p&&j<i)
   {
       p=p->next;
       ++j;
   }
   if(!p||j>i)//如果 p 为 NULL（链表长度不足）或 j > i（位置非法），返回 -1 表示失败。
   {
       return -1;
   }
   s=(LinkList)malloc(sizeof(Node));
   s->data=e;
   s->next=p->next;
   p->next=s;
   return 0;

}
Status delete(LinkList *L,int i,int *e)//删除
{
    int j;
    j=1;
    LinkList p,s;
    p=*L;
    while(p->next&&j<i)
   {
       p=p->next;
       ++j;
   }
   if(!(p->next)||j>i)//如果 p 为 NULL（链表长度不足）或 j > i（位置非法），返回 -1 表示失败。
   {
       return -1;
   }
   
   s=p->next;
   p->next=s->next;
   s->data=*e;
   return 0;
}
void headinsert(LinkList *L,int n)//头插法
{
    LinkList p;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    (*L)->next=NULL;//头结点
    for(int i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        p->next=(*L)->next;//p指向头结点,head
        (*L)->next=p;//更新头结点
    }

}
void tailinsert(LinkList *L,int n)//尾插法
{
    LinkList p,r;
    int i;
    srand(time(0));
    *L=(LinkList)malloc(sizeof(Node));
    r=*L;//尾结点
    for(int i=0;i<n;i++)
    {
        p=(LinkList)malloc(sizeof(Node));
        p->data=rand()%100+1;
        r->next=p;//尾结点指向p
        r=p;//更新尾结点
    }

}
Status clearList(LinkList *L)//整表删除(释放内存)
{
    LinkList p,q;
    p=(*L)->next;
    while ((p))
    {
        p=p->next;
        free(p);
        p=q;
    }
    (*L)->next=NULL;
    return 0;
}
#define MAXSIZE 1000//静态链表
typedef struct 
{
    ElemType data;//数据
    int cur;//游标,cur 是一个整数，表示当前节点的下一个节点在数组中的位置索引。如果 cur 为 0，表示当前节点是链表的最后一个节点。
}Compoent,StaticLinkList[MAXSIZE];//使用 typedef 定义了一个静态链表类型
Status InitList(StaticLinkList space)
{
    int i;
    for(i=0;i<MAXSIZE;i++)
    {
        space[i].cur=i+1;
    }
    space[MAXSIZE-1].cur=0;
    return 0;

}
