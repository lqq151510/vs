#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

#define LINKLIST_OK 1
#define LINKLIST_ERROR 0

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
int InitList(LinkList *L) {
    if (L == NULL) return LINKLIST_ERROR;
    L->head = NULL;
    L->length = 0;
    return LINKLIST_OK;
}

// 销毁整个链表（整体删除）
int DestroyList(LinkList *L) {
    if (L == NULL) return LINKLIST_ERROR;
    
    Node *current = L->head;
    Node *next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    L->head = NULL;
    L->length = 0;
    
    return LINKLIST_OK;
}

int main() {
    LinkList list = {0};
    
    // 初始化链表
    if (InitList(&list) == LINKLIST_OK) {
        printf("链表初始化成功\n");
        
        // ...这里可以添加创建链表的代码...
        
        // 销毁链表
        if (DestroyList(&list) == LINKLIST_OK) {
            printf("链表已成功销毁\n");
        } else {
            printf("链表销毁失败\n");
        }
    } else {
        printf("链表初始化失败\n");
    }
    
    return EXIT_SUCCESS;  // 使用标准退出码宏定义替代0
}
