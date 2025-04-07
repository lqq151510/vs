#include <stdio.h>
#include <stdlib.h>

// 定义排序方式
#define DESCENDING 0
#define ASCENDING 1

// 定义多项式项的结构体
typedef struct Term {
    int coefficient; // 系数
    int exponent;    // 指数
    struct Term *next; // 指向下一个项的指针
    struct Term *prev; // 为了反向遍历，指向上一个项的指针
} Term, *Polynomial; // Term为结构体类型，Polynomial为指向Term的指针类型

// 函数声明
Polynomial createPolynomial();
void insertTerm(Polynomial poly, int coefficient, int exponent);
Polynomial addPolynomials(Polynomial poly1, Polynomial poly2);
Polynomial subtractPolynomials(Polynomial poly1, Polynomial poly2);
Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2);
void printPolynomial(Polynomial poly, int order);
void freePolynomial(Polynomial poly);

int main() {
    Polynomial poly1 = createPolynomial(); // 创建第一个多项式
    Polynomial poly2 = createPolynomial(); // 创建第二个多项式
    
    printf("请输入第一个多项式的项数: ");
    int n1;
    scanf("%d", &n1); // 读取第一个多项式的项数
    printf("请输入第一个多项式的系数和指数(格式: 系数 指数):\n");
    for (int i = 0; i < n1; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp); // 读取系数和指数
        insertTerm(poly1, coeff, exp); // 插入项到第一个多项式
    }
    
    printf("请输入第二个多项式的项数: ");
    int n2;
    scanf("%d", &n2); // 读取第二个多项式的项数
    printf("请输入第二个多项式的系数和指数(格式: 系数 指数):\n");
    for (int i = 0; i < n2; i++) {
        int coeff, exp;
        scanf("%d %d", &coeff, &exp); // 读取系数和指数
        insertTerm(poly2, coeff, exp); // 插入项到第二个多项式
    }
    
    printf("\n请选择操作:\n");
    printf("1. 加法\n");
    printf("2. 减法\n");
    printf("3. 乘法\n");
    printf("输入选择(1-3): ");
    int choice;
    scanf("%d", &choice); // 读取用户选择
    
    Polynomial result;
    switch (choice) {
        case 1:
            result = addPolynomials(poly1, poly2); // 多项式加法
            printf("\n加法结果:\n");
            break;
        case 2:
            result = subtractPolynomials(poly1, poly2); // 多项式减法
            printf("\n减法结果:\n");
            break;
        case 3:
            result = multiplyPolynomials(poly1, poly2); // 多项式乘法
            printf("\n乘法结果:\n");
            break;
        default:
            printf("无效选择\n");
            return 1;
    }
    
    printf("降幂排列: ");
    printPolynomial(result, DESCENDING); // 打印降幂排列的多项式
    printf("升幂排列: ");
    printPolynomial(result, ASCENDING); // 打印升幂排列的多项式
    
    freePolynomial(poly1); // 释放第一个多项式内存
    freePolynomial(poly2); // 释放第二个多项式内存
    freePolynomial(result); // 释放结果多项式内存
    
    return 0;
}

// 创建一个空的多项式
Polynomial createPolynomial() {
    Polynomial poly = (Polynomial)malloc(sizeof(Term)); // 分配内存
    poly->next = NULL; // 初始化指针
    poly->prev = NULL; // 初始化指针
    return poly;
}

// 向多项式中插入一个项
void insertTerm(Polynomial poly, int coefficient, int exponent) {
    Term *newTerm = (Term *)malloc(sizeof(Term)); // 分配内存
    newTerm->coefficient = coefficient; // 设置系数
    newTerm->exponent = exponent; // 设置指数
    newTerm->next = NULL; // 初始化指针
    newTerm->prev = NULL; // 初始化指针
    // 如果多项式为空，直接插入新项
    if (poly->next == NULL) {
        poly->next = newTerm;
        newTerm->prev = poly;
        return;
    }
    
    Term *prev = poly; // 指向头节点的指针
    Term *current = poly->next; // 指向第一个项的指针
    
    // 找到插入位置
    while (current != NULL && current->exponent < exponent) {
        prev = current;
        current = current->next;
    }
    
    // 如果指数相同，合并项
    if (current != NULL && current->exponent == exponent) {
        current->coefficient += coefficient;
        free(newTerm); // 释放新分配的内存
        if (current->coefficient == 0) { // 如果系数为0，删除该项
            prev->next = current->next;
            if (current->next != NULL) {
                current->next->prev = prev;
            }
            free(current);
        }
    } else { // 插入新项
        newTerm->next = current;
        newTerm->prev = prev;
        prev->next = newTerm;
        if (current != NULL) {
            current->prev = newTerm;
        }
    }
}

