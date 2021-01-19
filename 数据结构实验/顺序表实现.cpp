#include <iostream> 
using namespace std;

#define MaxSize 50 

typedef char ElemType; 

typedef struct  { 
    ElemType * data; 
    int length; 
} SqList; 

void InitList(SqList *& L); 
void DestroyList(SqList *L); 
void ClearList(SqList * L);
bool ListEmpty(SqList *L); 
int ListLength(SqList *L); 
void DispList(SqList *L); 
bool GetElem(SqList *L,int i,ElemType &e); 
int LocateElem(SqList *L, ElemType e);
bool PriorElem(SqList *L, ElemType e, ElemType & pre); 
bool NextElem(SqList *L, ElemType e, ElemType & next);
bool ListInsert(SqList * L,int i,ElemType e); 
bool ListDelete(SqList *& L,int i,ElemType &e);

//初始化线性表
void InitList(SqList *& L) { 
    //分配存放线性表的空间，并将线性表长度置0
    L -> data = new ElemType[MaxSize];  
    L -> length = 0;      
} 

//销毁线性表
void DestroyList(SqList *L) { 
    delete [] L -> data;
} 

//将线性表清空
void ClearList(SqList * L) {
    if (L -> data == nullptr)
        cout << "线性表不存在" << endl;

    //将线性表置空
    L -> length = 0;
}

//判断线性表是否为空
bool ListEmpty(SqList *L) { 
    return(L -> length == 0); 
} 

//求线性表长度
int ListLength(SqList *L) { 
    return(L -> length); 
} 

//打印线性表
void DispList(SqList *L) { 
    int i; 

    //如果线性表为空则直接返回
    if (ListEmpty(L)) 
        return; 

    //遍历输出
    for (i = 0; i < L -> length; i++) 
        cout << L -> data[i];

    cout << endl;
} 

//求线性表中序号为i的元素的值
bool GetElem(SqList *L, int i, ElemType &e) {
    //参数不正确时，返回false
    if (i < 1 || i > L -> length) 
        return false;   
    
    //取该元素值
    e = L -> data[i-1];    
    return true;     
} 

//按元素值查找，并返回该元素的序号
int LocateElem(SqList *L, ElemType e) { 
    int i = 0; 

    //顺序查找元素e
    while (i < L->length && L -> data[i] != e) 
        i++;      

    //若 i 大于线性表长度，则没找到，返回0，否则返回该元素的序号
    if (i >= L->length)   
        return 0; 
    else 
        return i+1; 
} 

//返回元素e的直接前驱
bool PriorElem(SqList *L, ElemType e, ElemType & pre) {
    //查找该元素所在的位置
    int i = LocateElem(L, e);

    //没找到该元素则返回false
    if (i == 0) {
        cout << "该元素在线性表中不存在" << endl;
        return false;
    }

    //第一个元素不存在前驱
    if (i == 1) {
        cout << "该元素不存在前驱" << endl;
        return false;
    }

    //找到则将其前驱赋给pre
    pre = L -> data[i - 2];
    return true;
}

//返回元素e的直接后继
bool NextElem(SqList *L, ElemType e, ElemType & next) {
    //查找该元素所在的位置
    int i = LocateElem(L, e);

    //没找到该元素则返回false
    if (i == 0) {
        cout << "该元素在线性表中不存在" << endl;
        return false;
    }

    //如果该元素是线性表最后一个元素，则不存在后继
    if (i == L -> length) {
        cout << "该元素不存在后继" << endl;
        return false;
    }

    //找到则将其后继赋给next
    next = L -> data[i];
    return true;
}
 
//向第i个位置插入数据元素e
bool ListInsert(SqList * L,int i,ElemType e) { 
    int j; 

    //若参数有问题则返回 false
    if (i < 1 || i > L -> length + 1) 
        return false;   
    i--;      

    //将data[i]及后面的元素往后移
    for (j = L -> length; j > i; j--)  
        L -> data[j] = L -> data[j-1]; 
    
    //插入元素e，并让顺序表长度增加1
    L -> data[i] = e;    
    L -> length++;
             
    //插入成功返回true
    return true;  
} 

//删除线性表中第i个位置的元素
bool ListDelete(SqList *& L,int i,ElemType &e) { 
    int j; 

    //若参数有问题则返回 false
    if (i < 1 || i > L -> length)  
        return false; 
    i--;      
    e = L -> data[i]; 

    //将data[i]之后的元素前移一个位置，并让顺序表长度减一
    for (j = i; j < L -> length - 1; j++) 
        L -> data[j] = L -> data[j+1]; 
    L -> length--; 

    //插入成功返回true   
    return true;    //成功删除返回 true 
} 


int main() { 
    SqList *L; 
    ElemType e, pre, next; 
    cout << "顺序表的基本运算如下:" << endl; 

    cout << "  (1)初始化顺序表 L" << endl; 
    InitList(L); 

    cout <<"  (2)依次采用尾插法插入 a,b,c,d,e 元素" << endl; 
    ListInsert(L,1,'a'); 
    ListInsert(L,2,'b'); 
    ListInsert(L,3,'c'); 
    ListInsert(L,4,'d'); 
    ListInsert(L,5,'e'); 

    cout << "  (3)输出顺序表 L:"; 
    DispList(L); 

    cout << "  (4)顺序表 L 长度:" << ListLength(L) << endl; 

    cout << "  (5)顺序表 L 为" << (ListEmpty(L)?"空":"非空") << endl; 

    GetElem(L,3,e); 
    cout << "  (6)顺序表 L 的第 3 个元素=" << e << endl; 

    cout << "  (7)元素 a 的位置为：" << LocateElem(L,'a') << endl; 

    cout << "  (8)在第 4 个元素位置上插入 f 元素 " << endl; 
    ListInsert(L,4,'f'); 
    
    cout << "  (9)输出顺序表 L:"; 
    DispList(L); 
    
    cout << "  (10)删除 L 的第 3 个元素" << endl; 
    ListDelete(L,3,e); 
    
    cout << "  (11)输出顺序表 L:" ; 
    DispList(L);

    PriorElem(L, 'd', pre);
    cout << "  (12)求d的直接前驱为：" << pre << endl;

    NextElem(L, 'd', next);
    cout << "  (13)求d的直接后继为：" << next << endl;

    cout << "  (14)清空顺序表 L" << endl;
    ClearList(L);

    cout << "  (15)输出顺序表 L:" << endl; 
    DispList(L); 

    cout << "  (16)销毁顺序表 L" << endl; 
    DestroyList(L); 

    return 0;
} 