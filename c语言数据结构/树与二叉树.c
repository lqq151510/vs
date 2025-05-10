#include<stdio.h>
#include<stdlib.h>

// 二叉树节点定义
typedef struct BiTNode {
    int data;                     // 数据域
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

// 二叉树的前序遍历
void PreOrderTraversal(BiTree T) {
    if (T != NULL) {
        printf("%d ", T->data);   // 访问根节点
        PreOrderTraversal(T->lchild); // 遍历左子树
        PreOrderTraversal(T->rchild); // 遍历右子树
    }
}

// 二叉树的中序遍历
void InOrderTraversal(BiTree T) {
    if (T != NULL) {
        InOrderTraversal(T->lchild); // 遍历左子树
        printf("%d ", T->data);   // 访问根节点
        InOrderTraversal(T->rchild); // 遍历右子树
    }
}

// 二叉树的后序遍历
void PostOrderTraversal(BiTree T) {
    if (T != NULL) {
        PostOrderTraversal(T->lchild); // 遍历左子树
        PostOrderTraversal(T->rchild); // 遍历右子树
        printf("%d ", T->data);   // 访问根节点
    }
}

// 创建二叉树（示例）
void CreateBiTree(BiTree *T) {
    int data;
    scanf("%d", &data);
    if (data == -1) { // -1 表示空节点
        *T = NULL;
    } else {
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data = data;
        printf("输入%d的左子节点: ", data);
        CreateBiTree(&((*T)->lchild)); // 创建左子树
        printf("输入%d的右子节点: ", data);
        CreateBiTree(&((*T)->rchild)); // 创建右子树
    }
}

// 线索二叉树节点定义
typedef struct ThreadNode {
    int data;                     // 数据域
    struct ThreadNode *lchild, *rchild; // 左右孩子指针
    int ltag, rtag;               // 左右线索标志：0 表示指向孩子，1 表示指向前驱或后继
} ThreadNode, *ThreadTree;

ThreadNode *pre = NULL; // 全局变量，指向当前访问节点的前驱

// 中序线索化
void InThreading(ThreadTree T) {
    if (T != NULL) {
        InThreading(T->lchild); // 线索化左子树
        if (T->lchild == NULL) { // 如果没有左孩子
            T->ltag = 1;         // 设置左线索
            T->lchild = pre;     // 左孩子指向前驱
        } else {
            T->ltag = 0;         // 左孩子指向实际孩子
        }
        if (pre != NULL && pre->rchild == NULL) { // 如果前驱没有右孩子
            pre->rtag = 1;       // 设置右线索
            pre->rchild = T;     // 前驱的右孩子指向当前节点
        }
        pre = T;                 // 更新前驱为当前节点
        InThreading(T->rchild);  // 线索化右子树
    }
}

// 创建中序线索二叉树
void CreateInThread(ThreadTree T) {
    pre = NULL; // 初始化前驱指针
    if (T != NULL) {
        InThreading(T); // 中序线索化
        if (pre != NULL) {
            pre->rtag = 1; // 最后一个节点的右线索置为 1
            pre->rchild = NULL; // 右孩子指向 NULL
        }
    }
}

// 中序遍历线索二叉树
void InOrderThreadTraversal(ThreadTree T) {
    ThreadNode *p = T;
    while (p != NULL) {
        while (p->ltag == 0) { // 找到中序遍历的第一个节点
            p = p->lchild;
        }
        printf("%d ", p->data); // 访问节点
        while (p->rtag == 1 && p->rchild != NULL) { // 按右线索访问后继节点
            p = p->rchild;
            printf("%d ", p->data);
        }
        p = p->rchild; // 转向右子树
    }
}

// 测试二叉树的遍历
int main() {
    BiTree T;
    printf("请输入二叉树节点数据，-1表示空节点:\n");
    CreateBiTree(&T);

    printf("前序遍历: ");
    PreOrderTraversal(T);
    printf("\n");

    printf("中序遍历: ");
    InOrderTraversal(T);
    printf("\n");

    printf("后序遍历: ");
    PostOrderTraversal(T);
    printf("\n");

    return 0;
}
