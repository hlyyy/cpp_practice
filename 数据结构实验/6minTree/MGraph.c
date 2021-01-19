#include "MGraph.h"

int InitMGraph(MGraph* g){
    char c;
    printf("请输入连通网顶点数和边数：\n");
    scanf("%d %d",&g->vexnum,&g->arcnum);

    printf("请输入连通网顶点：(A B C D...\n");
    while((c=getchar())!='\n'&&c!=EOF);

    for (int i=0;i<g->vexnum;i++){
        c=getchar();
        if (c==' '){
            i--;
            continue;
        }
        g->Vex[i].Value = c;
        g->Vex[i].sign = i;
    }

    printf("请输入各边起始点和终点及其权重：(A B 10\n");
    
    char tmpA,tmpB;
    int a,b,tmpC;
    for (int i=0;i<g->arcnum;i++){
        while((c=getchar())!='\n'&&c!=EOF);
        scanf("%c %c %d",&tmpA,&tmpB,&tmpC);
        a=LocateVex(g,tmpA);
        b=LocateVex(g,tmpB);
        if(a==-1) return -1;
        if(b==-1) return -1;
        g->Edge[i].Start = tmpA;
        g->Edge[i].End = tmpB;
        g->Edge[i].Weight = tmpC;
    }
    return 1;
}

int LocateVex(MGraph* g,char node){
    for (int i=0;i<g->vexnum;i++){
        if (g->Vex[i].Value==node){
            return i;
        }
    }
    return -1;
}

int SortEdge(MGraph* g){
    for (int j=1;j<g->arcnum;j++) {
        Edge key = g->Edge[j];
        int i = j-1;
        while(i>=0&&g->Edge[i].Weight>key.Weight) {
            g->Edge[i+1]=g->Edge[i];
            i--;
        }
        g->Edge[i+1] = key;
    }
}