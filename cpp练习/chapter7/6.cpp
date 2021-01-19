#include<iostream>
using namespace std;

class Shape {
    public:
        Shape() {}
        virtual ~Shape() {}
        virtual double getArea() = 0;
        virtual double getPerimeter() = 0;
};

class Rectangle : public Shape {
    private:
        double l;
        double w;
    
    public:
        Rectangle(double ll = 0, double ww = 0) {
            l = ll;
            w = ww;
        }
        ~Rectangle() {}
        double getArea() {
            return l * w;
        }
        double getPerimeter() {
            return 2 * (l + w);
        }
};

class Circle : public Shape {
    private:
        double radius;

    public:
        Circle(double r = 0) {
            radius = r;
        }
        ~Circle() {}
        double getArea() {
            return 3.14 * radius * radius;
        }
        double getPerimeter() {
            return 2 * 3.14 *radius;
        }
}; 

int main() {
    Shape * p;
    p = new Rectangle(3, 4);
    cout << "the area of my rectangle is : " << p -> getArea() << endl;
    cout << "the perimeter of my rectangle is : " << p -> getPerimeter() << endl;
    delete p;

    p = new Circle(5);
    cout << "the area of my circle is : " << p -> getArea() << endl;
    cout << "the perimeter of my circle is : " << p -> getPerimeter() << endl;
    delete p;

    return 0;
}
