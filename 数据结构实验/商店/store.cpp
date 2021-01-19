#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstring>

#include "util.c"
#include "constvar.h"
#include "search.cpp"

FILE *wfile; // 单通道写
FILE *rfile; // 单通道读

int lastID = 1; // 自增索引

// 商品格式：
// int string int int int string
// 标号 名称 价格 数量 销售量 备注

// TODO:
// 配置文件：
// int string string
// id key value

productLinkPtr HEAD;
productLinkPtr Tail;

Status initData() {
    productLinkPtr l;
    Tail = HEAD;

    product *item;

    while (1) {
        item = (product*)malloc(sizeof(product));
        item->name = (char *)malloc(STRINGLENGTH * sizeof(char));
        item->addition = (char *)malloc(STRINGLENGTH * sizeof(char));

        if (fscanf(rfile, "%d\t%s\t%d\t%d\t%d\t%s", &item->id, item->name, &item->price, &item->num, &item->sales, item->addition) == EOF) {
            break;
        }

        l = (productLinkPtr)malloc(sizeof(productLink));
        l->value = item;
        
        printf("加载：%d\t%s\t%d\t%d\t%d\t%s\n", item->id, item->name, item->price, item->num, item->sales, item->addition);
        lastID = item->id;

        l -> pre = Tail;
        l -> next = NULL;
        Tail -> next = l;
        Tail = l;
    }

    // free(l);

    return OK;
}

Status printData() {
    productLinkPtr l = HEAD->next;
    product *item;

    printf("标号\t名称\t价格\t数量\t销售量\t备注\n");

    while (l != NULL) {
        item = l->value;
        printf("%d\t%s\t%d\t%d\t%d\t%s\n", item->id, item->name, item->price, item->num, item->sales, item->addition);

        l = l->next;
    }

    return OK;
}

Status printProduct(productptr item) {
    newLine();
    printf("输出商品 %s", item->name);

    printf("标号\t名称\t价格\t数量\t销售量\t备注\n");
    printf("%d\t%s\t%d\t%d\t%d\t%s\n", item->id, item->name, item->price, item->num, item->sales, item->addition);

    return OK;
}

// 新建节点
Status addNewNode(productptr node) {
    productLinkPtr newNode = (productLinkPtr)malloc(sizeof(productLink));
    
    newNode->value = node;
    Tail->next = newNode;
    newNode->pre = Tail;
    newNode->next = NULL;
    Tail = newNode;

    return OK;
}

// 删除节点
Status deleteNode(int id) {
    productLinkPtr p = HEAD->next;

    while(p != NULL) {
        if (p->value->id == id) {
            // 删除节点
            p->pre->next = p->next;
            // node = p->value;
            
            printProduct(p->value);

            free(p->value->addition);
            free(p->value->name);
            free(p->value);
            free(p);

            return OK;
        }

        p = p->next;
    }

    return NODENOTFOUND;
}

// 新建商品
Status newProduct() {
    productptr product = (productptr)malloc(sizeof(product));
    product->name = (char*)malloc(STRINGLENGTH * sizeof(char));
    product->addition = (char*)malloc(STRINGLENGTH * sizeof(char));

    printf("新建商品：\n");

    // printf("名称：");
    // scanf("%s", product->name);
    product->id = ++lastID;
    printf("价格：");
    scanf("%d", &product->price);
    printf("数量：");
    scanf("%d", &product->num);
    printf("备注：");
    scanf("%s", product->addition);
    printf("名称：");
    scanf("%s", product->name);

    newLine();
    printf("%p, %p, %p, %p", product->name, &product->price, &product->num, product->addition);
    newLine();

    addNewNode(product);

    return OK;
}

// 获取信息
Status getProduct(productptr item, int n) {
    productLinkPtr p = HEAD->next;

    while(p != NULL) {        
        if (p->value->id == n) {
            item = p->value;

            return OK;
        }
        p = p->next;
    }

    return PRODUCTNOTFOUND;
}

// 删除商品
Status deleteProduct() {
    int n;
    Status status;

    printf("输入希望删除的商品的id：\n");
    printf("id: ");
    scanf("%d", &n);

    // productptr item;
    // item.id = n;
    // item.name = s;

    // status = getProduct(item, n);
    // printf("OK\n");
    // if (strcmp(status, OK) != 0) {
    //     logInfo(status, "Product may not exist.");

    //     return status;
    // }

    status = deleteNode(n);
    if (strcmp(status, OK) != 0) {
        logInfo(status, "Delete product failed.");

        return status;
    }

    // printProduct(item);

    // free(item);

    return  OK;
}

Status changeNode(product item) {
    productLinkPtr p = HEAD->next;

    while(p != NULL) {        
        if (p->value->id == item.id) {
            p->value->num = item.num;
            p->value->price = item.price;
            strcpy(p->value->name, item.name);
            strcpy(p->value->addition, item.addition);

            printf("Change product info success!");

            return OK;
        }
        p = p->next;
    }
    
    return PRODUCTNOTFOUND;
}

