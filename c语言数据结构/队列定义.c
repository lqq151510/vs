#include<stdio.h>
#include<stdlib.h>
#define maxsize 10
typedef int SElemType;
typedef struct  {
      
    SElemType *front;//对首
    SElemType *rear;//队尾
    int  data[maxsize];
} SqQuene;
int InitSQuene(SqQuene *S) {
    S->front = S->data; // 初始化队首指针
    S->rear = S->data;  // 初始化队尾指针
    for (int i = 0; i < maxsize; i++) {
        S->data[i] = 0; // 初始化队列数据为 0
    }
    return 0; // 初始化成功
}

// 顺序队列入队
int EnQueue(SqQuene *S, SElemType e) {
    if (S->rear - S->data >= maxsize) { // 队列满
        printf("队列已满，无法入队！\n");
        return -1;
    }
    *S->rear = e; // 将元素插入队尾
    S->rear++;    // 更新队尾指针
    return 0; // 入队成功
}

// 顺序队列出队
int DeQueue(SqQuene *S, SElemType *e) {
    if (S->front == S->rear) { // 队列空
        printf("队列为空，无法出队！\n");
        return -1;
    }
    *e = *S->front; // 获取队首元素
    S->front++;     // 更新队首指针
    return 0; // 出队成功
}

// 求队列长度
int GetLength(SqQuene *S) {
    return S->rear - S->front; // 队列长度为队尾指针减去队首指针
}
