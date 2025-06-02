#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAXSIZE 100

typedef int KeyType;

typedef struct {
    KeyType key;
    int orig_index;  // 记录原始位置用于验证稳定性
} RedType;

typedef struct {
    RedType r[MAXSIZE + 1];
    int length;
} SqList;

// 全局计数器
long compare_count = 0;
long move_count = 0;

// 重置计数器
void reset_counters() {
    compare_count = 0;
    move_count = 0;
}

// 交换元素
void swap(RedType *a, RedType *b) {
    RedType temp = *a;
    *a = *b;
    *b = temp;
    move_count += 3;  // 3次移动
}

// 打印数组
void print_list(SqList L, int pass) {
    if (pass >= 0) printf("第%2d趟: ", pass);
    for (int i = 1; i <= L.length; i++) {
        printf("%2d(%d) ", L.r[i].key, L.r[i].orig_index);
    }
    printf("\n");
}

// 简单选择排序
void SelectSort(SqList *L) {
    for (int i = 1; i < L->length; i++) {
        int min_idx = i;
        for (int j = i + 1; j <= L->length; j++) {
            compare_count++;
            if (L->r[j].key < L->r[min_idx].key) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swap(&L->r[i], &L->r[min_idx]);
        }
        print_list(*L, i);
    }
}

// 直接插入排序
void InsertSort(SqList *L) {
    for (int i = 2; i <= L->length; i++) {
        if (L->r[i].key < L->r[i - 1].key) {
            L->r[0] = L->r[i];  // 哨兵
            move_count++;
            int j;
            for (j = i - 1; L->r[0].key < L->r[j].key; j--) {
                compare_count++;
                L->r[j + 1] = L->r[j];
                move_count++;
            }
            L->r[j + 1] = L->r[0];
            move_count++;
        }
        print_list(*L, i - 1);
    }
}

// 冒泡排序
void BubbleSort(SqList *L) {
    for (int i = 1; i < L->length; i++) {
        for (int j = 1; j <= L->length - i; j++) {
            compare_count++;
            if (L->r[j].key > L->r[j + 1].key) {
                swap(&L->r[j], &L->r[j + 1]);
            }
        }
        print_list(*L, i);
    }
}

