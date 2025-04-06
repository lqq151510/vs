#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义多项式的项结构体
typedef struct Term {
    int coeff; // 系数
    int exp;   // 指数
} Term;

// 定义多项式的节点结构体
typedef struct Node {
    Term term;           // 项
    struct Node *next;    // 指向下一个节点的指针
} Node, *Polynomial;     // Node为节点类型，Polynomial为指向节点的指针类型

// 创建一个空的多项式
Polynomial create_polynomial() {
    Polynomial head = (Polynomial)malloc(sizeof(Node)); // 分配头节点内存
    head->next = NULL; // 头节点的下一个节点为空
    return head; // 返回头节点指针
}

// 销毁多项式，释放内存
void destroy_polynomial(Polynomial poly) {
    Node *current = poly->next; // 从头节点的下一个节点开始
    while (current != NULL) {
        Node *temp = current; // 临时保存当前节点
        current = current->next; // 移动到下一个节点
        free(temp); // 释放当前节点内存
    }
    free(poly); // 释放头节点内存
}

// 向多项式中插入一个项
void insert_term(Polynomial poly, int coeff, int exp) {
    if (coeff == 0) return; // 系数为0的项不插入

    Node *prev = poly; // 前一个节点指针初始化为头节点
    Node *current = poly->next; // 当前节点指针初始化为头节点的下一个节点

    // 找到插入位置
    while (current != NULL && current->term.exp < exp) {
        prev = current; // 移动前一个节点指针
        current = current->next; // 移动当前节点指针
    }

    // 如果当前节点的指数与要插入的指数相同，则合并系数
    if (current != NULL && current->term.exp == exp) {
        current->term.coeff += coeff; // 合并系数
        if (current->term.coeff == 0) { // 如果合并后的系数为0，则删除该节点
            prev->next = current->next; // 前一个节点指向当前节点的下一个节点
            free(current); // 释放当前节点内存
        }
    } else { // 如果当前节点的指数与要插入的指数不同，则插入新节点
        Node *new_node = (Node *)malloc(sizeof(Node)); // 分配新节点内存
        new_node->term.coeff = coeff; // 设置新节点的系数
        new_node->term.exp = exp; // 设置新节点的指数
        new_node->next = current; // 新节点的下一个节点为当前节点
        prev->next = new_node; // 前一个节点的下一个节点为新节点
    }
}

// 输入一个多项式
Polynomial input_polynomial() {
    int terms;
    printf("请输入多项式的项数：");
    scanf("%d", &terms); // 输入多项式的项数

    Polynomial poly = create_polynomial(); // 创建空多项式

    // 输入每一项的系数和指数
    for (int i = 0; i < terms; i++) {
        int coeff, exp;
        printf("请输入第%d项的系数和指数（用空格分隔）：", i + 1);
        scanf("%d %d", &coeff, &exp);
        insert_term(poly, coeff, exp); // 插入项
    }

    return poly; // 返回输入的多项式
}

// 多项式加法
Polynomial add_polynomial(Polynomial a, Polynomial b) {
    Polynomial result = create_polynomial(); // 创建结果多项式
    Node *p = a->next; // 指向第一个多项式的第一个节点
    Node *q = b->next; // 指向第二个多项式的第一个节点

    // 遍历两个多项式，合并同类项
    while (p != NULL && q != NULL) {
        if (p->term.exp < q->term.exp) {
            insert_term(result, p->term.coeff, p->term.exp); // 插入a的当前项
            p = p->next; // 移动到a的下一项
        } else if (p->term.exp > q->term.exp) {
            insert_term(result, q->term.coeff, q->term.exp); // 插入b的当前项
            q = q->next; // 移动到b的下一项
        } else {
            int sum = p->term.coeff + q->term.coeff; // 合并同类项
            if (sum != 0) {
                insert_term(result, sum, p->term.exp); // 插入合并后的项
            }
            p = p->next; // 移动到a的下一项
            q = q->next; // 移动到b的下一项
        }
    }

    // 插入a剩余的项
    while (p != NULL) {
        insert_term(result, p->term.coeff, p->term.exp);
        p = p->next;
    }

    // 插入b剩余的项
    while (q != NULL) {
        insert_term(result, q->term.coeff, q->term.exp);
        q = q->next;
    }

    return result; // 返回结果多项式
}

// 多项式减法
Polynomial subtract_polynomial(Polynomial a, Polynomial b) {
    Polynomial result = create_polynomial(); // 创建结果多项式
    Node *p = a->next; // 指向第一个多项式的第一个节点
    Node *q = b->next; // 指向第二个多项式的第一个节点

    // 遍历两个多项式，合并同类项
    while (p != NULL && q != NULL) {
        if (p->term.exp < q->term.exp) {
            insert_term(result, p->term.coeff, p->term.exp); // 插入a的当前项
            p = p->next; // 移动到a的下一项
        } else if (p->term.exp > q->term.exp) {
            insert_term(result, -q->term.coeff, q->term.exp); // 插入b的当前项的相反数
            q = q->next; // 移动到b的下一项
        } else {
            int diff = p->term.coeff - q->term.coeff; // 合并同类项
            if (diff != 0) {
                insert_term(result, diff, p->term.exp); // 插入合并后的项
            }
            p = p->next; // 移动到a的下一项
            q = q->next; // 移动到b的下一项
        }
    }

    // 插入a剩余的项
    while (p != NULL) {
        insert_term(result, p->term.coeff, p->term.exp);
        p = p->next;
    }

    // 插入b剩余的项的相反数
    while (q != NULL) {
        insert_term(result, -q->term.coeff, q->term.exp);
        q = q->next;
    }

    return result; // 返回结果多项式
}

