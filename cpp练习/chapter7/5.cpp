#include<iostream>
using namespace std;

class Vehicle {
    public:
        Vehicle() {
            cout << "Vehicle constructing ..." << endl;
        }
        virtual ~Vehicle() {
            cout << "Vehicle destructing ..." << endl;
        }
        virtual void display() = 0;
};

class Car : public Vehicle {
    public:
        Car() {
            cout << "Car constructing ..." << endl;
        }
        ~Car() {
            cout << "Car destructing ..." << endl;
        }
        void display () {
            cout << "This is a car !" << endl;
        }
};

class Truck : public Vehicle {
    public:
        Truck() {
            cout << "Truck constructing ..." << endl;
        }
        ~Truck() {
            cout << "Truck destructing ..." << endl;
        }
        void display() {
            cout << "This is a truck !" << endl;
        }
};

class Boat : public Vehicle {
    public :
        Boat() {
            cout << "Boat constructing ..." << endl;
        }
        ~Boat() {
            cout << "Boat destructing ..." << endl;
        }
        void display() {
            cout << "This is a Boat !" << endl;
        }
};

int main() {
    Vehicle * p;
    p = new Car;
    p -> display();
    delete p;

    p = new Boat;
    p -> display();
    delete p;

    p = new Truck;
    p -> display();
    delete p;

    return 0;
}