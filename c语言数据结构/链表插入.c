#include <stdio.h>
#include <stdlib.h>  // 添加malloc需要的头文件

#define Ok 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int ElemType;  // 修正拼写错误(Elemtype -> ElemType)
typedef int Status;

// 正确的链表节点定义
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct LinkList {
    Node *head;  // 链表头指针
    int length;  // 链表长度
} LinkList;

// 初始化链表函数
Status InitList(LinkList *L) {
    L->head = NULL;
    L->length = 0;
    return Ok;
}

// 插入元素函数(改名为更合适的名称)
Status ListInsert(LinkList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        return ERROR;
    }
    
    Node *p = L->head;
    Node *prev = NULL;
    int j = 1;
    
    // 找到插入位置的前驱节点
    while (p && j < i) {
        prev = p;
        p = p->next;
        j++;
    }
    
    // 创建新节点
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode) {
        return ERROR; // 内存分配失败
    }
    
    newNode->data = e;
    
    if (prev == NULL) { // 在头部插入
        newNode->next = L->head;
        L->head = newNode;
    } else { // 在中间或尾部插入
        newNode->next = prev->next;
        prev->next = newNode;
    }
    
    L->length++;
    free(p);
    free(prev);
    free(newNode);

     return Ok;
}
