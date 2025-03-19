#include<stdio.h>
int main()
{
  // 定义一个整型变量num并初始化为1024
  int num=1024;
  // 定义一个整型指针p并指向num的地址
  int *p=&num;
  // 定义一个字符指针p1并指向字符串"hello world"
  char *p1="hello world";
  // 定义一个void指针p2，用于通用指针操作
  void *p2;
  // 将整型指针p的值（即num的地址）赋给void指针p2
  p2=p;
  // 打印整型指针p和void指针p2的值（即地址）
  printf("p:%p,p2:%p\n",p,p2);
  // 通过void指针p2访问num的值，需要先将其转换为整型指针
  printf("num:%d\n",*(int *)p2);
 
  // 将字符指针p1的值（即字符串"hello world"的地址）赋给void指针p2
  p2=p1;
  // 打印字符指针p1和void指针p2的值（即地址）
  printf("p1:%p,p2:%p\n",p1,p2);
  // 通过void指针p2访问字符串"hello world"，需要先将其转换为字符指针
  printf("num:%s\n",(char *)p2);//char *可有可无
 
    return 0;
}