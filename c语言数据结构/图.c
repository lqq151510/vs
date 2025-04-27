#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
#include <ctype.h>

#define MAX_VERTEX 9
#define MAX_EDGE 11
#define NAME_LEN 3

// 邻接表存储结构
typedef struct ArcNode {
    int adjvex;         // 目标顶点索引
    float distance;     // 路程(km)
    float time;         // 时间(小时)
    char edge_name[5];  // 边名称
    struct ArcNode *nextarc;//指向下一个相邻的弧节点 用于构建邻接表中的链表结构 如果是链表中的最后一个节点，则为NULL
} ArcNode;

typedef struct {
    char name[NAME_LEN];    // 顶点名称
    ArcNode *firstarc;      // 邻接边链表
} VNode;

typedef struct {
    VNode vertices[MAX_VERTEX];//这是一个数组，用于存储图中的所有顶点(vertex)
    int vexnum, arcnum;//(vertex number)记录图中当前实际的顶点数量,(vertex number)记录图中当前实际的顶点数量
} ALGraph;

// 初始化交通图（严格按图示结构）
void InitGraph(ALGraph *G) {
    const char *nodes[MAX_VERTEX] = {"V1","V2","V3","V4","V5","V6","V7","V8","V9"};
    for(int i=0; i<MAX_VERTEX; i++) {
        strcpy(G->vertices[i].name, nodes[i]);
        G->vertices[i].firstarc = NULL;
    }
    //创建一个包含9个顶点名称的数组遍历所有顶点，将名称复制到图的顶点数组中将每个顶点的firstarc指针初始化为NULL（表示初始时没有边）

    // 严格按图示边结构初始化
    struct EdgeData {
        int from;        // 起点索引
        char ename[5];   // 边名称
        int to;          // 终点索引
        float distance;  // 距离
        float speed;     // 速度
    };

    const struct EdgeData edges[MAX_EDGE] = {
        {0, "a1",1, 12,40},  // V1->V2
        {0, "a2",2,  8,50},  // V1->V3
        {0, "a3",3,  6,60},  // V1->V4
        {1, "a4",4,  5,20},  // V2->V5
        {2, "a5",4,  8,25},  // V3->V5
        {3, "a6",5,  7,55},  // V4->V6
        {4, "a7",6,  5,20},  // V5->V7
        {4, "a8",7,  6,20},  // V5->V8
        {5, "a9",7, 10,40},  // V6->V8
        {6, "a10",8, 6,30},  // V7->V9
        {7, "a11",8, 8,25}   // V8->V9
    };

    // 构建邻接表
    for(int i=0; i<MAX_EDGE; i++) {
        ArcNode *arc = (ArcNode*)malloc(sizeof(ArcNode));
        strcpy(arc->edge_name, edges[i].ename);
        arc->adjvex = edges[i].to;
        arc->distance = edges[i].distance;
        arc->time = edges[i].distance / edges[i].speed;  // 计算时间
        
        // 头插法建立链表（保持图示顺序）
        arc->nextarc = G->vertices[edges[i].from].firstarc;
        G->vertices[edges[i].from].firstarc = arc;
    }
    G->arcnum = MAX_EDGE;
    G->vexnum = MAX_VERTEX;
}

// Dijkstra算法（mode:0-路程 1-时间）
void Dijkstra(ALGraph *G, int start, int end, int mode) {
    float dist[MAX_VERTEX];
    int path[MAX_VERTEX];
    int visited[MAX_VERTEX] = {0};
    
    for(int i=0; i<MAX_VERTEX; i++) {
        dist[i] = FLT_MAX;
        path[i] = -1;
    }
    dist[start] = 0;

    for(int i=0; i<G->vexnum; i++) {
        int u = -1;
        float min = FLT_MAX;
        for(int j=0; j<G->vexnum; j++) {
            if(!visited[j] && dist[j] < min) {
                u = j;
                min = dist[j];
            }
        }
        if(u == -1) break;
        visited[u] = 1;

        ArcNode *p = G->vertices[u].firstarc;
        while(p) {
            float weight = mode ? p->time : p->distance;
            if(dist[p->adjvex] > dist[u] + weight) {
                dist[p->adjvex] = dist[u] + weight;
                path[p->adjvex] = u;
            }
            p = p->nextarc;
        }
    }

    // 路径回溯
    if(dist[end] == FLT_MAX) {
        printf("\n路径不存在！\n");
        return;
    }

    printf("\n最优路径：");
    int stack[MAX_VERTEX], top = -1;
    for(int v=end; v!=-1; v=path[v]) stack[++top] = v;
    
    float total_dist = 0, total_time = 0;
    while(top > 0) {
        int u = stack[top--];
        int next = stack[top];
        
        ArcNode *p = G->vertices[u].firstarc;
        while(p && p->adjvex != next) p = p->nextarc;
        
        if(p) {
            printf("%s-%s→", G->vertices[u].name, p->edge_name);
            total_dist += p->distance;
            total_time += p->time;
        }
    }
    printf("%s", G->vertices[end].name);
    
    printf("\n总路程：%.1fkm", total_dist);
    printf("\n总时间：%.2f小时\n", total_time);
}

// 图形化显示交通网络
void VisualizeGraph() {
    printf("\n当前交通网络结构：\n");
    printf("                [V9]终点              \n");
    printf("                 ▲                   \n");
    printf("               a10│a11               \n");
    printf(" [V7]◄────a7───[V5]───a8───►[V8]    \n");
    printf("   ▲           ▲ ▲               ▲ \n");
    printf("   │a4        a5 │               │a9\n");
    printf(" [V2]◄─a1──[V1]  │a2           [V6]  \n");
    printf("                 │               ▲   \n");
    printf("               a3│             a6 │  \n");
    printf("                 ▼               ▼   \n");
    printf("                [V3]           [V4]   \n");
}

// 输入顶点有效性检查
int ValidateVertex(char *name) {
    if(strlen(name) != 2 || toupper(name[0]) != 'V') return -1;
    int idx = name[1] - '1';
    return (idx >=0 && idx < MAX_VERTEX) ? idx : -1;
}

int main() {
    ALGraph G;
    InitGraph(&G);
    
    int choice;
    char start[NAME_LEN], end[NAME_LEN];

    do {
        printf("\n========== 城市交通咨询系统 ==========\n");
        printf("1. 显示交通网络图\n");
        printf("2. 最短路程查询\n");
        printf("3. 最短时间查询\n");
        printf("4. 退出系统\n");
        printf("请选择操作：");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                VisualizeGraph();
                break;
            case 2:
            case 3: {
                printf("\n可用顶点：");
                for(int i=0; i<MAX_VERTEX; i++)
                    printf("%s ", G.vertices[i].name);
                
                printf("\n请输入起点：");
                scanf("%2s", start);
                printf("请输入终点：");
                scanf("%2s", end);
                
                int s = ValidateVertex(start);
                int e = ValidateVertex(end);
                if(s == -1 || e == -1) {
                    printf("错误：顶点名称无效！格式示例：V1\n");
                    break;
                }
                
                Dijkstra(&G, s, e, choice-2);
                break;
            }
            case 4:
                printf("感谢使用！\n");
                break;
            default:
                printf("无效操作！\n");
        }
    } while(choice != 4);

    // 释放内存
    for(int i=0; i<MAX_VERTEX; i++) {
        ArcNode *p = G.vertices[i].firstarc;
        while(p) {
            ArcNode *tmp = p;
            p = p->nextarc;
            free(tmp);
        }
    }
    return 0;
}