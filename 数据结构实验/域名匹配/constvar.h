#define OK "OK" // OK

#define READFILE 1
#define WRITEFILE 2

#define STRINGLENGTH 100
#define BUFFSIZI 10
#define CAPSIZE 10

typedef struct treeNode {
    char *data1; // data(host)
    treeNode **child; // child
    int bufLength;
    int childNum;
    char *data2; // data(ip)
} treeNode, *treeNodePtr;

typedef struct ipInfo {
    char *host;
    char *ip;
} ipInfo, *ipInfoPtr;
