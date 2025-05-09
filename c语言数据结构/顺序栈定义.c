#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
typedef int SElemType;


// 顺序栈的结构体定义
typedef struct Stack {
      
    SElemType *base;
    SElemType *top;
    int  staclsize;
} SqStack;
SqStack s;

//顺序栈初始化
int InitStack(SqStack *S) {
    S->base = (SElemType *)malloc(maxsize * sizeof(SElemType));
    if (!S->base) {
        printf("内存分配失败！\n");
        return -1; // 初始化失败
    }
    S->top = S->base;
    S->staclsize = maxsize;
    return 0; // 初始化成功
}
int push(SqStack *S, SElemType elem)//插入
{
    if (S->top - S->base >= S->staclsize) {
        printf("栈已满，无法入栈！\n");
        return -1;
    }
    *(S->top) = elem;
    S->top++;
    return 0;
}
int pop(SqStack *S, SElemType *elem)//删除
{
    if (S->top == S->base) {
        printf("栈为空，无法出栈！\n");
        return -1;
    }
    *elem = *(--S->top); // 正确地通过指针返回弹出的值
    return 0;
}
