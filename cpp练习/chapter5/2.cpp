#include <iostream>
#include <cmath>
using namespace std;

class Point {
    private:
        double x, y;
    public:
        Point(double xx, double yy) {
            x = xx;
            y = yy;
        }
        double Distance(const Point &p) {
            return sqrt((x - p.x)*(x - p.x) + (y - p.y)*(y - p.y));
        }
};

int main() {
    Point point1(3.4, 6.7);
    Point point2(4.4, 7.7);
    cout << "The distance between point1 and point2 is :" << point1.Distance(point2) << endl;
    return 0;
}