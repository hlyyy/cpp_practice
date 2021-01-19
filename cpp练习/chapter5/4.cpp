#include<iostream>
using namespace std;

class Clock {
    private:
        int h, m, s, h1, m1, s1;
    public:
        Clock(int hour = 0, int mintue = 0, int second = 0) {
            h = hour;
            m = mintue;
            s = second;
        }
        void SetAlarm(int hour, int mintue, int second) {
            h1 = hour;
            m1 = mintue;
            s1 = second;
        }
        void run() {
            s++;
            if (s == 60) {
                m++;
                s = 0;
            }
            if (m == 60) {
                h++;
                m = 0;
            }
            if (h == 24) {
                h = 0;
            }
            if (s == s1 && m == m1 && h == h1) 
                cout << "di di di !" << endl;
        }
        void display() {
            cout << "Now the time is : " << h << ":" << m << ":" << s << endl;
        }
};

int main() {
    Clock myclock(14,38,27);
    myclock.SetAlarm(16,34,23);
    myclock.display();
    for (int i = 0; i < 3600 * 3; i++) {
        myclock.run();
    }
    myclock.display();
    return 0;
}