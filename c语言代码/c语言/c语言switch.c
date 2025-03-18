#include <stdio.h>
int main()
{
    // 定义一个字符变量n
    char n;
    // 提示用户输入成绩
    printf("请输入成绩：");
    // 从用户输入中读取一个字符
    scanf("%c",&n);
    // 根据用户输入的字符进行判断
    switch(n)
    {
        // 如果用户输入的是A，则输出优秀
        case 'A':
        printf("优秀\n");
        break;
        // 如果用户输入的是B，则输出良好
        case 'B':
        printf("良好\n");
        break;
        // 如果用户输入的是C，则输出中等
        case 'C':
        printf("中等\n");
        break;
        // 如果用户输入的是D，则输出及格
        case 'D':
        printf("及格\n");
        break;
        // 如果用户输入的不是A、B、C、D，则输出不及格
        default:
        printf("不及格\n");
    }
    // 返回0，表示程序正常结束
    return 0;

}
