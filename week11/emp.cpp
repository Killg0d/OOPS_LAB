// Write a C++ program to create an employee database and store the following
// information: Name, Employee id, Department, Designation, Basic salary. Then accept
// an employee id from the keyboard and generate the salary slip for that employee. Use
// suitable formulas to calculate DA, HRA, GROSS PAY, INCOME TAX and NET PAY.
// Make use of random-access file concept. (Employee id should be generated
// automatically).
#include <iostream>
#include <fstream>
using namespace std;
class Employee
{
    int id;
    char name[10];
    static int empid;
    char dept[10];
    char design[10];
    float basic_salary;

public:
    void calculate_payslip()
    {
        float da, hra, tax, gross, net;
        da = basic_salary * 0.12;
        hra = basic_salary * 0.14;
        tax = basic_salary * 0.3;
        gross = basic_salary + da + hra;
        net = gross - tax;
        cout << "\nDA=" << da;
        cout << "\nHRA=" << hra;
        cout << "\nGross sal : " << gross;
        cout << "\nTax : " << tax;
        cout << "\nNet sal : " << net;
    }
    friend istream &operator>>(istream &in, Employee &e);
    friend ostream &operator<<(ostream &out, Employee &e);
    friend void searchfile();
};
int Employee::empid = 0;
istream &operator>>(istream &in, Employee &e)
{
    cout << "Enter the details of Employee" << ++e.empid << endl;
    e.id = e.empid;
    cout << e.id;
    cout << "\nEnter the name:";
    in >> e.name;
    cout << "\nEnter the department:";
    in >> e.dept;
    cout << "\nEnter the designation:";
    in >> e.design;
    cout << "\nEnter the basic salary:";
    in >> e.basic_salary;
}
ostream &operator<<(ostream &out, Employee &e)
{
    out << "\nID:" << e.id;
    out << "\nName:" << e.name;
    out << "\nDepartment:" << e.dept;
    out << "\nDesignation:" << e.design;
    out << "\nBasic Salary:" << e.basic_salary;
    return out;
}
void searchfile()
{
    Employee e;
    int id;
    ifstream ifile("emp.txt");
    if (!ifile)
    {
        cout << "\nFile not found";
        exit(0);
    }
    ifile.seekg(0, ios::end);
    int endposition = ifile.tellg();
    cout << "\nThe number of employees:" << endposition / sizeof(Employee);
    cout << "\nEnter the id:";
    cin >> id;
    if (id <= 0)
    {
        cout << "\nId improper";
        exit(0);
    }
    ifile.seekg((id - 1) * sizeof(Employee), ios::beg);
    if (ifile.tellg() >= endposition)
    {
        cout << "ID not present\n";
        exit(1);
    }
    ifile.read((char *)&e, sizeof(e));
    cout << e;
    e.calculate_payslip();
}
void storefile(Employee &e)
{
    ofstream file("emp.txt", ios::app);
    if (file.is_open())
    {
        file.write((char *)&e, sizeof(e));
        file.close();
    }
    else
    {
        cout << "Error opening file email.txt for appending." << endl;
    }
}
int main()
{
    int ch;
    Employee *emp;
    do
    {
        cout << "\n\tMenu" << endl;
        cout << "1.Add new employee." << endl;
        cout << "2.Display pay slip of employee." << endl;
        cout << "3.Exit." << endl;
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            emp = new Employee();
            cin >> *emp;
            storefile(*emp);
            delete emp;
            break;
        case 2:
            searchfile();
            break;
        case 3:
            cout << "\nExit\n";
            break;
        default:
            cout << "\nINVALID CHOICE\n";
            break;
        }
    } while (ch != 3);
}