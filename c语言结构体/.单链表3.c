#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};
void insertNode(struct node **head,int value);
void printNode(struct node *head);
void insertNode(struct node **head,int value)
{
    // 定义三个指针，分别指向前一个节点、当前节点和新节点
    struct node *previous;//前一个节点
    struct node *current; //当前节点
    struct node *new; //新节点
    // 初始化当前节点为头节点
    current=*head;
    // 初始化前一个节点为NULL
    previous=NULL;
    while(current!=NULL&&current->value<value)//找到插入位置
    {
        previous=current;
        current=current->next;
    }
    new=(struct node*)malloc(sizeof(struct node));
    if(new==NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    new->value=value;//赋值
    new->next=current;
    if (previous==NULL)
    {
        *head=new;
    }
    else
    {
        previous->next=new;
    }
    free(new);

}
void printNode(struct node *head)
{
    struct node *current=head;
    while(current!=NULL)
    {
        printf("%d ",current->value);
        current=current->next;
    }
    printf("\n");
}
int main()
{
struct node *head=NULL;
int input;
while(1)
{
    printf("请输入一个整数：");
    scanf("%d",&input);
    if(input==-1)
    {
        break;
    }
    insertNode(&head,input);
    printNode(head);
}
return 0;
}