#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode   Next;
};
typedef PtrToNode List;

List Merge(List L1, List L2) {
    List dummy = (List)malloc(sizeof(struct Node)); // 创建一个虚拟头结点
    PtrToNode tail = dummy; // 指向结果链表的尾部

    PtrToNode p1 = L1->Next; // 跳过L1的头结点
    PtrToNode p2 = L2->Next; // 跳过L2的头结点

    while (p1 && p2) {
        if (p1->Data <= p2->Data) {
            tail->Next = p1;
            p1 = p1->Next;
        } else {
            tail->Next = p2;
            p2 = p2->Next;
        }
        tail = tail->Next;
    }

    // 将剩余的节点接到结果链表后面
    if (p1) tail->Next = p1;
    if (p2) tail->Next = p2;

    L1->Next = NULL; // 清空原链表L1
    L2->Next = NULL; // 清空原链表L2

    List result = dummy->Next; // 获取结果链表的头结点
    free(dummy); // 释放虚拟头结点
    return result;
}
