#include<stdio.h>
#include<stdlib.h>

// 定义链表节点
typedef struct Node {
    int data;           // 节点数据
    struct Node *next;  // 指向下一个节点的指针
} Node;

// 定义栈结构
typedef struct Stack {
    Node *top;          // 栈顶指针
} Stack;

// 初始化栈
Stack* initStack() {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

// 入栈
void push(Stack *stack, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("内存分配失败！\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

// 出栈
int pop(Stack *stack) {
    if (!stack->top) {
        printf("栈为空，无法出栈！\n");
        return -1; // 返回-1表示栈为空
    }
    Node *temp = stack->top;
    int value = temp->data;
    stack->top = temp->next;
    free(temp);
    return value;
}

// 销毁栈
void destroyStack(Stack *stack) {
    Node *current = stack->top;
    while (current) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
    free(stack);
}

// 测试栈功能
int main() {
    Stack *stack = initStack();
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("出栈元素: %d\n", pop(stack));
    printf("出栈元素: %d\n", pop(stack));

    destroyStack(stack);
    return 0;
}