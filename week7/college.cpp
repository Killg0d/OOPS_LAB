// Consider a college that maintains records of its employees. The hierarchical
// relationship of this employee database is divided into a number of classes as shown
// in the figure given below. It contains the data needed for each class. Define
// functions to create the database and retrieve information as needed.
#include <iostream>
#include <cstring>
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
class NonTeaching : public Employee
{
    char grade;

public:
    NonTeaching(){}
    NonTeaching(int code, char name[], char g) : Employee(code, name),grade(g){}
    void getdata(){
        Employee::getdata();
        cout<<"\nEnter the grade:";
        cin>>grade;
    }
    void show(){
        Employee::show();
        cout<<"Grade: "<<grade<<endl;
    }
};
class Faculty : public Employee
{
    char qualification[10];
    int yrs_of_exp;

public:
    Faculty(){}
    Faculty(int code, char name[], char q[], int y) : Employee(code, name)
    {
        strcpy(qualification, q);
        yrs_of_exp = y;
    }
    void getdata()
    {
        Employee::getdata();
        cout << "\nEnter qualification:";
        cin >> qualification;
        cout << "\nEnter years Of Experience:";
        cin >> yrs_of_exp;
    }
    void show()
    {
        Employee::show();
        cout << "Qualification:" << qualification << endl;
        cout << "Years Of Experience:" << yrs_of_exp << endl;
    }
};

class Permanent:public Faculty{
    float basic_pay;
    float academic_allowance;
    public:
        Permanent(){}
        Permanent(int code,char name[],char q[],int y,int b,int a):Faculty(code,name,q,y),basic_pay(b),academic_allowance(a){}
        void getdata(){
            Faculty::getdata();
            cout<<"\nEnter the basic pay:";
            cin>>basic_pay;
            cout<<"\nEnter the academic allowance:";
            cin>>academic_allowance;
        }    
        void show(){
            Faculty::show();
            cout<<"Basic Pay:"<<basic_pay<<endl;
            cout<<"Academic Allowance:"<<academic_allowance<<endl;
        }
};
class Contract:public Faculty{
    int probation;
    public: Contract(){}
            Contract(int i,char n[],char q[],int y,int p):Faculty(i,n,q,y),probation(p){}
            void getdata(){
                Faculty::getdata();
                cout<<"\nEnter Probation:";
                cin>>probation;
            }
            void show(){
                Faculty::show();
                cout<<"Probation Years:"<<probation<<endl;
            }
};
int main(){
    int ch;
    Contract c;
    NonTeaching n;
    Permanent p;
    //system("clear");
    do{
        cout<<"\n1.Non-Teaching\n2.Permanent\n3.Contract\n4.Exit\nEnter your choice:";
        cin>>ch;
        switch(ch){
                case 1:cout<<"Example of Nonteaching\n";
                        n.getdata();
                        n.show();
                        break;
                case 2:
                        cout<<"\nExample of Permanent\n";
                        p.getdata();
                        p.show();
                        break;
                case 3:
                        cout<<"\nExample of Contract\n";
                        c.getdata();
                        c.show();
                        break;
                case 4:ch=4;
                       break;
                default:cout<<"\nInvalid choice\n";
                }
        }while(ch!=4);
        cout<<endl;
        return 0;
}