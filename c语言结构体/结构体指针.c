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
    struct Book *p;
    p=&book;
    // 打印提示信息，要求用户输入书名
 printf("请输入书名：%s\n",p->title);//printf("请输入书名：%s\n",(*p).title);
    // 打印提示信息，要求用户输入作者
 printf("请输入作者：%s\n",p->author);//printf("请输入作者：%s\n",(*p).author);
    // 打印提示信息，要求用户输入价格
 printf("请输入价格：%f\n",p->price);//printf("请输入价格：%f\n",(*p).price);

    // 打印提示信息，要求用户输入出版日期
 printf("请输入出版日期：%d年%d月%d日\n",p->date.year,p->date.month,p->date.day);//printf("请输入出版日期：%d年%d月%d日\n",(*p).date.year,(*p).date.month,(*p).date.day);
    // 打印提示信息，要求用户输入出版社
 printf("请输入出版社：%s\n",p->publisher);//printf("请输入出版社：%s\n",(*p).publisher);
    return 0;
}