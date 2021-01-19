#include<stdio.h>
#include "MGraph.h"

int main(){
    MGraph g; // 图
    Edge minTree[MaxVertexNum];// 结果
    
    // 初始化图
    InitMGraph(&g);

    // 对弧按权升序排序
    SortEdge(&g);

    int count=0; // 记录最小生成树的边数
    
    // 遍历所有的边
    for (int i=0; i<g.arcnum;i++) {
        // 找到边的起始顶点和结束顶点在顶点数组中的位置
        int start = LocateVex(&g, g.Edge[i].Start);
        int end = LocateVex(&g, g.Edge[i].End);
        // 如果顶点位置存在且顶点的标记不同，说明不在一个集合中，不会产生回路
        if (start!=-1&& end!=-1&&g.Vex[start].sign!=g.Vex[end].sign) {
            // 记录该边，作为最小生成树的组成部分
            minTree[count]=g.Edge[i];
            // 计数+1
            count++;
            // 将新加入生成树的顶点标记更改为一样的
            for (int k=0; k<g.vexnum; k++) {
                if (g.Vex[k].sign==g.Vex[end].sign) {
                    g.Vex[k].sign=g.Vex[start].sign;
                }
            }
            // 如果选择的边的数量和顶点数相差1，证明最小生成树已经形成，退出循环
            if (count==g.vexnum-1) {
                break;
            }
        }
    }

    for (int i=0; i<g.vexnum-1; i++) {
        printf("%c->%c\n",minTree[i].Start,minTree[i].End);
    }
    return 0;
}