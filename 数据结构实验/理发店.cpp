#include<iostream>
using namespace std;

//定义一个事件的结构体
typedef struct {
    int OccurTime; //事件发生时刻
    int NType; //0表示进门，1表示离开
} ElemType, Event;

//定义一个事件链表
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} *Link, *Position;

//记录事件链表的头尾、长度、以及目前正在等待的第一个顾客
typedef struct List {
    Link head;
    Link tail;
    int len;
    Link current;
} EventList;

//链表的节点，登录排队理发的顾客的信息
typedef struct {
    int ArrivalTime; //顾客到达的时间
    int Duration; //顾客理发的时间
} QElemType;

//链表
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, * QueuePtr;

//链队列
typedef struct Queue{
    QueuePtr front; //队头指针
    QueuePtr rear; //队尾指针
} *LinkQueue;

EventList ev = {nullptr,nullptr,0,nullptr};       //事件表
Event en = {0, 0};           //事件
LinkQueue Q = new Queue;        //等待理发的顾客队列
QElemType customer = {0, 0}; //顾客记录
int t1 = 0, t2 = 0;
int Totaltime = 0;    //累计时间
int CustomerNum = 0;  //累计顾客数
int CloseTime = 20; //关门时间
int CurrentChair = 7; //当前空闲的理发椅子数目
float Totallength = 0; //累计顾客排队长度

//生成一个事件节点
bool MakeNode(Link p, ElemType e)
{
    p->data = e;
    p->next = nullptr;
    return true;
}

//向事件表中插入事件(按事件发生的时间顺序)
bool OrderInsert (EventList &L, ElemType e) {
    Link p;
    p = new LNode;
    if(!MakeNode(p, e))
        return false;
    Link q, r;
    q = L.head;
    r = q->next;

    //cout << "print r :" << endl;
    //将新事件按时间顺序插入
    while (r && (p->data.OccurTime > r->data.OccurTime)) {
        //cout << " " << r->data.OccurTime;
        q = r;
        r = r->next;
    }
    //cout << endl;

    //如果指针为空，新事件将会插入到表尾，否则插到表中
    if (!r) {
        L.tail -> next = p;
        if (L.current == L.tail)
            L.current = p;
        L.tail = p;
    } else {
        p->next = r;
        q->next = p;
        L.current = p;
    }
    //cout << "print L head :" << L.head->next << endl;

    L.len++; //事件表长度加一
    delete p;
    return true;
}

//判断事件表是否为空
bool ListEmpty(EventList &L) {
    if (L.len == 0)
        return true;
    else
        return false;
}

//删除链表中第一个元素，并放入e中
bool DelFirst(EventList &L, ElemType & e)
{
    Link p;
    //cout << "111" << endl;
    if (L.head->next == nullptr)
        return false;
    //cout << "333" << endl;
    p = L.head->next;                  //p指针指向第一个节点
    e.OccurTime = p->data.OccurTime;    //将第一个节点的信息存入e中
    e.NType = p->data.NType;
    //cout << e.OccurTime << e.NType << endl;
    L.head->next = p->next; //删除头结点
    L.len--; //链表长度减一
    return true;
}

//获取当前排队的长度
int QueueLength(LinkQueue  Q) {
    int i;
    QueuePtr p, r;
    p = Q->front;
    r = Q->rear;
    for (i = 0; p != r; i++)
        p = p->next;
    return i;
}

//判断当前队列是否为空
bool QueueEmpty(LinkQueue  Q) {
    if (Q->front == Q->rear)
        return true;
    else
        return false;
}

//生成链队列节点
bool MakeQNode(QNode *p, QElemType e)
{
    p->data = e;
    p->next = nullptr;
    return true;
}

//将顾客入队操作
bool EnQueue(LinkQueue Q, QElemType e) {
    QNode * p;
    p = new QNode;
    if (!MakeQNode(p, e))
        return false;

    Q->rear->next = p;   //p添加到队尾
    Q->rear = p;
    return true;    
}

