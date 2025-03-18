#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// 函数声明
bool isPrime(int num);

int main() {
    int num;

    // 输入一个整数
    printf("请输入一个整数: ");
    scanf("%d", &num);

    // 判断是否为素数并输出结果
    if (isPrime(num)) {
        printf("%d 是素数。\n", num);
    } else {
        printf("%d 不是素数。\n", num);
    }

    return 0;
}

// 判断素数的函数
bool isPrime(int num) {
    if (num <= 1) {
        return false; // 小于等于1的数不是素数
    }
    
    // 检查从2到sqrt(num)之间的数是否能整除num
    for (int i = 2; i <=num/2; i++) {
        if (num % i == 0) {
            return false; // 如果能整除，则不是素数
        }
    }
    
    return true; // 如果没有找到能整除的数，则是素数
}
