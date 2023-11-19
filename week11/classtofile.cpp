#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;
class Employee
{
    int code;
    char name[50];

public:
    Employee(){}
    Employee(int code, char n[]) : code(code)
    {
        strcpy(name, n);
    }

    void getdata()
    {
        cout << "\nEnter the empcode:";
        cin >> code;
        cout << "\nEnter the empname:";
        cin >> name;
    }
    void show()
    {
        cout << "Employee Code:" << code << endl;
        cout << "Employee Name:" << name << endl;
    }
};
int main(){
    Employee e1;
    e1.getdata();
    ofstream outfile("temp.txt");
    outfile<<"hello";
    cout<<outfile.tellp();
    outfile.seekp(ios::cur);
    o

    return 0;
}