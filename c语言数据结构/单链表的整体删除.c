#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef int Status;

#define OK 1
#define ERROR 0

// 链表节点定义
typedef struct Node {
    ElemType data;
    struct Node *next;
} Node;

typedef struct LinkList {
    Node *head;  // 链表头指针
    int length;  // 链表长度
} LinkList;

// 初始化链表
Status InitList(LinkList *L) {
    L->head = NULL;
    L->length = 0;
    return OK;
}

// 销毁整个链表（整体删除）
Status DestroyList(LinkList *L) {
  Node *current=L->head;
  Node *next;
  while(current!=NULL)
  {
    next=current->next;
    free(current);
    current=next;
  }
  L->head=NULL;
  L->length=0;
  return OK;
}

int main() {
    LinkList list;
    
    // 初始化链表
    if (InitList(&list) == OK) {
        printf("链表初始化成功\n");
        
        // ...这里可以添加创建链表的代码...
        
        // 销毁链表
        if (DestroyList(&list) == OK) {
            printf("链表已成功销毁\n");
        } else {
            printf("链表销毁失败\n");
        }
    } else {
        printf("链表初始化失败\n");
    }
    
    return 0;
}
