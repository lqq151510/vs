// #include <stdio.h>
// int main()
// {
//     int i=520;
//     printf("before,i=%d\n",i);//520
//     for (int i=0;i<10;i++)
//     {
//         printf("%d\n",i);
//     }

//     printf("after,i=%d\n",i);//520
    
//    return 0;
// }
// #include <stdio.h>
// void a();
// void b();
// void c();
// int count=0;
// void a()
// {
//     count++;

// }
// void b()
// {
//     count++;

// }
// void c()
// {
//     count++;

// }

// int main()
// {

//     a();
//     b();
//     c();
//     b();
//     printf("一共%d次\n",count);
//     return 0;

// }
#include <stdio.h>
void c();
int a,b=520;
void c()
{
    int b;
    a=880;
    b=120;
    printf("c a=%d,b=%d\n",a,b);
}
int main()
{
    printf("main a=%d,b=%d\n",a,b);
    c();
    printf("main a=%d,b=%d\n",a,b);
    return 0;
}