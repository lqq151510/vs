#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

// 头插法创建链表
Node* createListByHeadInsert(int arr[], int n) {
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->data = arr[i];
        newNode->next = head;
        head = newNode;
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
    
    Node *head = createListByHeadInsert(arr, n);
    
    printf("链表元素: ");
    printList(head); // 输出顺序与原数组相反
    
    return 0;
}
