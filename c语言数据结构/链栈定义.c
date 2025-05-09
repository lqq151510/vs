#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
typedef int SElemType;
//链栈的结构体定义
typedef struct StackNode {
      
    SElemType data;//数据域
    struct StackNode *next;//指针域
} SqStack,*LinkStack;
int InitLinkList(LinkStack *S) {
    *S = (LinkStack)malloc(sizeof(LinkStack));
        if (!(*S)) {
        printf("内存分配失败！\n");
        return -1; // 初始化失败
    }
    (*S)->next = NULL;
    return 0; // 初始化成功
}
LinkStack s;
int stackLength(LinkStack *S)
{
   int length=0;
   LinkStack p=*S;
   while(p)
   {
    length++;
    p=p->next;
   }
   return length;
}

void push(LinkStack *S, int e) // 入栈
{
    LinkStack q = (LinkStack)malloc(sizeof(SqStack)); // 分配内存
    if (!q) {
        printf("内存分配失败！\n");
        return;
    }
    q->data = e;
    q->next = *S; // 新节点指向当前栈顶
    *S = q;       // 更新栈顶指针
}

void pop(LinkStack *S, int *e) // 出栈
{
    if (*S == NULL) { // 检查链栈是否为空
        printf("链栈为空，无法出栈！\n");
        return;
    }
    LinkStack q = *S; // 指向栈顶节点
    *e = q->data;     // 获取栈顶节点的数据
    *S = q->next;     // 更新栈顶指针
    free(q);          // 释放栈顶节点的内存
}
