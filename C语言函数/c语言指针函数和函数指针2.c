// #include<stdio.h>
// int add(int ,int);
// int sub(int ,int);
// int cal (int (*p)(int,int),int,int);
// // 定义一个名为add的函数，该函数接收两个整数参数x和y，并返回它们的和
// int add(int x,int y)
// {
//     // 计算x和y的和，并将结果返回
//     return x+y;
// }
// // 定义一个名为sub的函数，用于计算两个整数的差值
// int sub(int x,int y)
// {
//     // 返回x和y的差值
//     return x-y;
// }
// // 定义一个名为cal的函数，该函数接收三个参数
// // 第一个参数是一个指向函数的指针，该函数接收两个int类型参数并返回一个int类型值
// // 第二个和第三个参数是int类型
// int cal (int (*p)(int,int),int x,int y)
// {
//     // 调用通过指针p指向的函数，传入x和y作为参数，并将返回值作为cal函数的返回值
//     return p(x,y);
// }
// int main()
// {
//     // 调用cal函数，传入add函数指针、3和4作为参数，打印结果
//     printf("%d\n",cal(add,3,4));
//     // 调用cal函数，传入sub函数指针、3和4作为参数，打印结果
//     printf("%d\n",cal(sub,3,4));


// return 0;
// }

#include<stdio.h>
int add(int ,int);
int sub(int ,int);
int cal (int (*)(int,int),int,int);
int (*select(char op))(int,int);

int add(int x,int y)
{
 
    return x+y;
}

int sub(int x,int y)
{
    return x-y;
}

int cal (int (*p)(int,int),int x,int y)
{
    // 调用通过指针p指向的函数，传入x和y作为参数，并将返回值作为cal函数的返回值
    return p(x,y);//p=(*p)
}
int (*select(char op))(int,int)
{
switch ((op))
{
    case'+':
    return add;
    case'-':
    return sub;
}

}
int main()
{
  int x,y;
  char op;
  int (*f)(int,int);
  printf("请输入一个式子");
  scanf("%d%c%d",&x,&op,&y);
  f=select(op);
  printf("%d %c %d = %d\n",x,op,y,cal(f,x,y));
return 0;
}