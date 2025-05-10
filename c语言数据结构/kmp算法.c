#include<stdio.h>
#include<string.h>

// 计算部分匹配表（next 数组）
void ComputeNext(const char *pattern, int *next) {
    int m = strlen(pattern);
    next[0] = 0; // 第一个字符的部分匹配值为 0
    int j = 0;   // 前缀长度
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = next[j - 1]; // 回退到前一个部分匹配值
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        next[i] = j; // 记录部分匹配值
    }
}

// KMP 字符串匹配算法
int KMP(const char *text, const char *pattern) {
    int n = strlen(text);
    int m = strlen(pattern);
    if (m == 0) return 0; // 空模式串匹配位置为 0

    int next[m];
    ComputeNext(pattern, next); // 计算 next 数组

    int j = 0; // 模式串指针
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = next[j - 1]; // 回退到前一个部分匹配值
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) { // 完全匹配
            return i - m + 1; // 返回匹配起始位置
        }
    }
    return -1; // 未匹配
}

// 测试 KMP 算法
int main() {
    const char *text = "ababcabcacbab";
    const char *pattern = "abcac";
    int result = KMP(text, pattern);
    if (result != -1) {
        printf("匹配成功，起始位置为: %d\n", result);
    } else {
        printf("匹配失败。\n");
    }
    return 0;
}