// 更改信息
Status changeProductInfo() {
    int n;
    // char *s;
    Status status;

    // s = (char*)malloc(STRINGLENGTH * sizeof(char));

    printf("输入希望改变的id：\n");
    printf("id: ");
    scanf("%d", &n);

    product item;
    item.name = (char*)malloc(STRINGLENGTH * sizeof(char));
    item.addition = (char*)malloc(STRINGLENGTH * sizeof(char));

    // item.id = n;
    // item.name = s;

    status = getProduct(&item, n);
    if (strcmp(status, OK) != 0) {
        logInfo(status, "Product may not exist.");

        return status;
    }

    // printProduct(item);

    item.id = n;
    printf("价格：");
    scanf("%d", &item.price);
    printf("数量：");
    scanf("%d", &item.num);
    printf("备注：");
    scanf("%s", item.addition);
    printf("名称：");
    scanf("%s", item.name);

    changeNode(item);
    
    free(item.addition);
    free(item.name);
    // free(s);

    return OK;
}

// 根据关键字查询商品
Status searchProduct() {
    char *s;
    int res[100], n;
    memset(res, 0, 100);

    s = (char*)malloc(STRINGLENGTH * sizeof(char));
    printf("输入关键字：");
    scanf("%s", s);

    int len = strlen(s);
    search(s, len, res);

    newLine();
    printf("查询结果(id)：\n");
    for(int i = 0; res[i] != 0; i ++) {
        // printProduct()
        printf("%d\t", res[i]);
    }
    newLine();
    newLine();

    free(s);

    return OK;
}

// 自动补货

// 自动经营

// 显示菜单
Status showMenu() {
    printf("超市系统\n");
    printf("1 查看库存\n");
    printf("2 新建货物\n");
    printf("3 更新商品信息\n");
    printf("4 查询商品\n");
    printf("5 删除商品\n");
    printf("6 打印索引\n");
    printf("10 落盘\n");
    printf("0 结束\n");

    return OK;
}

// others

// 打开文件
Status openFile(int n) {
    if (n == READFILE) {
        if ((rfile = fopen("./data.txt", "r")) == NULL) {
            return OPENFILEERROR;
        }
        
        logInfo(OK, "Open file(R) success!");

        return OK;
    }

    if ((wfile = fopen("./data.txt", "w")) == NULL) {
        return OPENFILEERROR;
    }

    logInfo(OK, "Open file(W) success!");

    return OK;
}

// 关闭文件
Status closeFile() {
    fclose(wfile);
    fclose(rfile);

    return OK;
}

// 写入数据
Status writeData() {
    openFile(WRITEFILE);

    productLinkPtr l = HEAD->next;
    product *item;

    printf("标号\t名称\t价格\t数量\t销售量\t备注\n");

    while (l != NULL) {
        item = l->value;
        fprintf(wfile, "%d\t%s\t%d\t%d\t%d\t%s\n", item->id, item->name, item->price, item->num, item->sales, item->addition);
        printf("写入：%d\t%s\t%d\t%d\t%d\t%s\n", item->id, item->name, item->price, item->num, item->sales, item->addition);

        l = l->next;
    }

    return OK;
}

// 释放链表空间
Status freeLink() {
    productLinkPtr l, pre = HEAD->next;
    product *item;

    printf("标号\t名称\t价格\t数量\t销售量\t备注\n");

    while (l != NULL) {
        item = l->value;
        printf("释放:%d\n", item->id);

        pre = l;
        l = l->next;

        free(item->name);
        free(item->addition);
        free(item);
        free(pre);
    }

    free(HEAD);
    free(Tail);

    return OK;
}

// 主函数
int main() {
    int c = 0;
    Status status;

    HEAD = (productLinkPtr)malloc(sizeof(productLink));
    // Tail = (productLinkPtr)malloc(sizeof(productLink));
    // HEAD->next = NULL;
    // HEAD->pre = NULL;

    status = openFile(READFILE);
    if (strcmp(status, OK) != 0) {
        return 0;
    }

    initData();
    initIndex(HEAD);
    do {
        // fflush(stdin);
        // fflush(stdout);
        showMenu();
        scanf("%d", &c);
        printf("接收到操作数%d\n", c);
        switch (c) {
            case 1:
                printData();
                break;
            case 2:
                newProduct();
                renewIndex(HEAD);
                break;
            case 3:
                changeProductInfo();
                renewIndex(HEAD);
                break;
            case 4:
                searchProduct();
                break;
            case 5:
                deleteProduct();
                renewIndex(HEAD);
                break;
            case 6:
                printIndex();
                break;
            case 10:
                writeData();
                break;
            default:
                break;
        }
    } while(c != 0);

    writeData();
    closeFile();
    freeLink();
    freeIndex();

    return 0;
}
