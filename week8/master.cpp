// Consider the following: The class Master derives information from both Account
// and Admin classes, which in turn derive information from the class Employee.
// Define all the 4 classes and write a program to create, update, and display the
// information contained in the Master object.
// tarun
// 230970005
// 23-10-23
#include <iostream>
#include <cstring>
using namespace std;
class Employee
{
        int id;
        char name[30];

public:
        Employee() {}
        Employee(int i, char n[]) : id(i)
        {
                strcpy(name, n);
        }
        void getdata()
        {
                cout << "\nEnter the id:";
                cin >> id;
                cout << "\nEnter the name:";
                cin >> name;
        }
        void updatename()
        {
                cout << "\nEnter New name:";
                cin >> name;
        }
        void showdata()
        {
                cout << "\nID = " << id;
                cout << "\nNAME = " << name;
        }
};
class Account : public virtual Employee
{
        int pay;

public:
        Account() {}
        Account(int id, char name[], int p) : Employee(id, name), pay(p) {}
        void getdata()
        {
                cout << "\nEnter the basic pay:";
                cin >> pay;
        }
        void updatepay()
        {
                cout << "\nEnter New pay:";
                cin >> pay;
        }
        void showdata()
        {
                cout << "\nBasic Pay:" << pay;
        }
};

class Admin : public virtual Employee
{
        int exp;

public:
        Admin() {}
        Admin(int id, char name[], int e) : Employee(id, name), exp(e) {}
        void getdata()
        {
                cout << "\nEnter the experience:";
                cin >> exp;
        }
        void updateexperience()
        {
                cout << "\nEnter new Experience:";
                cin >> exp;
        }
        void showdata()
        {
                cout << "\nExperience:" << exp;
        }
};
class Master : public Admin, public Account
{
public:
        void getdata()
        {
                Employee::getdata();
                Account::getdata();
                Admin::getdata();
        }
        void showdata()
        {
                Employee::showdata();
                Account::showdata();
                Admin::showdata();
        }
};
int main()
{
        Master m;
        int ch, ch2;
        while (ch != 4)
        {
                cout << "\n\n1.Create\n2.Update\n3.Display\n4.Exit\nEnter your choice:";
                cin >> ch;
                switch (ch)
                {
                case 1:
                        m.getdata();
                        break;
                case 2:
                        cout << "\n1.Name\n2.Pay\n3.Exp\nEnter your choice:";
                        cin >> ch2;
                        if (ch2 == 1)
                                m.updatename();
                        else if (ch2 == 2)
                                m.updatepay();
                        else if (ch2 == 3)
                                m.updateexperience();
                        else
                                cout << "\nInvalid Choice\n";
                        break;
                case 3:
                        m.showdata();
                        break;
                case 4:
                        cout << "\nExit";
                        break;
                default:
                        cout << "\nInvalid choice\n";
                }
        }
        cout << endl;
        return 0;
}
