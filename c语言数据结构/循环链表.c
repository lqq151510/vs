#include<stdio.h>
#include<stdlib.h>

#define END_FLAG 9999

typedef struct node
{
    int data;
    struct node *next;
} Node;

// 定义一个类型别名 LinkList，它表示指向 Node 结构体的指针
typedef Node *LinkList;

LinkList createLinkList()
{
    LinkList head = (LinkList)malloc(sizeof(Node));
    head->next = head;  // 初始时指向自己
    head->data = -1;    // 头节点数据可设为无效值
    
    LinkList p = head;
    int x;
    
    printf("请输入数字(输入%d结束): ", END_FLAG);
    scanf("%d", &x);
    
    while(x != END_FLAG)
    {
        LinkList s = (LinkList)malloc(sizeof(Node));
        s->data = x;
        p->next = s;
        p = s;
        scanf("%d", &x);
    }
    
    p->next = head;  // 最后一个节点指向头节点形成循环
    return head;
}

void printLinkList(LinkList head)
{
    if(head == NULL || head->next == head)
    {
        printf("链表为空\n");
        return;
    }
    
    LinkList p = head->next;
    
    while(p != head)
    {
        printf("%d ", p->data);
        p = p->next;
        
        // 安全措施，防止错误的循环链表导致无限循环
        if(p == NULL) 
        {
            printf("\n错误：链表未正确形成循环\n");
            break;
        }
    }
    
    printf("\n");
}

void freeLinkList(LinkList head)
{
    if(head == NULL) return;
    
    LinkList p = head->next;
    
    while(p != head)
    {
        LinkList temp = p;
        p = p->next;
        free(temp);
        
        // 防止错误的循环链表导致无限循环
        if(p == NULL) break;  
        
        // 避免对已释放内存的访问（仅当p==head时退出）
        
         /* 
         如果链表中只有一个节点（头节点），这个条件已经由while条件处理。
         如果链表有多个节点，最终会回到head。
         */
         
         /* 
         特别注意：在调试阶段可以添加计数器，
         比如限制最大循环次数为某个合理值，
         防止错误的链表结构导致无限循环。
         */
         
         static int max_count = 1000;   //示例值
         static int count =0 ;
         
         if(count++ > max_count){
             printf("可能的内存泄漏或链表结构错误\n");
             break ;
         }
         
     }
     
     free(head);   //最后释放头节点 
}

int main()
{
    LinkList head = createLinkList();
    printLinkList(head);
    freeLinkList(head);
    return 0;
}
