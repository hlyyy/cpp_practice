#include<iostream>
using namespace std;

class String {
    private:
        char * s;
        int len;
    public:
        String() {
            len = 0;
            s = NULL;
        }
        String(const char * p) {
            len = strlen(p);
            s = new char[len+1];
            strcpy(s, p);
        }
        String(String & r) {
            len = r.len;
            s = new char[len+1];
            strcpy(s, r.s);
        }
        ~String() {
            if (s != NULL)
                delete [] s;
            len = 0;
        }

        bool IsSubstring(const char * str) {
            
        }
};