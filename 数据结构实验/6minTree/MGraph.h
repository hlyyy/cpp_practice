#include<stdio.h>
#define MaxVertexNum 100
typedef char VertexType; // 顶点类型
typedef int EdgeType;    // 权类型

// 节点
typedef struct {
    VertexType Value; // 顶点值
    int sign;         // 顶点所属集合
}Vertex;

// 弧
typedef struct {
    VertexType Start;
    VertexType End;
    EdgeType Weight;
}Edge;

// 领接矩阵
typedef struct {
    Vertex Vex[MaxVertexNum]; // 顶点表
    Edge Edge[MaxVertexNum];  // 弧权表
    int vexnum,arcnum;        // 顶点数和弧数
}MGraph;

int InitMGraph(MGraph* g);
int LocateVex(MGraph* g,char node);
int SortEdge(MGraph* g);