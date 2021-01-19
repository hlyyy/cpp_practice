#include<iostream>
using namespace std;

class Clock {
    private:
        int hour;
        int mintue;
        int second;

    public:
        Clock(int h = 0, int m = 0, int s = 0) {
            hour = h;
            mintue = m;
            second = s;
        }
        int gethour() {
            return hour;
        }
        int getmintue() {
            return mintue;
        }
        int getsecond() {
            return second;
        }
        void showtime() {
            cout << "the time now is : " << hour << ":" << mintue << ":" << second << endl;
        }
        void run() {
            second++;
            if (second == 60)
            {
                second = 0;
                mintue++;
            }
            if (mintue == 60)
            {
                mintue = 0;
                hour++;
            }
            if (hour == 24)
            {
                hour = 0;
            }
        }
};

class Date {
    private:
        int year;
        int month;
        int day;

    public:
        Date(int y = 2000, int m = 1, int d = 1) {
            year = y;
            month = m;
            day = d;
        } 
        int getyear() {
            return year;
        }
        int getmonth() {
            return month;
        }
        int getday() {
            return day;
        }
        void showdate() {
            cout << "the date is : " << year << "-" << month << "-" << day << endl;
        }
        void newday( ) {
            switch (month)
            {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
                if (day < 31)
                    day++;
                else
                {
                    month++;
                    day = 1;
                }
                break;

            case 4:
            case 6:
            case 9:
            case 11:
                if (day < 30)
                    day++;
                else
                {
                    month++;
                    day = 1;
                }
                break;

            case 12:
                if (day == 31)
                {
                    day = 1;
                    month = 1;
                    year++;
                }
                else
                {
                    day++;
                }
                break;

            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
                {
                    if (day < 29)
                        day++;
                    else
                    {
                        month++;
                        day = 1;
                    }
                }
                else
                {
                    if (day < 28)
                        day++;
                    else
                    {
                        month++;
                        day = 1;
                    }
                }
                break;
            }
        }
};

class ClockWithDate : public Clock, public Date{
    public:
        ClockWithDate(int y, int m, int d, int h, int mm, int s) : Clock(h, mm, s), Date(y, m, d) {
        }
    void showclockwithdate() {
        Date::showdate();
        Clock::showtime();
    }
    void run() {
        Clock::run();
        if (gethour() == 0 && getmintue() == 0 && getsecond() == 0) {
            newday();
        }
    }
};

int main() {
    ClockWithDate c1(2021, 1, 6, 12, 24, 23);
    c1.showclockwithdate();
    for (int i = 0; i < 3600 *24; i++) {
        c1.run();
    }
    c1.showclockwithdate();
    return 0;
}