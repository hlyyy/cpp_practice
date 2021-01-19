#include<iostream>
using namespace std;

class Location {
    private:
        int x, y;
    public:
        Location(int xx = 0, int yy = 0) {
            x = xx;
            y = yy;
        }
        Location & operator + (Location & l) {
            x += l.x;
            y += l.y;
            return * this;
        }

        Location & operator - (Location & l) {
            x -= l.x;
            y -= l.y;
            return * this; 
        }
        void display() {
            cout << "(" << x << "," << y << ")" << endl;
        }
};

int main() {
    Location l1(10,10);
    Location l2(5,5);
    l1.display();
    l1 = l1 + l2;
    l1.display();
    l1 = l1 - l2;
    l1.display();
    return 0;
}