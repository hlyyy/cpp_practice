#include<iostream>
using namespace std;

class Felid {
    public:
        Felid() {}
        virtual ~Felid() {}
        virtual void sound() = 0;
};

class Cat : public Felid {
    public:
        Cat() {}
        ~Cat() {}
        void sound() {
            cout << "miaomiaomiao" << endl;
        }
};

class Leopard : public Felid {
    public:
        Leopard() {}
        ~Leopard() {}
        void sound() {
            cout << "aoaoao" << endl;
        }
};

int main() {
    Felid * p;
    p = new Cat;
    p -> sound();
    delete p;

    p = new Leopard;
    p -> sound();
    delete p;

    return 0;
}