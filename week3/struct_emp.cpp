/*Given that an EMPLOYEE structure contains following members. Data members:
Employee_Number, Employee_Name, Basic, DA, IT, Net_Sal. Write functions: To
read the data, calculate net salary and display the net salary. Write a C++ program
to read the data of N employees and compute Net salary of each employee. (DA=
12% of Basic and Income Tax (IT) = 18% of the gross salary). */
//tarun
//23097005
//1-09-2023
#include<iostream>
using namespace std;
struct emp{
        int emp_no;
        char name[25];
        float basic,da,it,net_sal;
};
void get_data(emp &n){
        cout<<"\nEnter emp no:";
        cin>>n.emp_no;
        cout<<"\nEnter Name:";
        cin>>n.name;
        cout<<"\nEnter the basic salary:";
        cin>>n.basic;
}
void cal_net(emp &n){
    n.da = 0.12 * n.basic;
    float gross=n.basic+n.da;
    n.it = 0.18 * gross;
    n.net_sal = gross - n.it;
    }
void display(emp &n){
        cal_net(n);
    cout<<"Display the results:\n";
    cout << "\nEmployee Number: " << n.emp_no;
    cout << "\nEmployee Name: " << n.name;
    cout << "\nNet Salary: " << n.net_sal << "\n"<<endl;
}
int main(){
        system("clear");
        int n=0,ch;
        emp e[25];
        cout<<"Enter number of employees:";
        cin>>n;
         cout<<"\nRead the emplyees:";
                        for(int i=0;i<n;i++)
                        {
                                get_data(e[i]);

                        }



          for(int i=0;i<n;i++)
                        {
                                display(e[i]);

                        }

        return 0;
}
           