#include <stdio.h>
#include <stdlib.h>

struct Node {
    int Data;
    struct Node *Next;
};

typedef struct Node *PtrToNode;
typedef PtrToNode List;

List Merge(List L1, List L2) {
    List dummy = (List)malloc(sizeof(struct Node)); // 创建一个虚拟头结点
    PtrToNode tail = dummy; // 指向结果链表的尾部
    PtrToNode p1 = L1->Next, p2 = L2->Next; // 跳过头结点

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

    // 将剩余的链表接到结果链表后面
    tail->Next = p1 ? p1 : p2;

    // 释放原链表的头结点
    L1->Next = NULL;
    L2->Next = NULL;
    free(L1);
    free(L2);

    List result = dummy->Next;
    free(dummy); // 释放虚拟头结点
    return result;
}