// 折半插入排序
void BinaryInsertSort(SqList *L) {
    for (int i = 2; i <= L->length; i++) {
        L->r[0] = L->r[i];
        move_count++;
        int low = 1, high = i - 1;
        
        while (low <= high) {
            int mid = (low + high) / 2;
            compare_count++;
            if (L->r[0].key < L->r[mid].key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        for (int j = i - 1; j >= low; j--) {
            L->r[j + 1] = L->r[j];
            move_count++;
        }
        L->r[low] = L->r[0];
        move_count++;
        print_list(*L, i - 1);
    }
}

// 希尔排序
void ShellSort(SqList *L) {
    int gap = L->length / 2;
    int pass = 1;
    
    while (gap > 0) {
        for (int i = gap + 1; i <= L->length; i++) {
            L->r[0] = L->r[i];
            move_count++;
            int j;
            for (j = i - gap; j > 0 && L->r[0].key < L->r[j].key; j -= gap) {
                compare_count++;
                L->r[j + gap] = L->r[j];
                move_count++;
            }
            L->r[j + gap] = L->r[0];
            move_count++;
        }
        printf("增量=%d: ", gap);
        print_list(*L, pass++);
        gap /= 2;
    }
}

// 快速排序分区函数
int Partition(SqList *L, int low, int high) {
    L->r[0] = L->r[low];
    move_count++;
    KeyType pivotkey = L->r[low].key;
    
    while (low < high) {
        while (low < high && L->r[high].key >= pivotkey) {
            compare_count++;
            high--;
        }
        compare_count++;
        L->r[low] = L->r[high];
        move_count++;
        
        while (low < high && L->r[low].key <= pivotkey) {
            compare_count++;
            low++;
        }
        compare_count++;
        L->r[high] = L->r[low];
        move_count++;
    }
    L->r[low] = L->r[0];
    move_count++;
    return low;
}

// 快速排序（递归）
void QuickSort(SqList *L, int low, int high, int depth) {
    if (low < high) {
        int pivotloc = Partition(L, low, high);
        printf("递归深度%d: ", depth);
        print_list(*L, depth);
        
        QuickSort(L, low, pivotloc - 1, depth + 1);
        QuickSort(L, pivotloc + 1, high, depth + 1);
    }
}

// 快速排序（非递归）
#define MAX_STACK 100
typedef struct {
    int low;
    int high;
} StackItem;

void QuickSortNonRecursive(SqList *L, int low, int high) {
    StackItem stack[MAX_STACK];
    int top = -1;
    int pass = 1;
    
    stack[++top] = (StackItem){low, high};
    
    while (top >= 0) {
        StackItem item = stack[top--];
        int l = item.low, h = item.high;
        
        if (l < h) {
            int pivotloc = Partition(L, l, h);
            printf("非递归趟%d: ", pass++);
            print_list(*L, pass);
            
            if (pivotloc - 1 > l) {
                stack[++top] = (StackItem){l, pivotloc - 1};
            }
            if (pivotloc + 1 < h) {
                stack[++top] = (StackItem){pivotloc + 1, h};
            }
        }
    }
}

// 堆调整
void HeapAdjust(SqList *L, int s, int m) {
    RedType rc = L->r[s];
    move_count++;
    
    for (int j = 2 * s; j <= m; j *= 2) {
        compare_count++;
        if (j < m && L->r[j].key < L->r[j + 1].key) j++;
        
        compare_count++;
        if (rc.key >= L->r[j].key) break;
        
        L->r[s] = L->r[j];
        move_count++;
        s = j;
    }
    L->r[s] = rc;
    move_count++;
}

// 堆排序
void HeapSort(SqList *L) {
    // 建堆
    for (int i = L->length / 2; i > 0; i--) {
        HeapAdjust(L, i, L->length);
    }
    printf("初始建堆: ");
    print_list(*L, 0);
    
    // 排序
    for (int i = L->length; i > 1; i--) {
        swap(&L->r[1], &L->r[i]);
        HeapAdjust(L, 1, i - 1);
        printf("第%2d趟: ", L->length - i + 1);
        print_list(*L, L->length - i + 1);
    }
}

// 验证稳定性
int is_stable(SqList original, SqList sorted) {
    for (int i = 1; i < sorted.length; i++) {
        if (sorted.r[i].key == sorted.r[i + 1].key) {
            // 检查原始位置顺序
            if (sorted.r[i].orig_index > sorted.r[i + 1].orig_index) {
                return 0;  // 不稳定
            }
        }
    }
    return 1;  // 稳定
}

// 生成随机数据
void generate_data(SqList *L, int n) {
    srand(time(NULL));
    L->length = n;
    for (int i = 1; i <= n; i++) {
        L->r[i].key = rand() % 100;
        L->r[i].orig_index = i;  // 记录原始位置
    }
}

// 手动输入数据
void input_data(SqList *L) {
    printf("输入元素个数 (1-%d): ", MAXSIZE);
    scanf("%d", &L->length);
    
    printf("输入%d个整数: ", L->length);
    for (int i = 1; i <= L->length; i++) {
        scanf("%d", &L->r[i].key);
        L->r[i].orig_index = i;  // 记录原始位置
    }
}

// 复制表
void copy_list(SqList *dest, SqList src) {
    dest->length = src.length;
    for (int i = 1; i <= src.length; i++) {
        dest->r[i] = src.r[i];
    }
}

int main() {
    SqList L, original;
    int choice, n;
    
    printf("========= 内部排序算法模拟系统 =========\n");
    
    // 数据输入选项
    printf("\n[1] 随机生成数据\n[2] 手动输入数据\n选择: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        printf("输入数据量 (1-%d): ", MAXSIZE);
        scanf("%d", &n);
        generate_data(&L, n);
    } else {
        input_data(&L);
    }
    
    // 保存原始数据
    copy_list(&original, L);
    
    printf("\n原始数据: ");
    print_list(L, -1);
    
    while (1) {
        printf("\n============ 排序算法菜单 ============\n");
        printf(" 1. 简单选择排序\n");
        printf(" 2. 直接插入排序\n");
        printf(" 3. 冒泡排序\n");
        printf(" 4. 折半插入排序\n");
        printf(" 5. 希尔排序\n");
        printf(" 6. 快速排序(递归)\n");
        printf(" 7. 快速排序(非递归)\n");
        printf(" 8. 堆排序\n");
        printf(" 9. 重新生成数据\n");
        printf(" 0. 退出系统\n");
        printf("====================================\n");
        printf("请选择: ");
        scanf("%d", &choice);
        
        // 复制原始数据
        SqList current;
        copy_list(&current, original);
        
        reset_counters();  // 重置计数器
        
        switch (choice) {
            case 1:
                printf("\n===== 简单选择排序 =====\n");
                SelectSort(&current);
                break;
            case 2:
                printf("\n===== 直接插入排序 =====\n");
                InsertSort(&current);
                break;
            case 3:
                printf("\n===== 冒泡排序 =====\n");
                BubbleSort(&current);
                break;
            case 4:
                printf("\n===== 折半插入排序 =====\n");
                BinaryInsertSort(&current);
                break;
            case 5:
                printf("\n===== 希尔排序 =====\n");
                ShellSort(&current);
                break;
            case 6:
                printf("\n===== 快速排序(递归) =====\n");
                QuickSort(&current, 1, current.length, 1);
                break;
            case 7:
                printf("\n===== 快速排序(非递归) =====\n");
                QuickSortNonRecursive(&current, 1, current.length);
                break;
            case 8:
                printf("\n===== 堆排序 =====\n");
                HeapSort(&current);
                break;
            case 9:
                printf("\n重新生成数据:\n");
                printf("[1] 随机生成\n[2] 手动输入\n选择: ");
                scanf("%d", &choice);
                if (choice == 1) {
                    printf("输入数据量: ");
                    scanf("%d", &n);
                    generate_data(&L, n);
                } else {
                    input_data(&L);
                }
                copy_list(&original, L);
                printf("新数据: ");
                print_list(L, -1);
                continue;
            case 0:
                printf("系统已退出\n");
                return 0;
            default:
                printf("无效选择!\n");
                continue;
        }
        
        // 输出统计结果
        printf("\n排序结果: ");
        print_list(current, -1);
        printf("比较次数: %ld\n", compare_count);
        printf("移动次数: %ld\n", move_count);
        printf("稳定性: %s\n", is_stable(original, current) ? "稳定" : "不稳定");
    }
    return 0;
}