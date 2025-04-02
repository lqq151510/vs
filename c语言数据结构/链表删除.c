#include <stdio.h>
#include <stdlib.h>

#define Ok 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

// 定义元素类型为整型
typedef int ElemType;
// 定义状态类型为整型
typedef int Status;
// 定义链表节点结构体
typedef struct Node {
    ElemType data;  // 节点数据域，存储元素值
    struct Node *next;  // 节点指针域，指向下一个节点
} Node;
// 定义链表结构体
typedef struct LinkList {
    Node *head;  // 链表头指针，指向链表的第一个节点
    int length;  // 链表长度，记录链表中节点的个数
} LinkList;

// 初始化链表函数
// 参数：L - 指向链表结构体的指针
// 返回值：Status - 表示初始化操作的结果
Status InitList(LinkList *L) {
    L->head = NULL;  // 将链表头指针初始化为NULL，表示链表为空
    L->length = 0;  // 将链表长度初始化为0，表示链表中没有节点
    return Ok;  // 返回操作成功状态
}

// 删除链表中的节点
// 参数：L - 指向链表结构体的指针，i - 要删除的节点位置
// 返回值：Status - 表示删除操作的结果
Status ListDelete(LinkList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) {
        return ERROR;
    }

    Node *p = L->head;
    Node *prev = NULL;

    // 查找要删除的节点
    for (int j = 1; j < i; j++) {
        prev = p;
        p = p->next;
        if (!p) {
            return ERROR;
        }
    }

    // 保存被删除节点的数据
    *e = p->data;

    // 删除头节点的情况
    if (i == 1) {
        L->head = p->next;
    } else {
        prev->next = p->next;
    }

    // 释放被删除节点的内存
    free(p);

    // 更新链表长度
    L->length--;

    return Ok;
}
