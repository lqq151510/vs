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

#define MAX_LENGTH 100 // 定义链表的最大长度

// 初始化链表头结点
Status InitLinkList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    if (!(*L)) {
        printf("内存分配失败！\n");
        return -1; // 初始化失败
    }
    (*L)->next = NULL; // 头结点的指针域初始化为空
    return 0; // 初始化成功
}
Status GetElem(LinkList L, int i, ElemType *e) {
    LinkList p = L->next; // 指向链表的第一个节点
    int j = 1; // 计数器，表示当前节点的位置
    while (p && j < i) { // 遍历链表，直到找到第 i 个节点或链表结束
        p = p->next;
        ++j;
    }
    if (!p || j > i) { // 如果 p 为 NULL 或 j 超过 i，表示查找失败
        printf("查找失败：位置非法或链表长度不足。\n");
        return -1;
    }
    *e = p->data; // 将找到的节点数据赋值给 e
    return 0; // 查找成功
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
       printf("插入失败：位置非法或链表长度不足。\n");
       return -1;
   }
   s=(LinkList)malloc(sizeof(Node));
   if (!s) {
       printf("内存分配失败！\n");
       return -1;
   }
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
       printf("删除失败：位置非法或链表长度不足。\n");
       return -1;
   }
   
   s=p->next;
   p->next=s->next;
   s->data=*e;
   free(s); // 释放删除节点的内存
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
        if (!p) {
            printf("内存分配失败！\n");
            return;
        }
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
        if (!p) {
            printf("内存分配失败！\n");
            return;
        }
        p->data=rand()%100+1;
        r->next=p;//尾结点指向p
        r=p;//更新尾结点
    }

}
Status clearList(LinkList *L)//整表删除(释放内存)
{
    LinkList p,q;
    p=(*L)->next;
    while (p)
    {
        q=p->next;
        free(p); // 释放当前节点的内存
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
//循环链表
typedef struct CNode {
    ElemType data; // 数据域
    struct CNode* next; // 指针域，指向下一个节点
} CNode, *CircularLinkList;

// 循环链表的初始化
Status InitCircularList(CircularLinkList* L) {
    *L = (CircularLinkList)malloc(sizeof(CNode));
    if (!(*L)) {
        printf("内存分配失败！\n");
        return -1; // 分配失败
    }
    (*L)->next = *L; // 头结点指向自身，形成循环
    return 0; // 初始化成功
}

// 循环链表的插入
Status InsertCircularList(CircularLinkList L, int i, ElemType e) {
    CircularLinkList p = L;
    int j = 1;
    while (p->next != L && j < i) { // 遍历到第 i-1 个节点
        p = p->next;
        ++j;
    }
    if (j > i) {
        printf("插入失败：位置非法。\n");
        return -1; // 插入位置非法
    }
    CircularLinkList s = (CircularLinkList)malloc(sizeof(CNode));
    if (!s) {
        printf("内存分配失败！\n");
        return -1; // 分配失败
    }
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 0; // 插入成功
}

// 循环链表的删除
Status DeleteCircularList(CircularLinkList L, int i, ElemType* e) {
    CircularLinkList p = L;
    int j = 1;
    while (p->next != L && j < i) { // 遍历到第 i-1 个节点
        p = p->next;
        ++j;
    }
    if (p->next == L || j > i) {
        printf("删除失败：位置非法。\n");
        return -1; // 删除位置非法
    }
    CircularLinkList q = p->next;
    *e = q->data; // 保存被删除节点的数据
    p->next = q->next;
    free(q); // 释放被删除节点的内存
    return 0; // 删除成功
}

// 循环链表的遍历
void TraverseCircularList(CircularLinkList L) {
    if (L->next == L) {
        printf("循环链表为空。\n");
        return; // 空链表
    }
    CircularLinkList p = L->next;
    while (p != L) { // 遍历链表直到回到头结点
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// // 约瑟夫问题
// void JosephusProblem(int n, int m) {
//     CircularLinkList L, p, q;
//     int i;

//     // 初始化循环链表
//     InitCircularList(&L);
//     p = L;
//     for (i = 1; i <= n; i++) {
//         CircularLinkList node = (CircularLinkList)malloc(sizeof(CNode));
//         node->data = i;
//         node->next = L;
//         p->next = node;
//         p = node;
//     }

//     // 模拟约瑟夫问题
//     p = L;
//     while (p->next != p) { // 当链表中还有多个节点时
//         for (i = 1; i < m; i++) {
//             p = p->next; // 移动到第 m-1 个节点
//         }
//         q = p->next; // 第 m 个节点
//         printf("%d ", q->data); // 输出被删除的节点编号
//         p->next = q->next; // 删除第 m 个节点
//         free(q);
//     }
//     printf("%d\n", p->data); // 输出最后一个节点编号
//     free(p);
// }
void JosephusProblem(int n, int m) 
{
    CircularLinkList p,L;
    int i;
    InitCircularList(&L);
    p=L;
    for(i=1;i<=n;i++)
    {
        CircularLinkList node = (CircularLinkList)malloc(sizeof(CNode));
        node->data=i;
        node->next=p;
        p->next=node;
        p=node;
    }
    p=L;
    while(p->next!=p)
    {
        for (i = 1; i < m; i++)
    {
            p = p->next; // 移动到第 m-1 个节点
    }
    CircularLinkList q;
    q=p->next;
    printf("删除%d\n",q->data);
    p->next=q->next;
    free(q);
    }
    printf("最后结点:%d\n",p->data);
    free(p); 
}
//双向链表

// 双向链表节点定义
typedef struct DNode {
    ElemType data; // 数据域
    struct DNode* prior; // 前驱指针
    struct DNode* next;  // 后继指针
} DNode, *DLinkList;

// 双向链表的初始化
Status InitDLinkList(DLinkList* L) {
    *L = (DLinkList)malloc(sizeof(DNode));
    if (!(*L)) {
        printf("内存分配失败！\n");
        return -1; // 分配失败
    }
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return 0; // 初始化成功
}

// 双向链表的插入
Status InsertDLinkList(DLinkList L, int i, ElemType e) {
    DLinkList p = L;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        printf("插入失败：位置非法。\n");
        return -1; // 插入位置非法
    }
    DLinkList s = (DLinkList)malloc(sizeof(DNode));
    if (!s) {
        printf("内存分配失败！\n");
        return -1; // 分配失败
    }
    s->data = e;
    s->next = p->next;
    if (p->next) p->next->prior = s; // 更新后继节点的前驱指针
    s->prior = p;
    p->next = s;
    return 0; // 插入成功
}

// 双向链表的删除
Status DeleteDLinkList(DLinkList L, int i, ElemType* e) {
    DLinkList p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) {
        printf("删除失败：位置非法。\n");
        return -1; // 删除位置非法
    }
    *e = p->data;
    if (p->next) p->next->prior = p->prior; // 更新后继节点的前驱指针
    if (p->prior) p->prior->next = p->next; // 更新前驱节点的后继指针
    free(p); // 释放节点内存
    return 0; // 删除成功
}

// 双向链表的遍历
void TraverseDLinkList(DLinkList L) {
    DLinkList p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}