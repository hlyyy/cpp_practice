#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>

#include "constvar.h"

using namespace std;

FILE *wfile; // 单通道写
FILE *rfile; // 单通道读

treeNodePtr Tree;

// 存储文件：
// DATA(host)   ChildNum    DATA(ip)
// root         1           0
// cn           1           0
// ...

// 0 代表并不是个节点

// 打开文件
void openFile(int n) {
    if (n == READFILE) {
        if ((rfile = fopen("./data.txt", "r")) == NULL) {
            return;
        }
        
        cout << "Open file(R) success!" << endl;;

        return;
    }

    if ((wfile = fopen("./data.txt", "w")) == NULL) {
        return;
    }

    cout << "Open file(W) success!" << endl;;

    return;
}

void initData(treeNodePtr tree) {
    treeNodePtr t;
    // tree = (treeNodePtr)malloc(sizeof(treeNodePtr));
    tree->data1 = (char *)malloc(STRINGLENGTH * sizeof(char));
    tree->data2 = (char *)malloc(STRINGLENGTH * sizeof(char));
    tree->childNum = 0;
    tree->child = (treeNodePtr*)malloc((CAPSIZE) * sizeof(treeNodePtr));
    tree->bufLength = CAPSIZE;
    // tree->child = (treeNodePtr*)malloc((CAPSIZE) * sizeof(treeNodePtr));
    // copyNode(tree, t);

    if (fscanf(rfile, "%s\t%d\t%s", tree->data1, &tree->childNum, tree->data2) == EOF) {
        cout << "读取文件完毕" << endl;

        return;
    }

    int childNum = tree->childNum;
    // printf("child num %d, data1 %s, data2 %s", childNum, tree->data1, tree->data2);

    if (childNum >= CAPSIZE) {
        tree->child = (treeNodePtr*)realloc(tree->child, (childNum + CAPSIZE) * sizeof(treeNodePtr));
        tree->bufLength = childNum + CAPSIZE;
    }

    // copyNode(tree, t);

    printf("加载：%s\t%d\t%s\n", tree->data1, childNum, tree->data2);
    
    for (int i = 0; i < childNum; i ++) {
        tree->child[i] = (treeNodePtr)malloc(sizeof(treeNodePtr));
        initData(tree->child[i]);
    }

    return;
}

// 写入数据 算是先序遍历
void writeData(treeNodePtr tree) {
    fprintf(wfile, "%s\t%d\t%s\n", tree->data1, tree->childNum, tree->data2);
    printf("写入：%s\t%d\t%s\n", tree->data1, tree->childNum, tree->data2);

    int childNum = tree->childNum;
    for (int i = 0; i < childNum; i ++) {
        writeData(tree->child[i]);
    }

    return;
}

// 打印单个 node
void printNode(int pos, treeNodePtr node) {
    if (pos == -1) {
        cout << endl;
    }

    cout << (pos != -1 ? "." : "") << node->data1 << (strcmp(node->data2, "0") != 0 ? " " : "") << (strcmp(node->data2, "0") != 0 ? node->data2 : "") << (strcmp(node->data2, "0") != 0 ? " " : "");

    return;
}

// 先序遍历
void travelTreeF(int pos, treeNodePtr node) {
    int j = pos;

    if (node != Tree) {
        printNode(j, node);

        j = 0;
    } else {
        j = -1;
    }

    for (int i = 0; i < node->childNum; i ++) {
        travelTreeF(j, node->child[i]);
    }

    return;
}

// 无中序遍历

// 后序遍历
void travelTreeB(treeNodePtr node) {
    for (int i = 0; i < node->childNum; i ++) {
        travelTreeB(node->child[i]);
    }

    printNode(0, node);

    return;
}

// 打印数据 采用先序遍历
void printData(treeNodePtr node) {
    travelTreeF(-1, node);

    return;
}

void freeStack(stack<char*> s) {
    while (!s.empty()) {
        s.pop();
    }
    
    return;
}

