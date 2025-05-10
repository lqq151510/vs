#include<stdio.h>
#include<stdlib.h>

// 双亲表示法->父节点
#define MAX_TREE_SIZE 100
typedef struct {
    int data;       // 节点数据
    int parent;     // 双亲位置
} PTNode;

typedef struct {
    PTNode nodes[MAX_TREE_SIZE]; // 节点数组
    int n;                       // 节点数
} PTree;

// 孩子表示法->孩子节点
typedef struct CTNode {
    int child;               // 孩子节点下标
    struct CTNode *next;     // 指向下一个孩子
} CTNode, *ChildPtr;

typedef struct {
    int data;                // 节点数据
    ChildPtr firstChild;     // 第一个孩子指针
} CTBox;

typedef struct {
    CTBox nodes[MAX_TREE_SIZE]; // 节点数组
    int n, root;                // 节点数和根节点位置
} CTree;

// 孩子兄弟表示法,左孩子，右兄弟
typedef struct CSNode {
    int data;                 // 节点数据
    struct CSNode *firstChild, *nextSibling; // 第一个孩子和下一个兄弟指针
} CSNode, *CSTree;

// 二叉树节点定义
typedef struct BiTNode {
    int data;                 // 节点数据
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 示例：孩子兄弟表示法创建树
void CreateCSTree(CSTree *T) {
    int data;
    scanf("%d", &data);
    if (data == -1) { // -1 表示空节点
        *T = NULL;
    } else {
        *T = (CSNode *)malloc(sizeof(CSNode));
        (*T)->data = data;
        printf("输入%d的第一个孩子: ", data);
        CreateCSTree(&((*T)->firstChild)); // 创建第一个孩子
        printf("输入%d的下一个兄弟: ", data);
        CreateCSTree(&((*T)->nextSibling)); // 创建下一个兄弟
    }
}

// 示例：孩子兄弟表示法的前序遍历
void PreOrderCSTree(CSTree T) {
    if (T != NULL) {
        printf("%d ", T->data);         // 访问根节点
        PreOrderCSTree(T->firstChild); // 遍历孩子
        PreOrderCSTree(T->nextSibling); // 遍历兄弟
    }
}

// 二叉树的前序遍历
void PreOrderTraversal(BiTree T) {
    if (T != NULL) {
        printf("%d ", T->data);         // 访问根节点
        PreOrderTraversal(T->lchild);  // 遍历左子树
        PreOrderTraversal(T->rchild);  // 遍历右子树
    }
}

// 树转二叉树（孩子兄弟表示法）
void TreeToBinary(CSTree T, BiTree *B) {
    if (T == NULL) {
        *B = NULL;
    } else {
        *B = (BiTNode *)malloc(sizeof(BiTNode));
        (*B)->data = T->data;
        TreeToBinary(T->firstChild, &((*B)->lchild)); // 第一个孩子作为左子树
        TreeToBinary(T->nextSibling, &((*B)->rchild)); // 下一个兄弟作为右子树
    }
}

// 二叉树转树（孩子兄弟表示法）
void BinaryToTree(BiTree B, CSTree *T) {
    if (B == NULL) {
        *T = NULL;
    } else {
        *T = (CSNode *)malloc(sizeof(CSNode));
        (*T)->data = B->data;
        BinaryToTree(B->lchild, &((*T)->firstChild)); // 左子树作为第一个孩子
        BinaryToTree(B->rchild, &((*T)->nextSibling)); // 右子树作为下一个兄弟
    }
}

// 测试树与二叉树转换
int main() {
    CSTree T;
    BiTree B;

    printf("请输入树的节点数据，-1表示空节点:\n");
    CreateCSTree(&T);

    printf("孩子兄弟表示法的前序遍历: ");
    PreOrderCSTree(T);
    printf("\n");

    printf("将树转换为二叉树...\n");
    TreeToBinary(T, &B);

    printf("二叉树的前序遍历: ");
    PreOrderTraversal(B);
    printf("\n");

    printf("将二叉树转换回树...\n");
    BinaryToTree(B, &T);

    printf("孩子兄弟表示法的前序遍历: ");
    PreOrderCSTree(T);
    printf("\n");

    return 0;
}
