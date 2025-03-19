
#include <stdio.h>

int main()
{
    int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    int (*p)[4] = a; // p是指向包含4个整数的数组的指针
    int i,j;
    for(i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ", *(*(a+i)+j)); // *p+i相当于a+i, *(*p+i)+j相当于a[i][j]相当于a[i]
        }
        printf("\n");
    }

    return 0;
}

