#include<stdio.h>
#include<stdlib.h>

// 栈的结构体定义
typedef struct Stack {
    int *data;      // 存储栈元素的数组
    int top;        // 栈顶指针
    int capacity;   // 栈的容量
} Stack;

// 初始化栈
Stack* initStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("内存分配失败！\n");
        exit(1);
    }
    stack->data = (int*)malloc(sizeof(int) * capacity);
    if (!stack->data) {
        printf("内存分配失败！\n");
        free(stack);
        exit(1);
    }
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// 判断栈是否为空
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// 判断栈是否已满
int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// 入栈操作
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("栈已满，无法入栈！\n");
        return;
    }
    stack->data[++stack->top] = value;
    stack->capacity++;
}

// 出栈操作
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法出栈！\n");
        return -1; // 返回-1表示出栈失败
    }
    return stack->data[stack->top--];
    stack->capacity--;
}

// 获取栈顶元素
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("栈为空，无法获取栈顶元素！\n");
        return -1; // 返回-1表示获取失败
    }
    return stack->data[stack->top];
}

// 释放栈的内存
void freeStack(Stack *stack) {
    if (stack) {
        free(stack->data);
        free(stack);
    }
}

// 队列的结构体定义
typedef struct Queue {
    int *data;      // 存储队列元素的数组
    int front;      // 队头指针
    int rear;       // 队尾指针
    int capacity;   // 队列的容量
    int size;       // 队列当前大小
} Queue;

// 初始化队列
Queue* initQueue(int capacity) {
    Queue *queue = (Queue*)malloc(sizeof(Queue));
    if (!queue) {
        printf("内存分配失败！\n");
        exit(1);
    }
    queue->data = (int*)malloc(sizeof(int) * capacity);
    if (!queue->data) {
        printf("内存分配失败！\n");
        free(queue);
        exit(1);
    }
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

// 判断队列是否为空
int isQueueEmpty(Queue *queue) {
    return queue->size == 0;
}

// 判断队列是否已满
int isQueueFull(Queue *queue) {
    return queue->size == queue->capacity;
}

// 入队操作
void enqueue(Queue *queue, int value) {
    if (isQueueFull(queue)) {
        printf("队列已满，无法入队！\n");
        return;
    }
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = value;
    queue->size++;
}

// 出队操作
int dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        printf("队列为空，无法出队！\n");
        return -1; // 返回-1表示出队失败
    }
    int value = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return value;
}

// 释放队列的内存
void freeQueue(Queue *queue) {
    if (queue) {
        free(queue->data);
        free(queue);
    }
}