/*Design the classes using following hierarchical inheritance teaching. Each class has
member functions accept and display. Write a program to accept details of n
instructors and display the details.
*/
#include<iostream>
using namespace std;
class Person{
    int id;
    char name[30];
    public:
       Person():id(0),name("Default"){}
       Person(int i,char n[]):id(i){
        for(int i=0;n[i]!='\0';i++)
            name[i]=n[i];
       } 
       void accept_details(){
        cout<<"\nEnter the id:";
        cin>>id;
        cout<<"\nEnter the name:";
        cin>>name;
       }
       void display(){
        cout<<"\nID = "<<id;
        cout<<"\nNAME = "<<name;
       }
};
class Teaching:public Person{
    char subject[20];
    public:
        Teaching():Person(),subject("Default"){}
        Teaching(int i,char n[],char s[]):Person(i,n){
            for(int i=0;s[i]!='\0';i++)
                subject[i]=s[i];
        }
        void accept_teaching(){
            accept_details();
            cout<<"\nEnter the Subject:";
            cin>>subject;
        }
        void display_teaching(){
            display();
            cout<<"\nSubject = "<<subject;
        }
};
class Nonteaching:public Person{
    char dept[10];
    public:
        Nonteaching():Person(),dept("Default"){}
        Nonteaching(int i, char n[],char d[]):Person(i,d){
            for(int i=0;d[i]!='\0';i++)
                dept[i]=d[i];
        }
        void accept_nonteach(){
            accept_details();
            cout<<"\nEnter the Department:";
            cin>>dept;
        }
        void display_nonteach(){
            display();
            cout<<"\nDepartment = "<<dept;
        }

};
class Instructor:public Person{
    public:
    Instructor():Person(){}
    Instructor(int i,char n[]):Person(i,n){}
};
int main(){
    Instructor I[10];
    int n;
    
    do
    {
        cout<<"\nEnter the number of instructor:";
        cin>>n;
    }while(n<1||n>10);
    for(int i=0;i<n;i++)
        I[i].accept_details();
    for(int i=0;i<n;i++)
        I[i].display();
    return 0;
}