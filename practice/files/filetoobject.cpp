/*To create a class employee with code,dept,name*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Employee
{
    int code;
    char name[50];
    char dept[10];

public:
    void getdata();
    void display();
};
void Employee::getdata()
{
    cout << "Code:";
    cin >> code;
    cin.ignore();
    cout << "Name:";
    cin.getline(name, 50);
    cout << "Dept:";
    cin >> dept;
}
void Employee::display()
{
    cout << setw(3) << "\nCode" << setw(15) << "Name" << setw(10) << "Dept\n";
    cout << setw(3) << code << setw(15) << name << setw(10) << dept;
}
int main()
{
    Employee e[10],f;
    e[1].getdata();
    e[2].getdata();
    fstream iofile("obj.dat", ios::out | ios::binary);
    iofile.write((char *)(&e[1]), sizeof(e[1]));
    iofile.close();
    iofile.open("obj.dat", ios::in | ios::binary);
    while (true)
    { 
        // read type of next employee
        iofile.read((char *)&f, sizeof(e));
        if (iofile.eof()) // quit loop on eof
           break;
        if (!iofile) // error reading type
        {
            cout << "\nCan't read type from file\n";
            return 1;
        }
    }
        f.display();
        return 0;
}