// 多项式加法
Polynomial addPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial result = createPolynomial(); // 创建结果多项式
    
    Term *term1 = poly1->next; // 指向第一个多项式的第一个项
    Term *term2 = poly2->next; // 指向第二个多项式的第一个项
    
    // 遍历两个多项式
    while (term1 != NULL && term2 != NULL) {
        if (term1->exponent < term2->exponent) {
            insertTerm(result, term1->coefficient, term1->exponent);
            term1 = term1->next;
        } else if (term1->exponent > term2->exponent) {
            insertTerm(result, term2->coefficient, term2->exponent);
            term2 = term2->next;
        } else {
            int sum = term1->coefficient + term2->coefficient;
            if (sum != 0) {
                insertTerm(result, sum, term1->exponent);
            }
            term1 = term1->next;
            term2 = term2->next;
        }
    }
    
    // 插入剩余项
    while (term1 != NULL) {
        insertTerm(result, term1->coefficient, term1->exponent);
        term1 = term1->next;
    }
    
    while (term2 != NULL) {
        insertTerm(result, term2->coefficient, term2->exponent);
        term2 = term2->next;
    }
    
    return result;
}

// 多项式减法
Polynomial subtractPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial result = createPolynomial(); // 创建结果多项式
    
    Term *term1 = poly1->next; // 指向第一个多项式的第一个项
    Term *term2 = poly2->next; // 指向第二个多项式的第一个项
    
    // 遍历两个多项式
    while (term1 != NULL && term2 != NULL) {
        if (term1->exponent < term2->exponent) {
            insertTerm(result, term1->coefficient, term1->exponent);
            term1 = term1->next;
        } else if (term1->exponent > term2->exponent) {
            insertTerm(result, -term2->coefficient, term2->exponent);
            term2 = term2->next;
        } else {
            int diff = term1->coefficient - term2->coefficient;
            if (diff != 0) {
                insertTerm(result, diff, term1->exponent);
            }
            term1 = term1->next;
            term2 = term2->next;
        }
    }
    
    // 插入剩余项
    while (term1 != NULL) {
        insertTerm(result, term1->coefficient, term1->exponent);
        term1 = term1->next;
    }
    
    while (term2 != NULL) {
        insertTerm(result, -term2->coefficient, term2->exponent);
        term2 = term2->next;
    }
    
    return result;
}

// 多项式乘法
Polynomial multiplyPolynomials(Polynomial poly1, Polynomial poly2) {
    Polynomial result = createPolynomial(); // 创建结果多项式
    
    Term *term1 = poly1->next; // 指向第一个多项式的第一个项
    while (term1 != NULL) {
        Term *term2 = poly2->next; // 指向第二个多项式的第一个项
        while (term2 != NULL) {
            int coeff = term1->coefficient * term2->coefficient; // 计算系数
            int exp = term1->exponent + term2->exponent; // 计算指数
            insertTerm(result, coeff, exp); // 插入新项
            term2 = term2->next;
        }
        term1 = term1->next;
    }
    
    return result;
}

// 打印多项式
void printPolynomial(Polynomial poly, int order) {
    if (poly->next == NULL) {
        printf("0\n");
        return;
    }
    
    // 定义一个指向多项式项的指针current
    Term *current;

    
    // 根据order的值决定current的初始位置
    if (order == DESCENDING) { // 如果order为降序
        current = poly->next; // 从多项式的第一个项开始
        while (current->next != NULL) { // 遍历到多项式的最后一个项
            current = current->next;
        }
    } else { // 如果order为升序
        current = poly->next; // 从多项式的第一个项开始
    }
    
    // 定义一个标志变量，用于判断是否是第一个项
    int firstTerm = 1;
    
    // 遍历多项式的每一项
    while (current != NULL) {
        int coeff = current->coefficient; // 获取当前项的系数
        int exp = current->exponent; // 获取当前项的指数
        
        // 如果不是第一个项，根据系数的正负打印相应的符号
        if (!firstTerm) {
            if (coeff > 0) {
                printf(" + "); // 系数为正，打印加号
            } else {
                printf(" - "); // 系数为负，打印减号
                coeff = -coeff; // 取绝对值
            }
        } else { // 如果是第一个项
            if (coeff < 0) {
                printf("-"); // 系数为负，打印负号
                coeff = -coeff; // 取绝对值
            }
            firstTerm = 0; // 标记已经处理过第一个项
        }
        
        // 根据指数的值打印相应的格式
        if (exp == 0) {
            printf("%d", coeff); // 指数为0，直接打印系数
        } else if (exp == 1) {
            if (coeff == 1) {
                printf("x"); // 系数为1且指数为1，只打印x
            } else {
                printf("%dx", coeff); // 打印系数和x
            }
        } else {
            if (coeff == 1) {
                printf("x^%d", exp); // 系数为1，打印x^指数
            } else {
                printf("%dx^%d", coeff, exp); // 打印系数、x和指数
            }
        }
        
        // 根据order的值决定current的移动方向
        if (order == DESCENDING) {
            current = current->prev; // 降序时，向前移动
        } else {
            current = current->next; // 升序时，向后移动
        }
    }
    // 打印换行符，结束多项式的打印
    printf("\n");
}

// 释放多项式内存
void freePolynomial(Polynomial poly) {
    Term *current = poly->next;
    while (current != NULL) {
        Term *temp = current;
        current = current->next;
        free(temp);
    }
    free(poly);
}