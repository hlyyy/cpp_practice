#include <iostream>
using namespace std;

typedef struct BTNode
{
    int key;
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

//注意！这不是二叉排序树构造算法，这个二叉排序树生成只是为了下面的二叉排序树查找算法服务，真正的二叉排序树构造算法自行查找。
void createBST(BTNode *&bt)
{
    //欲生成的二叉排序树如上图所示
    bt = (BTNode *)malloc(sizeof(BTNode));
    bt->key = 5;

    BTNode *n4 = (BTNode *)malloc(sizeof(BTNode));
    n4->key = 4;
    BTNode *n8 = (BTNode *)malloc(sizeof(BTNode));
    n8->key = 8;
    BTNode *n3 = (BTNode *)malloc(sizeof(BTNode));
    n3->key = 3;
    BTNode *n7 = (BTNode *)malloc(sizeof(BTNode));
    n7->key = 7;
    BTNode *n9 = (BTNode *)malloc(sizeof(BTNode));
    n9->key = 9;
    BTNode *n10 = (BTNode *)malloc(sizeof(BTNode));
    n10->key = 10;

    bt->lchild = n4;
    bt->rchild = n8;
    n4->lchild = n3;
    n4->rchild = NULL;
    n8->lchild = n7;
    n8->rchild = n9;
    n3->lchild = NULL;
    n3->rchild = NULL;
    n7->lchild = NULL;
    n7->rchild = NULL;
    n9->lchild = NULL;
    n9->rchild = n10;
    n10->lchild = NULL;
    n10->rchild = NULL;
    //二叉排序树建立完成
}

BTNode *BSTSearch(BTNode *bt, int key)
{
    if (bt == NULL)
        return NULL;
    if (bt->key == key)
        return bt; //返回关键字所在的结点指针
    else if (bt->key > key)
        return BSTSearch(bt->lchild, key); //去左子树中查找
    else
        return BSTSearch(bt->rchild, key);
}

int main()
{
    BTNode *bt;
    createBST(bt);
    BTNode *p = BSTSearch(bt, 3);
    if (p == NULL)
        cout << "没有找到" << endl;
    else
        cout << "找到了 " << p->key << endl;
    return 0;
}
