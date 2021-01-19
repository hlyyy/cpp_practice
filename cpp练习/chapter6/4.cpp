#include<iostream>
using namespace std;

class Person{
    private:
        string name;
        int sex;
        string id;
        string birth_day;

    public:
        Person(string n, int s, string i, string b) {
            name = n; 
            sex = s; 
            id = i;
            birth_day = b;
        }
        
        void display() {
            cout << "the name of this person is : " << name << endl;
            cout << "the sex of this person is : " << sex << endl;
            cout << "the id of this person is : " << id << endl;
            cout << "the birth day of this person is : " << name << endl;
        }
};

class Student : virtual public Person {
    private:
        string st_id;
        int grade;
    
    public:
        Student(string n, int s, string i, string b, string sid, int g) : Person(n, s, i, b) {
            st_id = sid;
            grade = g;
        }
        void display() {
            cout << "the student id of this student is : " << st_id << endl; 
        }
};

class Teacher : virtual public Person {
    private:
        string position;
    
    public:
        Teacher(string n, int s, string i, string b, string p) : Person(n, s, i, b) {
            position = p;
        }
        void display() {
            cout << "the position of this teacher is : " << position << endl;
        }
};

class Stu_Teach : public Student, public Teacher{
    public:
        Stu_Teach(string n, int s, string i, string b, string sid, int g, string p) : Person(n, s, i, b), Student(n, s, i, b, sid, g), Teacher(n, s, i, b, p) {
        }
    void display() {
        Person::display();
        Student::display();
        Teacher::display();
    }
};

int main() {
    Stu_Teach st("huanglingyun", 0, "2019213900", "2002-01-30", "2019213900", 100, "haha");
    st.display();
    return 0;
}