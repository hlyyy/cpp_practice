#include <iostream>
#include <cmath>
using namespace std;

class Ctriangle {
    private:
        double a, b, c;
    public:
        Ctriangle(double aa, double bb, double cc) {
            a = aa;
            b = bb;
            c = cc;
        }
        double getPerimeter() {
            return a + b + c;
        }
        double getArea() {
            double l = getPerimeter()/2;
            return sqrt(l * (l - a) * (l - b) * (l - c));
        }
        void dispaly() {
            cout << "The perimeter of Ctriangle is :" << getPerimeter() << endl;
            cout << "The area of Ctriangle is :" << getArea() << endl;
        }
};

int main() {
    Ctriangle mytriangle(3,4,5);
    mytriangle.dispaly();
    return 0;
}