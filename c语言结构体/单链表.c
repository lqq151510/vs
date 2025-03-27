#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>  // 新增用于tolower()

struct Book {
    char title[128];
    char author[40];
    struct Book *next;
};

void getInput(struct Book *book) {
    printf("请输入书名：");
    scanf(" %127[^\n]", book->title);  // 修改为可以读取包含空格的字符串
    
    printf("请输入作者：");
    scanf(" %39[^\n]", book->author);  // 修改为可以读取包含空格的字符串
}

void addBook(struct Book **library) {
    struct Book *book = (struct Book *)malloc(sizeof(struct Book));
    if (book == NULL) {
        printf("内存分配失败\n");
        exit(1);
    }
    
    getInput(book);
    
    // 简化链表添加逻辑
    book->next = *library;
    *library = book;
}

void printBook(struct Book *library) {
    struct Book *book = library;
    int count = 1;
    
    while (book != NULL) {
        printf("\n第%d本书\n", count);
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
        printf("\n是否添加书籍？(y/n)\n");
        
        do {
            ch = tolower(getchar());  // 转换为小写统一处理
            // 清除输入缓冲区剩余字符
            while ((ch != '\n') && (ch != EOF)) { 
                ch = getchar();
            }
            if (ch == EOF) { // Handle EOF case
                return 0; 
            }
            ch = tolower(getchar());
        } while (ch != 'y' && ch != 'n');
        
        if (ch == 'n') {
            break;
        }
        
        addBook(&library);
        
        // Clear input buffer after adding a book
        while ((ch = getchar()) != '\n' && ch != EOF);
        
        printf("\n添加成功\n");
    }
    
    printf("\n请问是否需要打印图书信息(y/n)\n");
    
     do {
         ch = tolower(getchar());
         while ((ch != '\n') && (ch != EOF)) { 
             ch = getchar();
         }
         if (ch == EOF) { 
             releaseLibrary(library);
             return 0; 
         }
         ch = tolower(getchar());
     } while (ch != 'y' && ch != 'n');
     
     if (ch == 'y') {
         printBook(library);
     }
     
     releaseLibrary(library);                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
     
     return 0;
}
