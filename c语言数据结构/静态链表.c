#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000  // 定义静态链表的最大容量
// 定义静态链表的结点结构
typedef struct{
    int data;//数据域，用于存储数据
    int next;//游标域，用于存储下一个结点的索引
}Component,StaticLinkList[MAXSIZE];  // Component为结点类型，StaticLinkList为静态链表类型
// 初始化静态链表
int InitList(StaticLinkList L){
    int i;
    // 遍历静态链表的所有结点（除了最后一个结点）
    for(i=0;i<MAXSIZE-1;i++){
        L[i].next=i+1;  // 将每个结点的游标指向下一个结点
    }
    L[MAXSIZE-1].next=0;  // 将最后一个结点的游标指向0，表示链表结束
    return 0;  // 返回0表示初始化成功
}
// 从备用链表中分配一个空闲结点
int Malloc_SLL(StaticLinkList L) {
    int i = L[0].next; // 获取第一个备用结点的索引
    
    if(i) { // 如果有备用结点
        L[0].next = L[i].next; // 更新备用链表头结点的next
    }
    
    return i; // 返回分配的结点索引，0表示分配失败
}
// 将指定结点回收到备用链表
void Free_SLL(StaticLinkList L, int k) {
    L[k].next = L[0].next; // 将要释放的结点指向当前第一个备用结点
    L[0].next = k;         // 将头结点指向新释放的结点
}
// 在静态链表L的第i个位置前插入元素e
int ListInsert(StaticLinkList L, int i, int e) {
    if(i < 1 || i > Malloc_SLL(L) + 1) {
        return -1; // 插入位置不合法
    }
    
    int k = MAXSIZE - 1; // k指向头结点（最后一个元素）
    int new_node = Malloc_SLL(L); // 分配新结点
    
    if(new_node) {
        for(int j = 1; j < i; j++) { // 找到第i-1个元素的位置k
            k = L[k].next;
        }
        
        L[new_node].data = e;          // 设置新结点的数据域
        L[new_node].next = L[k].next;   // new_node指向原第i个元素
        L[k].next = new_node;           // i-1位置的元素指向new_node
        
        return new_node;
    }
    
    return -2; // new_node为0表示空间不足，插入失败
}
// 删除静态链表L的第i个位置的元素，并用e返回其值
int ListDelete(StaticLinkList L, int i, int *e) {
    if(i < 1 || i > Malloc_SLL(L)) {
        return -1; // 删除位置不合法
    }
    
    int k = MAXSIZE - 1;     // k指向头结点
    
    for(int j = 1; j < i; j++) {   //找到第i-1个元素的位置k 
        k = L[k].next;
    }
    
    int del_node = L[k].next;
    
    *e = L[del_node].data;
    
    L[k].next = L[del_node].next;
    
    Free_SLL(L, del_node);
    
    return del_node;
}
int main() {
    StaticLinkList SSL;
    
    InitList(SSL);      		//初始化静态链表
    
    int pos,e;
    
    pos=ListInsert(SSL,1,10);  	//在第1个位置插入10
    
    if(pos>0){
        printf("插入成功！\n");
    }else{
        printf("插入失败！\n");
    }
    
    if(ListDelete(SSL,pos,&e)==pos){  
        printf("删除成功，被删除的元素值为%d\n",e);
    }else{
        printf("删除失败！\n"); 
    }
    
    return EXIT_SUCCESS;
} 
