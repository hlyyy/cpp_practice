#include<iostream>
using namespace std;

class Date {
    private:
        int year;
        int month;
        int day;

    public:
        Date(int y = 1, int m = 1, int d = 1) {
            year = y;
            month = m;
            day = d;
        }
    friend ostream & operator << (ostream & os, Date d);
};

ostream & operator << (ostream & os, Date d) {
    os << d.year << "-" << d.month << "-" << d.day << endl;
    return os;
}

int main() {
    Date mydate(2020,1,7);
    cout << mydate;
    return 0;
}