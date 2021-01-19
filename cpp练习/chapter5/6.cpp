#include<iostream>
#include<string>
using namespace std;
const int N = 10;

class Users{
    private:
        string name[N];
        string password[N];

        static int num;
    public:
        Users(string n, string p) {
            name[num] = n;
            password[num] = p;
            num ++;
        }
        void addUser(string n, string p) {
            name[num] = n;
            password[num] = p;
            num++;
        }
        void login(string n, string p) {
            for (int i = 0; i < num; i++) {
                if (name[i] == n && password[i] == p) {
                    cout << "login successfully!" << endl;
                    return;
                }
            }
            cout << "login failed!" << endl;
            return;
        }
};

int Users::num = 0;

int main() {
    Users myusers("haha", "1234");
    myusers.addUser("xixi", "23435");
    myusers.addUser("hehe", "897987");
    myusers.addUser("lala", "234345");
    myusers.login("xixi", "123321");
    myusers.login("lala", "234345");
    return 0;
}
