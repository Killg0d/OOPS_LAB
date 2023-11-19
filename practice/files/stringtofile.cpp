/*To create a class employee with code,dept,name*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
class Employee
{
   
    string name;
 

public:
    void getdata();
    void display();
};
void Employee::getdata()
{
   
    cout << "Name:";
    getline(cin,name);
}
void Employee::display()
{
    cout << setw(15) << "Name\n" ;
    cout << setw(15) << name ;
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
        f.display();
    }
        f.display();
        return 0;
}