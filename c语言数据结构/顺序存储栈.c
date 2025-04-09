#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100 // 栈的最大容量
typedef int ElemType;

typedef struct {
    ElemType data[MAXSIZE];
    int top;   // 栈顶指针
    int base;  // 栈底指针
} SqStack;

// 初始化栈
void InitStack(SqStack *s) {
    s->top = -1;//初始化为-1表示栈为空
    s->base = 0; // 栈底指针初始化为0
}

// 判断栈是否为空
int StackEmpty(SqStack *s) {
    return s->top < s->base;//如果栈为空，栈顶指针会等于栈底指针，因此当栈顶指针小于栈底指针时，表示栈为空。
   // 实现原理
}

// 入栈操作
int Push(SqStack *s, ElemType e) {
    if (s->top == MAXSIZE - 1) {
        printf("栈满，无法入栈！\n");
        return 0;
    }
    s->data[++s->top] = e; // 简化操作
    return 1;
}

// 出栈操作
int Pop(SqStack *s, ElemType *e) {
    if (StackEmpty(s)) {
        printf("栈空，无法出栈！\n");
        return 0;
    }
    *e = s->data[s->top--]; // 简化操作
    return 1;
}

// 销毁栈（可选，顺序栈不需要动态分配内存）
void DestroyStack(SqStack *s) {
    s->top = -1;
    s->base = 0; // 重置栈底指针
}

// 测试代码
int main() {
    SqStack s;
    ElemType e;

    InitStack(&s);
    Push(&s, 10);
    Push(&s, 20);
    Push(&s, 30);

    while (!StackEmpty(&s)) {
        Pop(&s, &e);
        printf("出栈元素: %d\n", e);
    }

    return 0;
}
