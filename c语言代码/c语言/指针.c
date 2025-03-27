#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define foe(i,a,b) for(int i=a;i<=b;i++)

int main(){
    int arr[3][4]={ 1,2,3,4,5,6,7,8,9,10,11,300 };
    //1
    int *p1=arr[0]; // 将arr[0]的地址赋值给指针p1，arr[0]是一个指向int[4]的指针
    printf("%d ",*p1); // 输出p1指向的值，即arr[0][0]
    putchar('\n'); // 输出换行符
    //2
    int *p2=arr[1]; // 将arr[1]的地址赋值给指针p2，arr[1]是一个指向int[4]的指针
    printf("%d  ",p1[4]); // 输出p1指向的数组的第5个元素，即arr[0][4]
    printf("%d  ",p2[0]); // 输出p2指向的数组的第一个元素，即arr[1][0]
    printf("%d  ",p2[-1]); // 输出p2指向的数组的第-1个元素，即arr[1][-1]，等价于arr[1][3]
    putchar('\n'); // 输出换行符

    //2.5
    printf("%d",*(arr[1]+1)); // 输出arr[1][1]
    printf("%d",*(p2+1)); // 输出p2指向的数组的第2个元素，即arr[1][1]
    printf("%d",(arr[1]+1)[1]); // 输出arr[1][2]等价于(arr[1]+1)[1] 等价于 *(arr[1]+1+1)，即 arr[1][2]。
    printf("%d",(p2+1)[1]); // 输出p2指向的数组的第3个元素，即arr[1][2]    
    //3
    int *p3=&arr[0][0]; // 将arr[0][0]的地址赋值给指针p3
    printf("%d ",p3[0]); // 输出p3指向的值，即arr[0][0]
    printf("%d ",p3[4]); // 输出p3指向的数组的第5个元素，即arr[0][4]
    putchar('\n'); // 输出换行符
    //4
    int(*p4)[4]=arr; // 将arr的地址赋值给指针p4，p4是一个指向int[4]的指针
    printf("%d ",p4[0]); // 输出p4指向的数组的第一个元素，即arr[0]
    printf("%d ",p4[1][2]); // 输出p4指向的数组的第二行的第三个元素，即arr[1][2]
    printf("%d ",p4[1][-1]); // 输出p4指向的数组的第二行的第-1个元素，即arr[1][3]
    printf("%d ",p4[1][5]); // 输出p4指向的数组的第二行的第5个元素，即arr[1][1]
    putchar('\n'); // 输出换行符
    //5
    int(*p5)[3]=(int(*)[3])arr; // 将arr的地址转换为指向int[3]的指针赋值给p5
    printf("%d ",p5[1][2]); // 输出p5指向的数组的第二行的第三个元素，即arr[1][2]
    putchar('\n'); // 输出换行符
    //6
    char *p6=(char *)&p5[3][2]; //将p5[3][2]的地址转换为char*赋值给p6
    for(int i=0;i<=3;i++){
        printf("%d ",p6[i]); // 输出p6指向的数组的4个字节
    }
    putchar('\n'); // 输出换行符

    //7
    char brr[4]={ 1,1,0,0 }; // 定义一个字符数组brr
    int res=*(int *)brr; // 将brr的地址转换为int*并解引用赋值给res
    printf("%d ",res); // 输出res的值
    putchar('\n'); // 输出换行符

    //8
    int m=3,n=4;
    int **c0=(int **)malloc(m*sizeof(int *)); // 动态分配一个指向int*的指针数组
    for(int i=0;i<=m-1;i++){
        c0[i]=(int *)malloc(n*sizeof(int)); // 动态分配每一行的空间
    }

    for(int i=0;i<=m-1;i++){
        free(c0[i]); // 释放每一行的空间
    }
    free(c0); // 释放指针数组的空间
    // 二维数组c0和arr有什么区别

    //9
    int(*c1)[4]=(int(*)[4])malloc(3*4*sizeof(int)); // 动态分配一个指向int[4]的指针
    int(*c2)[3][4]=(int(*)[3][4])malloc(1*3*4*sizeof(int)); // 动态分配一个指向int[3][4]的指针
    memset(c1,0,sizeof(c1)); // 将c1指向的空间初始化为0
    memset(c2,0,sizeof(c2)); // 将c2指向的空间初始化为0

    int *pc1=*c1; // 将c1指向的数组的第一个元素赋值给pc1
    int *pc2=(*c2)[0]; // 将c2指向的数组的第一个元素赋值给pc2

    for(int i=1;i<=12;i++){
        pc1[i-1]=pc2[i-1]=i; // 将1到12依次赋值给pc1和pc2指向的数组
    }

#define m (*c2) // 定义宏m为*c2
    printf("%d ",c2[0][1][2]); // 输出c2指向的数组的第一个元素的第二个元素的第三个元素
    printf("%d ",m[1][2]); // 输出m的第二个元素的第三个元素
    printf("%d ",*(*(m+1)+2)); // 输出m的第二个元素的第三个元素

    free(c1); // 释放c1指向的空间
    free(c2); // 释放c2指向的空间

    //二维数组c1,c2和arr分别有什么区别
    //二维数组m和arr有什么区别

    // int a=300;
    // char *p=(char *)&a;
    // foe(i,0,3){
    //     printf("%d ",*(p+i));
    // }
    // char b[4]={1,1,0,0};
    // int num=*(int *)&b;
    // printf("%d ",num);

//     /*
//  * 此代码段展示了在C语言中操作多维数组和指针的各种方式。
//  * 通过不同的指针赋值和解引用操作，演示了如何访问和修改二维数组的元素。
//  * 同时，也展示了如何通过指针和类型转换来动态分配二维数组内存空间。
//  */
// #include <stdio.h>
// #include <stdlib.h>

//     int arr[3][4]={ 1,2,3,4,5,6,7,8,9,10,11,300 };

//     // 示例1：通过指针访问数组的第一个元素
//     int *p1=arr[0];
//     printf("%d ",*p1);
//     putchar('\n');

//     // 示例2：使用指针访问数组的不同元素，包括越界访问
//     int *p2=arr[1];
//     printf("%d ",p1[4]); // p1[4]等价于*(p1+4)，访问第5个元素
//     printf("%d ",p2[0]); // 访问p2指向的数组的第一个元素
//     printf("%d ",p2[-1]); // p2[-1]等价于*(p2-1)，访问上一个元素
//     putchar('\n');

//     // 示例3：通过指针访问数组的元素，展示等价性
//     int *p3=&arr[0][0];
//     printf("%d ",p3[0]); // 访问第一个元素
//     printf("%d ",p3[4]); // 访问第5个元素
//     putchar('\n');

//     // 示例4：使用指向数组的指针访问元素
//     int(*p4)[4]=arr;
//     printf("%d ",p4[0]); // 访问整个第一行
//     printf("%d ",p4[1][2]); // 访问第二行的第三个元素
//     printf("%d ",p4[1][-1]); // 越界访问，等价于p4[1][3]
//     printf("%d ",p4[1][5]); // 越界访问，等价于p4[1][1]（因为p4[1]是一个长度为4的数组）
//     putchar('\n');

//     // 示例5：类型转换，访问特定元素
//     int(*p5)[3]=(int(*)[3])arr;
//     printf("%d ",p5[1][2]); // 访问转换后的二维数组的特定元素
//     putchar('\n');

//     // 示例6：通过类型转换操作，以字符方式访问数组元素
//     char *p6=(char *)&p5[3][2];
//     for(int i=0;i<=3;i++){
//         printf("%d ",p6[i]); // 访问多维数组的单个字节
//     }
//     putchar('\n');

//     // 示例7：将一个字符数组强制转换为整数类型并访问
//     char brr[4]={ 1,1,0,0 };
//     int res=*(int *)brr; // 将字符数组看作整数进行访问
//     printf("%d ",res);
//     putchar('\n');

//     // 示例8：动态分配二维数组的行指针
//     int m=3,n=4;
//     int **c0=(int **)malloc(m*sizeof(int *));
//     for(int i=0;i<=m-1;i++){
//         c0[i]=(int *)malloc(n*sizeof(int));
//     }

//     for(int i=0;i<=m-1;i++){
//         free(c0[i]);
//     }
//     free(c0);

//     // 说明：此代码段分配了二维数组的行指针，每行通过malloc单独分配，需要手动释放内存。

//     // 示例9：动态分配二维数组并进行初始化
//     int(*c1)[4]=(int(*)[4])malloc(3*4*sizeof(int));
//     int(*c2)[3][4]=(int(*)[3][4])malloc(1*3*4*sizeof(int));
//     memset(c1,0,sizeof(c1));
//     memset(c2,0,sizeof(c2));

//     int *pc1=*c1;
//     int *pc2=(*c2)[0];

//     for(int i=1;i<=12;i++){
//         pc1[i-1]=pc2[i-1]=i;
//     }

//     #define m (*c2)
//     printf("%d ",c2[0][1][2]); // 直接访问二维数组元素
//     printf("%d ",m[1][2]); // 使用宏定义访问相同元素
//     printf("%d ",*(*(m+1)+2)); // 通过指针访问相同元素

//     free(c1);
//     free(c2);

//     // 说明：此代码段通过malloc动态分配了二维数组的空间，并通过memset初始化为0。
//     // 使用宏定义m来表示*c2，展示了不同的访问方式。

    return 0;
}