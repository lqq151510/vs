#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createCircularList(int n) {
    Node *head = NULL, *prev = NULL;
    for (int i = 1; i <= n; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        if (head == NULL) {
            head = newNode;
        } else {
            prev->next = newNode;//将前一个节点的 next 指针指向新节点。
        }
        prev = newNode;//更新前一个节点指针。
    }
    prev->next = head; //将最后一个节点的 next 指针指向头节点，形成环形链表。
    return head;
}

int josephus(int n, int k) {
    if (n == 1) return 1;
    
    // Create circular linked list
    Node *head = createCircularList(n);
    Node *curr = head, *prev = NULL;
    
    while (curr->next != curr) { // 找到第 k 个节点。
       
        for (int i = 1; i < k; i++) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        free(curr);
        curr = prev->next;
    }
    
    int result = curr->data;
    free(curr);
    return result;
}

int main() {
    int n, k;
    printf("总人数: ");
    scanf("%d", &n);
    printf("请输入计数间隔: ");
    scanf("%d", &k);
    
    printf("天选之人是 %d\n", josephus(n, k));
    
    return 0;
}
