#include<stdio.h>
#include<stdlib.h>

struct Book {
    char title[128];
    char author[40];
    struct Book *next;
};

void getInput(struct Book *book) {
    printf("请输入书名：");
    scanf("%127s", book->title);
    printf("请输入作者：");
    scanf("%39s", book->author);
}

void addBook(struct Book **library) {
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    
    getInput(book);
    
    // 将新书籍节点 book 的 next 指针指向当前图书馆链表的头节点
    book->next = *library;
    *library = book;
}

void printBook(struct Book *library) {
    struct Book *book = library;
    int count = 1;
    
    while (book != NULL) {
        printf("第%d本书\n", count);
        printf("书名：%s\n", book->title);
        printf("作者：%s\n", book->author);
        book = book->next;
        count++;
     }
}

void releaseLibrary(struct Book *library) {
     struct Book *current = library;
     while (current != NULL) {
         struct Book *next = current->next;
         free(current);
         current = next;
     }
}

int main() {
     struct Book *library = NULL; 
     char ch;      
     
     while (1) {
         printf("是否添加书籍？(y/n)\n");
         do {
             while ((ch = getchar()) != '\n' && ch != EOF); // Clear input buffer
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
     
     releaseLibrary(library);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
    
     return 0;
}
