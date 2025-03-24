#include <stdio.h>

// 快速排序函数声明
void quickSort(int array[], int left, int right);

// 快速排序函数定义
void quickSort(int array[], int left, int right)
{
    int i = left, j = right, temp;
    int pivot = array[(left + right) / 2]; // 选择中间元素作为基准

    // Partitioning step
    while (i <= j)
    {
        // 找到左侧第一个大于等于基准的元素
        while (array[i] < pivot)
        {
            i++;
        }
        // 找到右侧第一个小于等于基准的元素
        while (array[j] > pivot)
        {
            j--;
        }
        // 如果i和j没有交错，交换它们
        if (i <= j)
        {
            // Swap elements at i and j
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }

    // Recursively sort the sub-arrays
    // 如果左侧子数组有元素，递归排序
    if (left < j)
    {
        quickSort(array, left, j);
    }
    // 如果右侧子数组有元素，递归排序
    if (i < right)
    {
        quickSort(array, i, right);
    }
}

int main()
{int array[]={73,108,111,118,101,70,105,104,67,46,99,111,109};
int i,length;
length=sizeof(array)/sizeof(array[0]);
quickSort(array,0,length-1);
printf("排序后的数组：");
for (i=0;i<length;i++)
{
    printf("%d ",array[i]);
}
    return 0;
}