// 多项式乘法
Polynomial multiply_polynomial(Polynomial a, Polynomial b) {
    Polynomial result = create_polynomial(); // 创建结果多项式
    Node *p = a->next; // 指向第一个多项式的第一个节点

    // 遍历第一个多项式的每一项
    while (p != NULL) {
        Node *q = b->next; // 指向第二个多项式的第一个节点
        // 遍历第二个多项式的每一项
        while (q != NULL) {
            int coeff = p->term.coeff * q->term.coeff; // 计算系数乘积
            int exp = p->term.exp + q->term.exp; // 计算指数和
            insert_term(result, coeff, exp); // 插入乘积项
            q = q->next; // 移动到b的下一项
        }
        p = p->next; // 移动到a的下一项
    }

    return result; // 返回结果多项式
}

void reverse_polynomial(Polynomial poly) {
    Node *prev = NULL;
    Node *prev = NULL; // 前一个节点指针初始化为空
    Node *current = poly->next; // 当前节点指针初始化为头节点的下一个节点
    poly->next = NULL; // 头节点的下一个节点设为空
    while (current != NULL) {
    // 反转链表
        // 保存当前节点的下一个节点
        Node *next = current->next;
        // 将当前节点的下一个节点指向前一个节点，实现反转
        current->next = prev;
        // 将前一个节点指向当前节点
        prev = current;
        // 将当前节点指向下一个节点
        current = next;
    }

    // 将多项式的头节点指向反转后的链表
    poly->next = prev;
}

// 打印多项式
void print_polynomial(Polynomial poly, int reverse_order) {
    // 如果需要降幂排列，则先复制多项式并反转链表
    if (reverse_order) {
        Polynomial copy = create_polynomial();
        Node *current = poly->next;
        // 复制多项式的每一项
        while (current != NULL) {
            insert_term(copy, current->term.coeff, current->term.exp);
            current = current->next;
        }
        // 反转多项式
        reverse_polynomial(copy);
        // 递归打印反转后的多项式
        print_polynomial(copy, 0);
        // 销毁复制的多项式
        destroy_polynomial(copy);
        return;
    }

    // 从头节点开始遍历多项式
    Node *current = poly->next;
    int is_first = 1; // 标记是否为第一个非零项

    // 遍历多项式的每一项
    while (current != NULL) {
        Term term = current->term;
        // 跳过系数为0的项
        if (term.coeff == 0) {
            current = current->next;
            continue;
        }

        // 如果不是第一个非零项，根据系数的正负打印符号
        if (!is_first) {
            if (term.coeff > 0) {
                printf(" + ");
            } else {
                printf(" - ");
            }
        } else {
            // 如果是第一个非零项且系数为负，打印负号
            if (term.coeff < 0) {
                printf("-");
            }
        }

        // 获取系数的绝对值
        int abs_coeff = abs(term.coeff);

        // 根据指数的值打印多项式的项
        if (term.exp == 0) {
            printf("%d", abs_coeff);
        } else if (term.exp == 1) {
            if (abs_coeff == 1) {
                printf("x");
            } else {
                printf("%dx", abs_coeff);
            }
        } else {
            if (abs_coeff == 1) {
                printf("x^%d", term.exp);
            } else {
                printf("%dx^%d", abs_coeff, term.exp);
            }
        }

        // 标记已经打印过第一个非零项
        is_first = 0;
        // 移动到下一个节点
        current = current->next;
    }

    // 如果多项式为空，打印0
    if (is_first) {
        printf("0");
    }
    // 打印换行符
    printf("\n");
}

// 主函数
int main() {
    int choice;
    // 循环显示菜单
    while (1) {
        printf("\n多项式运算系统\n");
        printf("1. 加法\n");
        printf("2. 减法\n");
        printf("3. 乘法\n");
        printf("0. 退出\n");
        printf("请输入选择：");
        scanf("%d", &choice);

        // 如果选择退出，结束循环
        if (choice == 0) break;

        // 检查选择的有效性
        if (choice < 1 || choice > 3) {
            printf("无效的选择！\n");
            continue;
        }

        // 输入两个多项式
        printf("输入第一个多项式：\n");
        Polynomial poly1 = input_polynomial();
        printf("输入第二个多项式：\n");
        Polynomial poly2 = input_polynomial();

        Polynomial result;
        // 根据选择进行多项式运算
        switch (choice) {
            case 1:
                result = add_polynomial(poly1, poly2);
                break;
            case 2:
                result = subtract_polynomial(poly1, poly2);
                break;
            case 3:
                result = multiply_polynomial(poly1, poly2);
                break;
            default:
                result = create_polynomial();
                break;
        }

        // 打印升幂排列和降幂排列的多项式
        printf("\n升幂排列：");
        print_polynomial(result, 0);
        printf("降幂排列：");
        print_polynomial(result, 1);

        // 销毁多项式
        destroy_polynomial(poly1);
        destroy_polynomial(poly2);
        destroy_polynomial(result);
    }

    return 0;
}