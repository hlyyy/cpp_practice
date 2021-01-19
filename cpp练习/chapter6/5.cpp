#include<iostream>
using namespace std;

class Clock {
    private:
        int h, m, s;

    public:
        Clock(int hh = 0, int mm = 0, int ss = 0) {
            h = hh;
            m = mm;
            s = ss;
        }
        void run() {
            s++;
            if(s == 60) {
                s = 0;
                m++;
            }
            if (m == 60) {
                m = 0;
                h++;
            }
            if (h == 24)  {
                h = 0;
            }
        }
        void showtime() {
            cout << "the time now is : " << h << ":" << m << ":" << s << endl;
        }
        int gethour() {
            return h;
        }
        int getmintue() {
            return m;
        }
        int getsecond() {
            return s;
        }
};

class NewClock : public Clock {
    private:
        string M;
    public:
        NewClock(int mm, int hh, int ss) : Clock(hh, mm, ss) {
            if (hh >= 12)
                M = "PM";
            else
                M = "AM";
        }
        void run() {
            Clock::run();
            if (Clock::gethour() >= 12) 
                M = "PM";
            else
                M = "AM";
        }
        void showtime() {
            Clock::showtime();
            cout << M << endl;  
        }
};

int main() {
    NewClock newone1(12, 56, 23);
    newone1.showtime();
    for (int i = 0; i < 3600; i++) {
        newone1.run();
    }
    newone1.showtime();
    return 0;
}