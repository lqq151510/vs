// #include <stdio.h>
// void recursion(void);
// void recursion(void)

// { static int count =10;//在函数内部使用：当 static 用于函数内部的局部变量时，它使得该变量的生命周期延长到整个程序运行期间，而不是在函数调用结束后被销毁。
//     printf("Hi\n");
//     if(count > 0)
//     {
//         count--;
//         recursion();
//     }
    
// }
// int main(void)
// {
//     recursion();
//     return 0;
// }
#include <stdio.h>
long fact(long n)   {
    long result;
     // for (result = 1; n > 1; n--)
    //    { result *= n;}
    //    return result;循环实现
    if (n>1)
    {
        result = n * fact(n - 1);
    }
    else
    {
        result = 1;
    }
    return result;//递归
}

int main(void)
{
    long num;
    printf("Enter a number: ");
    scanf("%ld", &num);
    printf("Factorial of %ld is %ld\n", num, fact(num));//求阶乘
    return 0;
}