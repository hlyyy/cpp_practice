#include<iostream>
#include<string>
using namespace std;

class Student{
    private:
        string id;  //学生id
        string name;    //学生姓名
        
        double grade1;  //课程1分数
        double grade2;  //课程2分数
        double grade3;  //课程3分数

        static double sum1; //课程1总分
        static double sum2; //课程2总分
        static double sum3; //课程3总分

        static int num; //学生总人数
    public:
        Student(string id, string name, double g1, double g2, double g3) {
            this->id = id;
            this->name = name;
            grade1 = g1;
            grade2 = g2;
            grade3 = g3;

            num++;
            sum1 += grade1;
            sum2 += grade2;
            sum3 += grade3;
        } 
        double average1() {
            return sum1/num;
        }
        double average2() {
            return sum2/num;
        }
        double average3() {
            return sum3/num;
        }
        void display() {
            cout << id << "   " << name << "   " << grade1 << "   " << grade2 << "   " << grade3 << endl;
        }
};

int Student::num = 0;
double Student::sum1 = 0;
double Student::sum2 = 0;
double Student::sum3 = 0;


int main() {
    Student s1("2019213900", "haha", 99, 90, 95);
    Student s2("2019213901", "xixi", 80, 78, 89);
    Student s3("2019213902", "hehe", 90, 56, 91);
    s1.display();
    s2.display();
    s3.display();

    cout << "The average of grade1 is :" << s1.average1() << endl;
    cout << "The average of grade2 is :" << s1.average2() << endl;
    cout << "The average of grade3 is :" << s1.average3() << endl;

    return 0;
}