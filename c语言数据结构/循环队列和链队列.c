#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
typedef int SElemType;

typedef struct {
    SElemType data[maxsize]; // 队列存储空间
    int front;               // 队首指针
    int rear;                // 队尾指针
} CircularQueue;

// 初始化循环队列
int InitQueue(CircularQueue *Q) {
    Q->front = 0;
    Q->rear = 0;
    return 0; // 初始化成功
}

// 入队操作
int EnQueue(CircularQueue *Q, SElemType e) {
    if ((Q->rear + 1) % maxsize == Q->front) { // 队列满
        printf("队列已满，无法入队！\n");
        return -1;
    }
    Q->data[Q->rear] = e; // 插入元素
    Q->rear = (Q->rear + 1) % maxsize; // 更新队尾指针
    return 0; // 入队成功
}

// 出队操作
int DeQueue(CircularQueue *Q, SElemType *e) {
    if (Q->front == Q->rear) { // 队列空
        printf("队列为空，无法出队！\n");
        return -1;
    }
    *e = Q->data[Q->front]; // 获取队首元素
    Q->front = (Q->front + 1) % maxsize; // 更新队首指针
    return 0; // 出队成功
}

// 求队列长度
int GetLength(CircularQueue *Q) {
    return (Q->rear - Q->front + maxsize) % maxsize; // 计算队列长度
}

// 链队列节点定义
typedef struct Node {
    SElemType data;       // 数据域
    struct Node *next;    // 指针域，指向下一个节点
} Node, *QueueNode;

// 链队列结构定义
typedef struct {
    QueueNode front;      // 队首指针
    QueueNode rear;       // 队尾指针
    int length;           // 队列长度
} LinkQueue;

// 初始化链队列
int InitLinkQueue(LinkQueue *Q) {
    Q->front = Q->rear = (QueueNode)malloc(sizeof(Node));
    if (!Q->front) {
        printf("内存分配失败！\n");
        return -1; // 初始化失败
    }
    Q->front->next = NULL;
    Q->length = 0;
    return 0; // 初始化成功
}

// 入队操作
int EnQueueLink(LinkQueue *Q, SElemType e) {
    QueueNode newNode = (QueueNode)malloc(sizeof(Node));
    if (!newNode) {
        printf("内存分配失败！\n");
        return -1; // 内存分配失败
    }
    newNode->data = e;
    newNode->next = NULL;
    Q->rear->next = newNode; // 将新节点插入到队尾
    Q->rear = newNode;       // 更新队尾指针
    Q->length++;             // 更新队列长度
    return 0; // 入队成功
}

// 出队操作
int DeQueueLink(LinkQueue *Q, SElemType *e) {
    if (Q->front == Q->rear) { // 队列空
        printf("队列为空，无法出队！\n");
        return -1;
    }
    QueueNode temp = Q->front->next; // 指向队首节点
    *e = temp->data;                // 获取队首元素
    Q->front->next = temp->next;    // 更新队首指针
    if (Q->rear == temp) {          // 如果队列只有一个节点
        Q->rear = Q->front;         // 更新队尾指针
    }
    free(temp);                     // 释放队首节点
    Q->length--;                    // 更新队列长度
    return 0; // 出队成功
}

// 求队列长度
int GetLengthLink(LinkQueue *Q) {
    return Q->length; // 返回队列长度
}