// 新增 ip
void newIP() {
    ipInfoPtr newIp = (ipInfoPtr)malloc(sizeof(ipInfoPtr));
    newIp->host = (char *)malloc(STRINGLENGTH * sizeof(char));
    newIp->ip = (char *)malloc(STRINGLENGTH * sizeof(char));

    // cout << "新增 IP: " << endl;
    cout << "输入 IP: ";
    scanf("%s", newIp->ip);
    cout << "输入 HOST : ";
    scanf("%s", newIp->host);

    cout << "输入的 IP: " << newIp->ip << " HOST: " << newIp->host << endl;

    // 分割 host
    char *tempHost;
    cout << "分级域名: " << endl;
    treeNodePtr node = Tree;

    stack<char*> s;
    while(1) {
        char *temp; //= (char*)malloc(STRINGLENGTH * sizeof(char));
        if ((temp = strsep(&newIp->host, ".")) != NULL) {
            s.push(temp);
        } else {
            break;
        }
    }
    
    while(!s.empty()) {
        tempHost = s.top();
        s.pop();

        bool flag = false;
        for (int i = 0; i < node->childNum; i ++) {
            if (strcmp((node->child[i])->data1, tempHost) == 0) {
                flag = true;
                node = node->child[i];
                break;
            }
        }
        // cout << "flag: " << flag << endl;
        if (flag) {
            cout << tempHost << "(exist)" << " ";
        } else {
            // 新增树节点
            treeNodePtr newNode = (treeNodePtr)malloc(sizeof(treeNode));
            newNode->childNum = 0;
            newNode->child = (treeNodePtr*)malloc(CAPSIZE * sizeof(treeNodePtr));
            newNode->data1 = (char *)malloc(STRINGLENGTH * sizeof(char));
            newNode->data2 = (char *)malloc(STRINGLENGTH * sizeof(char));
            newNode->data1 = strcpy(newNode->data1, tempHost);
            newNode->data2 = strcpy(newNode->data2, "0");
            newNode->bufLength = CAPSIZE;

            if (node->childNum + 1 < node->bufLength) {
                node->child[node->childNum] = newNode;
            } else {
                // 扩容
                node->child = (treeNodePtr*)realloc(node->child, (node->childNum +  CAPSIZE) * sizeof(treeNodePtr));
                node->child[node->childNum] = newNode;
            }

            node->childNum ++;
            cout << newNode->data1 << "(new)" << " ";
            node = node->child[node->childNum - 1];
        }
    }

    // 最后绑定 ip
    if (strcmp(node->data2, "0") != 0) {
        cout << "IP  已经存在！" << endl;
    } else {
        node->data2 = strcpy(node->data2, newIp->ip);
        cout << endl << "新 IP " << node->data2 << " 绑定成功！" << endl;
    }

    // freeStack(s);

    return;
}

// 查询 ip
void searchIP(treeNodePtr node, stack<char*> s) {
    if (s.empty()) {
        if (strcmp(node->data2, "0") != 0 ) {
            cout << "查询成功！ " << "IP: " << node->data2 << endl;
            return;
        }
    }

    char *temp = s.top();

    s.pop();
    for (int i = 0; i < node->childNum; i ++) {
        // cout << "str1: " << strlen(node->child[i]->data1) << " str2: " << strlen(temp) << " strcmp: " << strcmp(node->child[i]->data1, temp) << endl;
        if (strcmp(node->child[i]->data1, temp) == 0) {
            searchIP(node->child[i], s);
            return;
        }
    }

    cout << "查询失败！" << endl;

    freeStack(s);

    return;
}

void search() {
    stack<char*> s;

    char *host = (char*)malloc(STRINGLENGTH * sizeof(char));

    cout << "输入域名: " << endl;
    scanf("%s", host);

    while(1) {
        char *temp; //= (char*)malloc(STRINGLENGTH * sizeof(char));
        // char *t;
        if ((temp = strsep(&host, ".")) != NULL) {
            //strcpy(temp, t);
            //temp[strlen(temp) + 1] = '\0';
            //cout << "temp " << strlen(temp) << " " << temp << " t " << strlen(t) << " " << t << endl;
            s.push(temp);
        } else {
            break;
        }
    }

    searchIP(Tree, s);

    return;
}

// 释放空间
void freeTree(treeNodePtr tree) {
    if (tree->childNum != 0) {
        for (int i = 0; i < tree->childNum; i ++) {
            freeTree(tree->child[i]);
        }
    }

    free(tree->child);

    if (tree != Tree) {
        free(tree->data1);
        free(tree->data2);
    }
    
    free(tree);

    return;
}

// 菜单
void showMenu() {
    printf("\n");
    
    printf("域名匹配\n");
    printf("1 查看所有域名\n");
    printf("2 新建域名\n");
    printf("3 查询域名\n");
    printf("0 结束\n");

    return;
}

// 入口函数
int main() {
    openFile(READFILE);

    Tree = (treeNodePtr)malloc(sizeof(treeNodePtr));
    initData(Tree);
    if (Tree->childNum == 0) {
        cout << "init" << endl;
        // Tree = (treeNodePtr)malloc(sizeof(treeNodePtr));
        // 加载默认根域名: root
        Tree->data1 = (char *)malloc(STRINGLENGTH * sizeof(char));
        Tree->data2 = (char *)malloc(STRINGLENGTH * sizeof(char));
        Tree->data1 = "root";
        Tree->data2 = "0";
        Tree->child = (treeNodePtr*)malloc(CAPSIZE * sizeof(treeNodePtr));
        Tree->childNum = 0;
        Tree->bufLength = CAPSIZE;
    }

    int c = 0;
    do {
        showMenu();
        scanf("%d", &c);
        printf("接收到操作数%d\n", c);
        switch (c) {
            case 1:
                printData(Tree);
                break;
            case 2:
                newIP();
                break;
            case 3:
                search();
                break;
            default:
                break;
        }
    } while(c != 0);

    // travelTreeF(Tree);
    // travelTreeB(Tree);
    openFile(WRITEFILE);
    writeData(Tree);

    freeTree(Tree);

    return 0;
}
