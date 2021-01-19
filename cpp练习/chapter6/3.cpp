#include<iostream>
using namespace std;

class Circle {
    private:
        double radius;

    public:
        Circle(double r) {
            radius = r;
        }
        void display() {
            cout << "the radius is : " << radius << endl;
        }
};

class Table {
    private:
        double high;
    
    public:
        Table(double h) {
            high = h;
        }
        void dispaly() {
            cout << "the high of this table is : " << high << endl;
        }
};

class RoundTable : public Circle, public Table {
    private:
        string color;

    public:
        RoundTable(double h, double r, string c) : Circle(r), Table(h) {
            color = c;
        } 

        void dispaly() {
            Circle::display();
            Table::dispaly();
            cout << "The color of this table is :" << color << endl;
        }
};

int main() {
    RoundTable r1(1, 3.5, "green");
    r1.dispaly();
    return 0;
}
