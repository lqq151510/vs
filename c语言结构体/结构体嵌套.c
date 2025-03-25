#include<stdio.h>
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
}book={"c语言","张三",50.0,{2020,10,1},"清华大学出版社"};
int main()
{
    // 打印提示信息，要求用户输入书名
    printf("请输入书名：");
    // 使用scanf函数读取用户输入的书名，并存储到book.title中
    scanf("%s",book.title);
    // 打印提示信息，要求用户输入作者
    printf("请输入作者：");
    // 使用scanf函数读取用户输入的作者，并存储到book.author中
    scanf("%s",book.author);
    // 打印提示信息，要求用户输入价格
    printf("请输入价格：");
    // 使用scanf函数读取用户输入的价格，并存储到book.price中
    scanf("%f",&book.price);
    // 打印提示信息，要求用户输入出版日期
    printf("请输入出版日期：");
    // 使用scanf函数读取用户输入的年、月、日，并分别存储到book.date.year、book.date.month、book.date.day中
    scanf("%d%d%d",&book.date.year,&book.date.month,&book.date.day);
    // 打印提示信息，要求用户输入出版社
    printf("请输入出版社：");
    // 使用scanf函数读取用户输入的出版社，并存储到book.publisher中
    scanf("%s",book.publisher);
    // 返回0，表示程序正常结束
    return 0;
}