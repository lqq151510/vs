#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *next,*prev;
} Node;
Node* ininlist()
{
    Node *head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    head->prev=NULL;
    return head;

} 
int inserthead(Node *L, int e)
{
    Node *n = (Node*)malloc(sizeof(Node)); // 修复内存分配错误
    n->data = e;
    n->prev = L;
    n->next = L->next;
    if (L->next != NULL)
    {
        L->next->prev = n;
    }
    L->next = n;
    return 1;
}

void listnode(Node *L)
{
    Node *current = L->next; // 跳过头节点，第一个数据
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node *list = ininlist(); // 初始化链表

    // 插入一些节点
    inserthead(list, 10);
    inserthead(list, 20);
    inserthead(list, 30);

    // 打印链表
    printf("链表中的节点数据: ");
    listnode(list);

    return 0;
}