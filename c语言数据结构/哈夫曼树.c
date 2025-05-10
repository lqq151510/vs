#include<stdio.h>
#include<stdlib.h>

#define MAX_TREE_SIZE 100

// 哈夫曼树节点定义
typedef struct {
    int weight;       // 权值
    int parent;       // 双亲位置
    int lchild;       // 左孩子位置
    int rchild;       // 右孩子位置
} HTNode, HuffmanTree[MAX_TREE_SIZE];

// 构建哈夫曼树
void CreateHuffmanTree(HuffmanTree HT, int weights[], int n) {
    int m = 2 * n - 1; // 哈夫曼树总节点数
    for (int i = 0; i < m; i++) {
        HT[i].weight = (i < n) ? weights[i] : 0;
        HT[i].parent = HT[i].lchild = HT[i].rchild = -1;
    }

    for (int i = n; i < m; i++) {
        int min1 = -1, min2 = -1;
        for (int j = 0; j < i; j++) {
            if (HT[j].parent == -1) { // 未被选中的节点
                if (min1 == -1 || HT[j].weight < HT[min1].weight) {
                    min2 = min1;
                    min1 = j;
                } else if (min2 == -1 || HT[j].weight < HT[min2].weight) {
                    min2 = j;
                }
            }
        }
        HT[i].weight = HT[min1].weight + HT[min2].weight;
        HT[i].lchild = min1;
        HT[i].rchild = min2;
        HT[min1].parent = HT[min2].parent = i;
    }
}

// 打印哈夫曼树
void PrintHuffmanTree(HuffmanTree HT, int n) {
    printf("节点\t权值\t双亲\t左孩子\t右孩子\n");
    for (int i = 0; i < 2 * n - 1; i++) {
        printf("%d\t%d\t%d\t%d\t%d\n", i, HT[i].weight, HT[i].parent, HT[i].lchild, HT[i].rchild);
    }
}

// 测试哈夫曼树
int main() {
    int weights[] = {5, 7, 10, 15, 20, 45};
    int n = sizeof(weights) / sizeof(weights[0]);
    HuffmanTree HT;

    CreateHuffmanTree(HT, weights, n);
    printf("哈夫曼树构建完成:\n");
    PrintHuffmanTree(HT, n);

    return 0;
}
