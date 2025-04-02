#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 使用尾插法创建链表（修正了函数名）
Node* createListByTailInsert(int arr[], int n) {
    if (n == 0) return NULL;
    
    Node *head = (Node*)malloc(sizeof(Node));
    head->data = arr[0];
    head->next = NULL;
    
    Node *tail = head; // 初始时尾指针指向头节点
    
    for (int i = 1; i < n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = NULL;
        tail->next = newNode; // 将当前尾节点的next指向新节点
        tail = newNode;       // 更新尾指针为新节点
        free(newNode);
    }
    
    return head;
}

// 打印链表
void printList(Node *head) {
    Node *p = head;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    Node *head = createListByTailInsert(arr, n);
    
    printf("链表元素: ");
    printList(head); // 现在会正确输出: 1 2 3 4 5
    
    return 0;
}
