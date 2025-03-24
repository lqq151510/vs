#include <stdio.h>

// 全局变量
int global_var = 10;

// 静态全局变量
static int static_global_var = 20;

void function() {
    // 局部变量
    int local_var = 30;
    
    // 静态局部变量
    static int static_local_var = 40;
    
    printf("Inside function:\n");
    printf("local_var: %d\n", local_var);
    printf("static_local_var: %d\n", static_local_var);
    
    // 修改局部变量的值
    local_var++;
    static_local_var++;
}

int main() {
    // 访问全局变量
    printf("In main, global_var: %d\n", global_var);
    
    // 访问静态全局变量
    printf("In main, static_global_var: %d\n", static_global_var);
    
    // 调用函数
    function();
    
    // 再次调用函数，观察静态局部变量的变化
    function();
    
    // 尝试访问局部变量（会报错）
    // printf("local_var in main: %d\n", local_var); // Error: 'local_var' undeclared
    
    return 0;
}
