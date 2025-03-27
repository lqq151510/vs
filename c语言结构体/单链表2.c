#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Book {
    // 用于存储书名的字符数组，最大长度为127个字符，加上一个终止符'\0'共128个字符
    char title[128];
    // 用于存储作者名的字符数组，最大长度为39个字符，加上一个终止符'\0'共40个字符
    char author[40];
    // 指向另一个Book结构体的指针，用于实现链表结构
    struct Book *next;
};

void getInput(struct Book *book) {
    printf("请输入书名：");
    scanf("%127s", book->title);
    printf("请输入作者：");
    scanf("%39s", book->author);
}
// void addBook(struct Book **library)//library是一个指向指针的指针，指向的是结构体指针,链表的头结点
//  {
//     // 使用 malloc 函数动态分配内存，用于存储新的书籍节点
//     struct Book *book = (struct Book *)malloc(sizeof(struct Book));
//     static struct Book *tail;
//     // 检查内存分配是否成功，如果失败则输出错误信息并退出程序
//     if (book == NULL) {
//         printf("内存分配失败\n");
//         exit(1);
//     }
    
//     // 调用 getInput 函数，获取用户输入的书籍信息，并填充到新分配的书籍节点中
//     getInput(book);
//     if(*library == NULL)
//     {
//         *library = book;
//         book->next=NULL;
//     }
//     else
//     {
//         struct Book *current=*library;
//         while(current ->next!=NULL)
//         {
//             current=current->next;
//         }
//         current->next=book;
//     }
// }
void addBook(struct Book **library) {
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    static struct Book *tail = NULL;  // 显式初始化为NULL
    
    if (book == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    
    getInput(book);
    book->next = NULL;
    
    if(*library == NULL) {
        *library = book;
        tail = book;  // 更新tail指针
    } else {
        tail->next = book;  // 直接使用tail添加新节点
        tail = book;       // 更新tail指针
    }
}//效率高.

struct Book *searchBook(struct Book *library, char *target)
{
    struct Book *book=library;
    while(book!=NULL)
    {
        if(!strcmp(book->title,target)||!strcmp(book->author,target))
        {
            break; 
        }
        book=book->next;
    }
    return book;
}
void printBook2(struct Book *Book)
{
    if(Book!=NULL)
    {
        printf("书名：%s\n",Book->title);
        printf("作者：%s\n",Book->author);
    }
    else
    {
        printf("没有找到该书籍\n");
    }
}
void printBook(struct Book *library) {
   struct Book *book=library;
   int count=1;
while(book!=NULL)
{
    printf("第%d本书\n",count);
    printf("书名：%s\n", book->title);
    printf("作者：%s\n", book->author);
    book=book->next;
    count++;
}
}
void releaselibrary(struct Book *library)
{
    struct Book *current=library;
    while(current!=NULL)
    {
       struct Book *next=current->next;
       free(current);
       current=next;
    }
}

int main() {
    struct Book *library = NULL;  // 初始化图书馆指针为NULL，表示图书馆为空
    char ch;            // 用于存储用户输入的字符
    char i[128];
    struct Book *book;
    
    while (1) { // 无限循环，直到用户选择不添加书籍
        printf("是否添加书籍？(y/n)\n"); // 提示用户是否添加书籍
        do {
            while ((ch = getchar()) != '\n' && ch != EOF); // Clear input buffer
            // 从标准输入读取下一个字符，并将其存储在变量ch中
            ch = getchar();
        } while (ch != 'y' && ch != 'n');
        
        if (ch == 'n') {
            break;
        } else {
            addBook(&library);
        }
    }
    
    printf("请问是否需要打印图书信息？(y/n)\n");
    do {
        while ((ch = getchar()) != '\n' && ch != EOF); // Clear input buffer
        ch = getchar();
    } while (ch != 'y' && ch != 'n');
    
    if (ch == 'y') {
        printBook(library);
    }
    printf("请输入书名和作者");
    scanf("%s\n",&i);
    book=searchBook(library,i);
    if (book==NULL)
    {
        printf("没有找到该书籍\n");
    }
    else
    {
        do
        {
            printf("已经找到");
            printBook2(book);
        } while((book=searchBook(book->next,i))!=NULL);
        
        printBook2(book);
    }
   
    
    releaselibrary(library);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
   
    return 0;
}
