#include<stdio.h>
struct Book
{
    char title[120];
    char author[40];
    float  price;
    unsigned int date;
    char publisher[40];
}book;
int main()
{
    
    printf("请输入书名：");
    scanf("%s",book.title);
    printf("请输入作者：");
    scanf("%s",book.author);
    printf("请输入价格：");
    scanf("%f",&book.price);
    printf("请输入出版日期：");
    scanf("%d",&book.date);
    printf("请输入出版社：");
    scanf("%s",book.publisher);
printf("数据录入完毕");
printf("书名：%s\n",book.title);
printf("作者：%s\n",book.author);
printf("价格：%.2f\n",book.price);
printf("出版日期：%d\n",book.date);
printf("出版社：%s\n",book.publisher);
    
return 0;
}
