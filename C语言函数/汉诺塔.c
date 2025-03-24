#include <stdio.h>

// Function prototype declaration
void hanoi(int n, char a, char b, char c);

// Function definition
void hanoi(int n, char a, char b, char c)
{
    if (n == 1)
    {
        printf("%c -> %c\n", a, c);
    }
    else
    {
        hanoi(n - 1, a, c, b);
        printf("%c -> %c\n", a, c);
        hanoi(n - 1, b, a, c);
    }
}

int main()
{
    int n;
    printf("请输入汉诺塔的层数：");
    
    // Input validation
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("请输入一个正整数！\n");
        return 1; // Exit with error code
    }
    
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
