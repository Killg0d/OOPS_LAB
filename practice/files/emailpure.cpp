#include <iostream>
#include <fstream>
#include<cstring>//used strstr(char[],string) from this
using namespace std;

class Student
{
    char email[50];

public:
    friend istream &operator>>(istream &in, Student &s);//overloaded extraction
    friend ostream &operator<<(ostream &out, Student &s);//overloaded insertion
    void storefile();//function to store contents
    friend void sortcontent();//function to sort contents into different file
};

istream &operator>>(istream &in, Student &s)
{
    cout << "\nEnter the student's email address : ";
    in >> s.email;
    return in;
}

ostream &operator<<(ostream &out, Student &s)
{
    out << "Email: " << s.email << endl;
    return out;
}
void sortcontent()
{
    fstream file("email.txt", ios::in);//open file in in mode
    char ch;
    int countm=0,countg=0;
    if (!file)//check if file exists
    {
        cout << "File not found";
        exit(1);
    }
    Student s;
    ofstream mfile("manipal.txt"),gfile("gmail.txt");//open files using ofstream
    if(!mfile&&!gfile)//check if files exist
    {
        cout<<"Files not Found";
        exit(1);
    }
    while (file.read((char *)&s, sizeof(s)))//read file on loop
    {   
        if(strstr(s.email,"manipal.edu"))//check if match
        {
            mfile.write((char*)&s,sizeof(s));//write to file
            countm++;
        }
        if(strstr(s.email,"gmail.com"))//check if match
        {
            gfile.write((char*)&s,sizeof(s));//write to file
            countg++;
        }
    }
    cout<<"\nCount of emails ending with manipal.edu:"<<countm;
    cout<<"\nCount of emails ending with gmail.com:"<<countg;
}
void Student::storefile()
{
    ofstream file("email.txt", ios::app);//open in append mode
    if (file.is_open())//check if file is open
    {
        file.write((char *)this, sizeof(Student));
        file.close();
    }
    else
    {
        cout << "Error opening file email.txt for appending." << endl;
    }
}
int main()
{
    Student *s;//Pointer to Student
    int ch;
    do
    {
        cout << "\n\tMenu" << endl;
        cout << "1.Add new email." << endl;
        cout << "2.Sort contents of email.txt" << endl;
        cout << "3.Exit." << endl;
        cout << "Enter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            s = new Student();//create an object
            cin >> *s;
            s->storefile();
            delete s;//delete object
            break;
        case 2:
            sortcontent();//sort content
            break;
        case 3:
            cout << "\nExit\n";
            break;
        default:
            cout << "\nINVALID CHOICE\n";
            break;
        }
    } while (ch != 3);
    return 0;
}