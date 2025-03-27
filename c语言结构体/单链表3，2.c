#include<stdio.h>
#include<stdlib.h>
struct node
{
    int value;
    struct node *next;
};
void insertNode(struct node **head,int value);
void printNode(struct node *head);
void deleteNode(struct node **head,int value);

void insertNode(struct node **head,int value)
{
    struct node *previous;
    struct node *current;
    struct node *new_node; // 改名
    
    current=*head;
    previous=NULL;
    
    while(current!=NULL && current->value<value)
    {
        previous=current;
        current=current->next;
    }
    
    new_node=(struct node*)malloc(sizeof(struct node));
    if(new_node==NULL)
    {
        printf("内存分配失败\n");
        exit(1);
    }
    
    new_node->value=value; 
    new_node->next=current;
    
    if(previous==NULL)
    {
        *head=new_node;
    }
    else
    {
        previous->next=new_node;
    }
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

void deleteNode(struct node **head,int value)
{
    if(head == NULL || *head == NULL) // 添加空指针检查
        return;

    struct node *previous;
    struct node *current;

    current=*head;
    previous=NULL;

     while(current!=NULL && current->value!=value)
     {
         previous=current;
         current=current->next; 
     }

     if(current==NULL)
     {
         printf("没有找到要删除的节点\n");
         return; 
     }

     if(previous==NULL)
     {
         *head=current->next; 
     }
     else{
         previous->next=current->next; 
     }

     free(current); 
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

    printf("开始删除"); 

    while(1) 
    {  
        printf("请输入一个整数：");  
        scanf("%d",&input);  

        if(input==-1)  
        {  
            break;  
        }  

        deleteNode(&head,input);  
        printNode(head);  
 }  

 return 0;  
}
