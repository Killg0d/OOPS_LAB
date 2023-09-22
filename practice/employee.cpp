/*To create a class employee with code,dept,name*/
#include<iostream>
#include<iomanip>
using namespace std;
class Employee{
    int code;
    char name[50];
    char dept[10];
    public:
    void getdata();
    void display();
};
void Employee::getdata(){
    cout<<"Code:";
    cin>>code;
    cin.ignore();
    cout<<"Name:";
    cin.getline(name,50);
    cout<<"Dept:";
    cin>>dept;
}
void Employee::display(){
    cout<<setw(3)<<"\nCode"<<setw(15)<<"Name"<<setw(10)<<"Dept\n";
    cout<<setw(3)<<code<<setw(15)<<name<<setw(10)<<dept;
}
int main(){
    Employee e;
    e.getdata();
    e.display();
    return 0;
}