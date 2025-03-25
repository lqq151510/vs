#include <stdio.h>
int main()
{
    struct student
    {
        char name[20];
        int num;
        int age;
        char sex;
        float score;
    };
    struct student stu[3] = {
        {"li", 1001, 18, 'M', 78.5},
        {"wang", 1002, 19, 'F', 90.0},
        {"sun", 1003, 17, 'M', 85.5},
    };
    int i;
    for (i = 0; i < 3; i++)
    {
        printf("name:%s\n", stu[i].name);
        printf("num:%d\n", stu[i].num);
        printf("age:%d\n", stu[i].age);
        }
}