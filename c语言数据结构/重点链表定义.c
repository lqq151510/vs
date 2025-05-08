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
//循环链表
typedef struct CNode {
    ElemType data; // 数据域
    struct CNode* next; // 指针域，指向下一个节点
} CNode, *CircularLinkList;

// 循环链表的初始化
Status InitCircularList(CircularLinkList* L) {
    *L = (CircularLinkList)malloc(sizeof(CNode));
    if (!(*L)) return -1; // 分配失败
    (*L)->next = *L; // 头结点指向自身，形成循环
    return 0;
}

// 循环链表的插入
Status InsertCircularList(CircularLinkList L, int i, ElemType e) {
    CircularLinkList p = L;
    int j = 1;
    while (p->next != L && j < i) {
        p = p->next;
        ++j;
    }
    if (j > i) return -1; // 插入位置非法
    CircularLinkList s = (CircularLinkList)malloc(sizeof(CNode));
    if (!s) return -1; // 分配失败
    s->data = e;
    s->next = p;
    p->next = s;
    p=s;
    return 0;
}

// 循环链表的删除
Status DeleteCircularList(CircularLinkList L, int i, ElemType* e) {
    CircularLinkList p = L;
    int j = 1;
    while (p->next != L && j < i) {
        p = p->next;
        ++j;
    }
    if (p->next == L || j > i) return -1; // 删除位置非法
    CircularLinkList q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return 0;
}

// 循环链表的遍历
void TraverseCircularList(CircularLinkList L) {
    CircularLinkList p = L->next;
    while (p != L) {
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
    if (!(*L)) return -1; // 分配失败
    (*L)->prior = NULL;
    (*L)->next = NULL;
    return 0;
}

// 双向链表的插入
Status InsertDLinkList(DLinkList L, int i, ElemType e) {
    DLinkList p = L;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return -1; // 插入位置非法
    DLinkList s = (DLinkList)malloc(sizeof(DNode));
    if (!s) return -1; // 分配失败
    s->data = e;
    s->next = p->next;//这行代码将新节点 s 的后继指针 next 指向当前节点 p 的后继节点。这样，新节点 s 就插入到了 p 和 p->next 之间。
    if (p->next) p->next->prior = s;
    s->prior = p;
    p->next = s;
    return 0;
}

// 双向链表的删除
Status DeleteDLinkList(DLinkList L, int i, ElemType* e) {
    DLinkList p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return -1; // 删除位置非法
    *e = p->data;
    if (p->next) p->next->prior = p->prior;
    p->prior->next = p->next;
    free(p);
    return 0;
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