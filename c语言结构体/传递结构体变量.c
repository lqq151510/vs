#include <stdio.h>
#include <stdlib.h>
// int main()
// { 
//    // 定义一个结构体类型Test，包含两个整型成员x和y
//    struct Test
//    {
//        int x;
//        int y;
//    }t1,t2; // 声明两个Test类型的变量t1和t2
//    // 为t1的成员x赋值为3
//    t1.x=3;
//    // 为t1的成员y赋值为4
//    t1.y=4;
//    // 将t1的值赋给t2，即t2的成员x和y分别被赋值为t1的成员x和y的值
//    t2=t1;
//    // 打印t2的成员x和y的值，格式化输出，%d表示整数
//    printf("t2x2=%d t2,t=%d\n",t2.x,t2.y);
//    // 返回0，表示程序正常结束
//    return 0;
// }
struct Date{
    int year;
    int month;
    int day;
};
struct Book{
    char title[50];
    char author[50];
    float price;
    struct Date date;
    char publisher[40];
};
void getInput(struct Book *book);

void printBook(struct Book *book);
void getInput(struct Book *book)
{
    printf("请输入图书信息：\n");
    printf("书名：");
    scanf("%s",book->title);
    printf("作者：");
    scanf("%s",book->author);
    printf("价格：");
    scanf("%f",&book->price);
    printf("出版日期：");
    scanf("%d%d%d",&book->date.year,&book->date.month,&book->date.day);
    printf("出版社：");
    scanf("%s",book->publisher);
    return book;
}


// 定义一个函数，用于打印书籍信息
void printBook(struct Book *book)
{
    // 打印书籍的标题
    printf("书名：%s\n",book->title);
    // 打印书籍的作者
    printf("作者：%s\n",book->author);
    // 打印书籍的价格，保留两位小数
    printf("价格：%.2f\n",book->price);
    // 打印书籍的出版日期，包括年、月、日
    printf("出版日期：%d年%d月%d日\n",book->date.year,book->date.month,book->date.day);
    // 打印书籍的出版社
    printf("出版社：%s\n",book->publisher);
}

int main()
{
    // struct Book b1,b2;
    // getInput(&b1);
    // getInput(&b2);
    // printf("图书1信息：\n");
    // printBook(&b1);
    // printf("图书2信息：\n");
    // printBook(&b2);
    // return 0;
    struct  Book *b1,*b2;
    b1=(struct Book *)malloc(sizeof(struct Book));
    b2=(struct Book *)malloc(sizeof(struct Book));
    if (b1==NULL||b2==NULL)
    {
        printf("内存分配失败！\n");
        exit(1);
    }
     getInput(&b1);
    getInput(&b2);
    printf("图书1信息：\n");
    printBook(&b1);
    printf("图书2信息：\n");
    printBook(&b2);
    free(b1);
    free(b2);
    return 0;
    

    
}
