#pragma once

#define OK "OK" // OK
#define OPENFILEERROR "OPEN FILE ERROR" // FILE ERROR 1
#define WRITEFILERROR "WRITE FILE ERROR" // FILE ERROR 2

#define PRODUCTNOTFOUND "PRODUCT NOT FOUND" // PRODUCT ERROR 1
#define PRODUCTEXIST "PRODUCT ALREADY EXIST" // PRODUCT ERROR 2

#define STDINERROR "STD IN ERROR" // IO ERROR 1

#define NODENOTFOUND "NODE NOT FOUND" // LINK ERROR 1

#define READFILE 1
#define WRITEFILE 2

#define STRINGLENGTH 100

typedef char* Status; // 自定义状态码 上浮
typedef char* INFO; // 自定义消息

typedef struct product {
    int id; // 序号
    char *name; // 名称
    int price;
    int num;
    int sales;
    char *addition;
} product, *productptr;

typedef struct productLink {
    struct productLink *pre;
    struct productLink *next;
    product *value;
} productLink, *productLinkPtr;
