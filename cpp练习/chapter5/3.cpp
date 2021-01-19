#include <iostream>
using namespace std;

class Date {
    private:
        int y, m, d;
    public:
        Date(int yy, int mm, int dd) {
            y = yy;
            m = mm; 
            d = dd;
        }
        void NewDay() {
            switch (m) {
                case 1:
                case 3:
                case 5: 
                case 7:
                case 8:
                case 10:
                    if (d < 31) 
                        d++;
                    else {
                        m++;
                        d = 1;
                    }
                    break;

                case 4:
                case 6:
                case 9:
                case 11:
                    if (d < 30)
                        d++;
                    else
                    {
                        m++;
                        d = 1;
                    }
                    break;

                case 12:
                    if (d == 31) {
                        d = 1;
                        m = 1;
                        y++;
                    } else {
                        d++;
                    }
                    break;
                
                case 2:
                    if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
                        if (d < 29)
                            d++;
                        else {
                            m++;
                            d = 1;
                        }
                    } else {
                        if (d < 28)
                            d++;
                        else
                        {
                            m++;
                            d = 1;
                        }
                    }
                    break;
            }
        }
        void display() {
            cout << "year :" << y << " month :" << m << " day :" << d << endl;
        }
};

int main() {
    Date mydate(2020,2,29);
    mydate.display();
    mydate.NewDay();
    mydate.display();
    return 0;
}