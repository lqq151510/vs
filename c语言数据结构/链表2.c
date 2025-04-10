#include<stdio.h>
#include<stdlib.h>
#include<string.h> // Ensure all required headers are included
typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* next;
    
} Node;

void bianli(Node *L); // Ensure the prototype matches the definition

Node* initlist()
{
    Node *head = (Node*)malloc(sizeof(Node));
    if (head == NULL) {
        return NULL; // 返回NULL表示内存分配失败
    }
    head->data = 0;
    head->next = NULL;
    return head; // 修复返回值
}


void freelist(Node *head)
{
    Node *current = head;
    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }
}

int inserthead(Node *head, ElemType e) 
{
    if (head == NULL) {
        return -1; // 错误码表示无效参数
    }

    Node *p = (Node*)malloc(sizeof(Node));
    if (p == NULL) {
        return -2; // 错误码表示内存分配失败
    }

    p->data = e;
    p->next = head->next;
    head->next = p;
    
    return 0; // 成功返回0
}

int insertwei(Node *head, ElemType e) 
{
    if (head == NULL) {
        return -1; // 错误码表示无效输入
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        return -2; // 错误码表示内存分配失败
    }
    
    newNode->data = e;
    newNode->next = NULL;
    // 找到链表末尾
    Node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    
    return 0; // 成功返回0
}

void bianli(Node *L) {
    if (L == NULL) {
        printf("链表为空\n");
        return;
    }
    Node *p = L->next;
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// 获取链表长度
int getLength(Node *head) {
    if (head == NULL) {
        return 0; // 空链表长度为0
    }
    int length = 0;
    Node *current = head->next; // 跳过头节点
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

int insertNode(Node *head, int pos, ElemType e) {
    // 检查位置有效性
    if (pos < 1) return 0;
    
    Node *current = head;
    int i = 0;
    
    // 找到插入位置的前一个节点
    while (current != NULL && i < pos-1) {
        current = current->next;
        i++;
    }
    
    // 如果位置超出链表长度
    if (current == NULL) {
        return 0; 
    }
    
    // 创建新节点并插入
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) return 0; // 内存分配失败
    
    newNode->data = e;
    newNode->next = current->next;
    current->next = newNode;
    
    return 1; // 插入成功
}

int delNode(Node *head, int pos) {
    // 检查位置有效性
    if (pos < 1) return 0;

    Node *current = head;
    int i = 0;

    // 找到删除位置的前一个节点
    while (current != NULL && i < pos - 1) {
        current = current->next;
        i++;
    }

    // 如果位置超出链表长度
    if (current == NULL || current->next == NULL) {
        return 0;
    }

    // 删除节点
    Node *p = current->next;
    current->next = p->next;
    free(p);

    return 1; // 删除成功
}

// 查找链表中值为e的节点，返回其位置（从1开始），未找到返回0
int findNode(Node *head, ElemType e) {
    if (head == NULL) {
        return 0; // 空链表返回0
    }
    int pos = 1;
    Node *current = head->next; // 跳过头节点
    while (current != NULL) {
        if (current->data == e) {
            return pos; // 找到返回位置
        }
        current = current->next;
        pos++;
    }
    return 0; // 未找到返回0
}

int main() {
    Node *list = initlist();
    if (list == NULL) {
        printf("初始化链表失败\n");
        return EXIT_FAILURE;
    }
    
    if (inserthead(list, 1) != 0 || inserthead(list, 2) != 0 || insertwei(list, 3) != 0) {
        printf("插入失败\n");
        freelist(list);
        return EXIT_FAILURE;
    }
    
    bianli(list);
    printf("链表长度: %d\n", getLength(list)); // 输出链表长度

    // 测试查找功能
    int pos = findNode(list, 2);
    if (pos != 0) {
        printf("值为2的节点位置: %d\n", pos);
    } else {
        printf("未找到值为2的节点\n");
    }

    // 测试删除功能
    if (delNode(list, 2)) {
        printf("删除位置2的节点成功\n");
    } else {
        printf("删除位置2的节点失败\n");
    }
    bianli(list);

    freelist(list);
    return EXIT_SUCCESS;
}

