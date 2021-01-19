#include<iostream>
using namespace std;

class Building {
    private:
        int num;    //建筑编号
        int floor;  //建筑层数
        int room;    //建筑房间数
        double area;    //建筑面积

    public:
        Building(int n, int f, int r, double a) {
            num = n;
            floor = f;
            room = r;
            area = a;
        }
        void show() {
            cout << "the num of this building is : " << num << endl;
            cout << "the floor of this building is : " << floor << endl;
            cout << "the room of this building is : " << room << endl;
            cout << "the area of this building is : " << area << endl;
        }
};

class Teaching_Building : public Building {
    private:
        string des;
    public:
        Teaching_Building(int n, int f, int r, double a, string d) : Building(n, f, r ,a) {
            des = d;
        }
 
        void show() {
            Building::show();
            cout << "the describe of this teaching building is :" << des << endl;
        }
};

class Dorm_Building : public Building {
    private:
        int student_num;    //能容纳的学生总人数

    public:
        Dorm_Building(int n, int f, int r, double a, int s) : Building(n, f, r, a) {
            student_num = s;
        }
        void show() {
            Building::show();
            cout << "the student num of this dorm building is : " << student_num << endl; 
        }
};

int main () {
    Teaching_Building b1(8, 3, 30, 200.5, "这是8号教学楼");
    Dorm_Building b2(1, 8, 200, 400, 400);

    b1.show();
    b2.show();
    return 0;
}