//将顾客出队操作,并将customer的信息放入e中
void DeQueue(LinkQueue Q, QElemType * e) {
    QNode * p;
    p = Q->front;
    e->ArrivalTime = p->data.ArrivalTime;
    e->Duration = p->data.Duration;
    Q->front = p->next;
    delete p;
}

//初始化顾客排队队列
void InitQueue(LinkQueue Q) {
    Q->front = Q->rear = new QNode;
    Q->front -> next = nullptr;
}

//初始化事件表
void InitList(EventList &L) {
    L.len = 0;
    L.head = L.tail = L.current = new LNode;
    L.head->next = nullptr;
}

//处理顾客到达事件
void CustomerArrived()
{
    QElemType e1;
    ElemType e;
    int durtime;
    int intertime;
    CustomerNum++;          //总顾客数加1
    int R = rand();         //生成一个随机数
    //durtime = 15 + R % 50;  //该顾客理发时间
    //intertime = 2 + R % 10; //下一顾客到达时间间隔

    
    cout << "Input durtime :" ;
    cin >> durtime;
    cout << "Input intertime :";
    cin >> intertime;
    cout << endl;
    
    e.OccurTime = en.OccurTime + intertime;
    if (e.OccurTime > t1)
        t1 = e.OccurTime;

    e.NType = 0; //进门事件设为0

    //如果进门时还未关门，则将该事件插入事件表
    if (e.OccurTime < CloseTime)
    {
        //cout << "e.OccurTime < CloseTime" << e.OccurTime << e.NType << endl;
        OrderInsert(ev, e);
    }

    if (CurrentChair > 0)
    {
        e.OccurTime = en.OccurTime + durtime;
        if (e.OccurTime > t1)
            t1 = e.OccurTime;
        e.NType = 1;

        //cout << "CurrentChair > 0" << e.OccurTime << e.NType << endl;

        OrderInsert(ev, e);
        Totaltime += durtime;
        CurrentChair--;
    }
    else
    {
        e1.ArrivalTime = en.OccurTime; //进门时间
        e1.Duration = durtime;         //理发时间
        EnQueue(Q, e1);                //没有空闲座位，将该顾客入队
        Totallength += QueueLength(Q); //累计队长
    }
}

//处理顾客离开事件
void CustomerDeparture()
{
    int DepartureTime;
    ElemType e;
    if (!QueueEmpty(Q))
    {
        DeQueue(Q, &customer);                             //队不空，第一个顾客出队
        DepartureTime = en.OccurTime + customer.Duration; //计算顾客离开时间
        if (DepartureTime > t2)
            t2 = DepartureTime;

        e.OccurTime = DepartureTime;
        e.NType = 1;
        OrderInsert(ev, e);
        Totaltime += DepartureTime - customer.ArrivalTime; //累计时间
    }
    else
        CurrentChair++;
}

//初始化
void OpenForDay()
{
    InitQueue(Q); //初始化队列
    InitList(ev); //初始化事件表
    ElemType e;   //第一个顾客自定义，后面的顾客随机生成
    e.NType = 0;
    e.OccurTime = 0;
    OrderInsert(ev, e);
}

int main() {
    int i = 0;
    OpenForDay();
    while(!ListEmpty(ev)) {
        DelFirst(ev, en);
        if (en.NType == 0)
            CustomerArrived();  //处理顾客进门事件
        else 
            CustomerDeparture();    //处理顾客离开事件
        i++;
        if (i == 5) break;
    }

    cout << "Number of customer is : " << CustomerNum << endl;  //输出总顾客数
    cout << "Average time is:" << Totaltime/CustomerNum << endl;    //输出平均停留时间
    cout << "Average queue length is :" << Totallength/CustomerNum << endl;     //输出平均队长
    int t = (t1 > t2) ? t1 : t2;
    //cout << "Additon time :" << t - CloseTime << endl;
    return 0;
}







