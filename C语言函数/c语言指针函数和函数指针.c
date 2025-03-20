// #include <stdio.h>

// const char *her(char c);

// // 定义一个函数her，接受一个字符c作为参数，返回一个指向常量字符的指针
// const char *her(char c)
// {
//     // 使用switch语句根据输入的字符c进行分支处理
//     switch(c)
//     {
//         // 如果c是'a'或'A'，返回字符串"apple"
//         case 'a':
//         case 'A':
//             return "apple";
//         // 如果c是'b'或'B'，返回字符串"banana"
//         case 'b':
//         case 'B':
//             return "banana";
//         // 如果c是'c'或'C'，返回字符串"cat"
//         case 'c':
//         case 'C':
//             return "cat";
//         // 如果c不是上述任何一个字符，返回字符串"error"
//         default:
//             return "error";
//     }
// }

// int main()
// {
//     char input; // 定义一个字符变量input用于存储用户输入的字符
//     printf("请输入一个字符："); // 提示用户输入一个字符
//     scanf("%c", &input); // 使用scanf函数读取用户输入的字符，并存储到input变量中
//     getchar(); // 清除缓冲区中的换行符
//     printf("%s\n", her(input));
//     return 0;
// }
//函数指针
#include<stdio.h>
int square(int num);
int square(int num)
{
return num*num;
}
int main()
{
    int num;
    int (*p)(int); //定义一个函数指针p，指向一个接受int类型参数并返回int类型的函数
    printf("请输入一个整数：");
    scanf("%d",&num);
    p=square; //将函数square的地址赋值给函数指针p
    printf("%d\n",(*p)(num)); //通过函数指针p调用函数square，并输出结果
  
    return 0;
}