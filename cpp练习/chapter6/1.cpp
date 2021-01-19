#include<iostream>
using namespace std;

class Point {
    private:
        double x, y;

    public:
        Point(double xx, double yy) {
            x = xx; 
            y = yy;
        }
};

class Rectangle : public Point {
    private:
        double a, b;

    public:
        Rectangle(double xx, double yy, double aa, double bb) : Point(xx, yy){
            a = aa;
            b = bb;
        }
        double area() {
            return a * b;
        }
};

class Circle : public Point {
    private:
        double radius;

    public:
        Circle(double xx, double yy, double r) : Point(xx, yy) {
            radius = r;
        }

        double area() {
            return 3.14 * radius *radius;
        }
};

int main() {
    Rectangle r1(1, 2, 3, 4);
    Circle c1(1, 2, 5);

    cout << "The area of my rectangle is :" << r1.area() << endl;
    cout << "The area of my circle is : " << c1.area() << endl;
    return 0;
}



