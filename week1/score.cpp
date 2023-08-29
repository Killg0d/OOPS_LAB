//Program to accept student details and display score card

//tarun

//230970005

//17-08-23

#include<iostream>

#include<iomanip>

using namespace std;

int main()
{
    char name[20];
    char sem[2];
    char grade;
    int reg_no, join_year;
    int m1, m2, m3, m4, m5, sum, avg;
    cout<<"Enter the Name: ";
    cin>>name;
    cout<<"\nEnter the registration number:";
    cin>>reg_no;
    cout<<"\nEnter the semester:";
    cin>>sem;
    cout<<"\nEnter year of joining:";
    cin>>join_year;
    cout<<"\nEnter the marks in 5 subjects: \n";
    cin>>m1>>m2>>m3>>m4>>m5;
    sum=m1+m2+m3+m4+m5;
    avg=sum/5;
    if(avg>=90)
        grade='A';
    else if(avg>79)
        grade='B'; 
    else if(avg>60)
        grade='C'; 
    else if(avg>50)
        grade='D'; 
    else if(avg>39)
        grade='E'; 
    else
        grade='F';
    cout<<"-------------------------------------------------------------------------"<<endl;
    cout<<"\t\t\tScore Card for Student: "<<name<<endl<<endl;

    cout<<setw(20)<<"Registration Number: "<<setw(10)<<left<<reg_no<<setw(10)<<"Semester: "<<setw(24)<<left<<sem<<setw(6)<<"Year: "<<setw(4)<<join_year<<endl;

    cout<<"Grade Assigned: "<<endl;
    cout<<setw(9)<<left<<"Serial No"<<"\tSubject Name\t"<<"\t\tMarks Scored (out of 100)"<<endl;
    cout<<"_________________________________________________________________________"<<endl;
    cout<<setw(9)<<left<<"1"<<setw(30)<<left<<"Object Oriented Programming"<<setw(34)<<right<<m1<<endl;
    cout<<setw(9)<<left<<"2"<<setw(30)<<left<<"DBMS"<<setw(34)<<right<<m2<<endl;
    cout<<setw(9)<<left<<"3"<<setw(30)<<left<<"Research Methodology"<<setw(34)<<right<<m3<<endl; 
    cout<<setw(9)<<left<<"4"<<setw(30)<<left<<"Computational Mathematics"<<setw(34)<<right<<m4<<endl;
    cout<<setw(9)<<left<<"5"<<setw(30)<<left<<"Web Technologies"<<setw(34)<<right<<m5<<endl;
    cout<<endl;
    cout<<setw(59)<<right<<"Total:"<<setw(14)<<right<<sum<<endl;
    cout<<setw(59)<<right<<"Average:"<<setw(14)<<right<<avg<<endl;
    cout<<setw(59)<<right<<"Grade:"<<setw(14)<<right<<grade<<endl;
    return 0;
}