#include<stdio.h>
#define Ok 1
#define ERROR 0
#define TRUE 1
#define FALSE 
#define MAXSIZE 100
//插入  
// typedef int ElemType;
// typedef int Status; // 添加Status类型定义

// typedef struct SqList {
//     ElemType data[MAXSIZE];
//     int length;
// } SqList; // 移除了多余的分号并添加了结构体名称

// Status ListInsert(SqList *L, int i, ElemType e) { // 更明确的函数名
//     if(L == NULL) {
//         return ERROR;
//     }
    
//     if(i < 1 || i > L->length + 1) {
//         return ERROR;
//     }
//     if(L->length >= MAXSIZE-1) { //选择MAXSIZE还是MAXSIZE-1取决于你的设计：
//         //>= MAXSIZE：完全不允许达到MAXSIZE
//        // >= MAXSIZE-1：保留一个位置（某些实现可能需要）
//         //在0-based索引的数组中，通常使用前者
//         return ERROR;
//     }
    
//     for(int j = L->length; j >= i; j--) {
//         L->data[j] = L->data[j-1];
//     }
    
//     L->data[i-1] = e;
//     L->length++;
    
//     return Ok; // 添加成功返回值
// }



//删除
typedef int elemtype;
typedef int status;
typedef struct SqList {
    elemtype data[MAXSIZE];
    int length;
} SqList;

status ListInsert(SqList *L, int i, elemtype *e)
{
    if(L=NULL)
    {
        return ERROR;// 添加了错误返回值
    }
    if(i<1||i>L->length+1)
    {
        return ERROR;// 添加了错误返回值
    }
   *e= L->data[i-1];
   if (i<L->length)
   {
   for(int k=i;k<L->length;k++)
   {
       L->data[k]=L->data[k+1];
   }
   }
   L->length--;
   return Ok;
   }
   