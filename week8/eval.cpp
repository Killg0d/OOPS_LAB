// A new scheme of evaluation of student’s performance is formulated that gives
// weightage for sports. The relationships of different classes and derived classes are
// given below.
//          >Student<
//      ^Exam   ^Sports
//          ^Result^
// By properly assuming the data members & member functions for each class, write
// a C++ program to model the above relationship such that members of the student
// class are not inherited twice.
//Tarun
//230970005
#include <iostream>
#include <cstring>
using namespace std;
class Student
{
    int rollno;
    char name[20];

public:
    //Two variables declared if an instance of the child class is invoked instead of grandchild 
    //then it must also call the functions to getvariables of parent. 
    bool dataReceived;//Checks if the getdata() is already called
    bool dataDisplayed;//Checks if showdata()is already called
    Student() : dataReceived(false),dataDisplayed(false) {}
    Student(int r, char n[]) : rollno(r) { strcpy(name, n); }
    void getdata()
    {
        if (!dataReceived)
        {
            cout << "\nEnter the rollno:";
            cin >> rollno;
            cout << "\nEnter the name:";
            cin >> name;
            dataReceived = true;
        }
    }
    void showdata()
    {   
        if(!dataDisplayed){
        cout << "\nRoll No: " << rollno << "\nName: " << name;
        dataDisplayed=true;
        }
    }
};
class Exam : public virtual Student
{
    int mark1, mark2, mark3;

public:
    Exam()
    {
        mark1 = mark2 = mark3 = 0;
    }
    Exam(int rno, char n[], int m1, int m2, int m3) : Student(rno, n), mark1(m1), mark2(m2), mark3(m3) {}
    void getdata()
    {
        Student::getdata();
        if (dataReceived) {
            cout << "\nEnter the 3 marks:";
            cin >> mark1 >> mark2 >> mark3;
        }
    }
    bool get_fails()
    {
        return (mark1 <= 35 || mark2 <= 35 || mark3 <= 35);
    }
    int get_total()
    {
        return (mark1 + mark2 + mark3);
    }
    void showdata()
    {
        Student::showdata();
        if(dataDisplayed){
        cout << "\nMark 1:" << mark1 << "\nMark 2:" << mark2 << "\nMark 3:" << mark3;
        }
    }
};
class Sports : virtual public Student
{
    int spmark;

public:
    Sports() { spmark = 0; }
    Sports(int rno, char name[], int sm) : Student(rno, name), spmark(sm) {}
    void getdata()
    {
        Student::getdata();
        if (dataReceived)
        {
            cout << "\nEnter the sports marks:";
            cin >> spmark;
        }
    }
    int get_total()
    {
        return spmark;
    }
    void showdata()
    {
        if(dataDisplayed)
        cout << "\nSports Marks:" << spmark;
    }
};

class Result : public Exam, public Sports
{
    int total;
    int average;
    enum Grade
    {
        a = 'A',
        b = 'B',
        c = 'C',
        d = 'D',
        e = 'E',
        f = 'F'
    };
    Grade grade;

public:
    void calc()
    {
        total = Exam::get_total() + Sports::get_total();
    }
    void getdata()
    {
        Exam::getdata();
        Sports::getdata();
    }
    void showdata()
    {
        calc();
        if (get_fails() || Sports::get_total() <= 35 || total/4 <= 35)
            grade = f;
        else if (total / 4 < 60)
            grade = e;
        else if (total / 4 < 70)
            grade = d;
        else if (total / 4 < 80)
            grade = c;
        else if (total / 4 < 90)
            grade = b;
        else
            grade = a;
        Exam::showdata();
        Sports::showdata();
        cout << "\nResult:\nTotal:" << total << "\nAverage:" << (total / 4) << endl
             << "Grade:" << static_cast<char>(grade);
    }
};
int main()
{
    Result r;
    r.getdata();
    r.showdata();
    return 0;
}
