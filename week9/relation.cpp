//Write an interactive C++ program to model the above relationship. Assume proper
//data members and member functions for each class.
//Name: Tarun
//Reg no.:230970005
//Date: 30-10-2023

#include<iostream>
#include<cstring>
using namespace std;
class Employee
{
        char name[20];
        int empcode;
public:
        Employee(){}
        Employee(int c,char nm[]){
                empcode=0;
                strcpy(name,nm);
        }
        virtual  void getdata()
        {
                cout<<"\nEnter employee code: ";
                cin>>empcode;
                cout<<"Enter Employee name: ";
                cin>>name;
        }
        virtual void showdata()
        {
                cout<<"\nEmpcode: "<<empcode<<"\nEmployee name: "<<name;
 }
};

class Education
{
        char qual[20];
public:
        virtual void getdata()
        {
                cout<<"Enter qualification : ";
                cin>>qual;
        }

        virtual void showdata()
        {
                cout<<"\nQualification: "<<qual;
        }
};

class Laborer : public Employee
{
        int wage;
public:
        void getdata()
        {
                Employee::getdata();
                cout<<"Enter wage: ";
                cin>>wage;
        }
        void showdata()
        {
                Employee::showdata();
                cout<<"\nWage : "<<wage;
        }
};

class Scientist : public Employee, public Education
{
        int publications;
public:
        void getdata()
        {
                Employee::getdata();
                Education::getdata();
                cout<<"Enter no. of publication: ";
                cin>>publications;
        }
        void showdata()
        {
                    Employee::showdata();
                Education::showdata();
                cout<<"\nNo. of publications: "<<publications;
        }
};

class Manager : public Employee, public Education
{
        char title[20];
        char dues[30];
public:
        void getdata()
        {
                Employee::getdata();
                Education::getdata();
                cout<<"Enter manager title: ";
                cin>>title;
                cout<<"Enter the dues: ";
                cin>>dues;
        }
        void showdata()
        {
                Employee::showdata();
                Education::showdata();
                cout<<"\nTitle: "<<title;
                cout<<"\nDues: "<<dues;
        }
};

int main()
{
        Employee *eptr;
        int ch;
        while(ch!=4)
        {
              cout<<"\n\n1.Laborer \n2.Scientist \n3.Manager \n4.Exit \nEnter your choice: ";
              cin>>ch;
               switch(ch){
                        case 1: eptr=new Laborer();
                                eptr->getdata();
                                eptr->showdata();
                                delete eptr;
                                break;
                        case 2: eptr=new Scientist();
                                eptr->getdata();
                                eptr->showdata();
                                delete eptr;
                                break;
                        case 3: eptr=new Manager();
                                eptr->getdata();
                                eptr->showdata();
                                delete eptr;
                                break;
                        case 4: break;
                        default: cout<<"\nInvalid choice!"<<endl;
                }
        }
        return 0;
}

