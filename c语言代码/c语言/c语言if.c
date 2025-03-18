#include <stdio.h>

int main()
{
    int i;
    // 提示用户输入成绩
    printf("请输入成绩：");
    // 读取用户输入的成绩
    scanf("%d", &i);

    // 判断成绩等级
    if (i >= 90)
    {
        printf("优秀\n");
    }
    else if (i >= 80 && i < 90)
    {
        printf("良好\n");
    }
    else if (i >= 70 && i < 80)
    {
        printf("中等\n");
    }
    else if (i >= 60 && i < 70)
    {
        printf("及格\n");
    }
    else
    {
        printf("不及格\n");
    }

    return 0;
}
