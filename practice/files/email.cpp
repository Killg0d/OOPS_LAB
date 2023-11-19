#include <iostream>
#include <fstream>
using namespace std;

class Student
{
    char email[50];

public:
    friend istream &operator>>(istream &in, Student &s);
    friend ostream &operator<<(ostream &out, Student s);
    friend void find_end(Student &);
    friend void process_content();
};

// void find_end(Student &s)
// {
//     size_t found = s.email.find("manipal.edu");
//     if (found != string::npos)
//     {
//         fstream iofile("manipal.txt", ios::binary | ios::app);
//         iofile.write((char *)&s, sizeof(s));
//         return;
//     }
//     found = s.email.find("gmail.com");
//     if (found != string::npos)
//     {
//         ofstream file("gmail.txt", ios::app | ios::binary);
//         file.write((char *)&s, sizeof(s));
//         return;
//     }
// }

istream &operator>>(istream &in, Student &s)
{
    cout << "\nEnter the student's email address : ";
    in >> s.email;
    ofstream file("email.txt", ios::app);
    if (file.is_open())
    {
        file.write((char *)&s, sizeof(s));
        file.close();
    }
    else
    {
        cout << "Error opening file email.txt for appending." << endl;
    }
    return in;
}

ostream &operator<<(ostream &out, Student s)
{
    ifstream ifile("email.txt");
    out << s.email;
    return out;
}

void process_content()
{
    cout << "Working\n";
    Student d;
    int countm = 0, counts = 0;
    ifstream ifile("email.txt", ios::binary);
    if (!ifile)
    {
        cout << "\ncannot open file";
        exit(1);
    }
    ifile.seekg(ios::beg);
    cout<<sizeof(d);
    while (ifile.read((char *)&d, sizeof(d)))
    {
        cout<<d.email;
        // size_t found = d.email.find("manipal.edu");
        // if (found != string::npos)
        // {
        //     fstream iofile("manipal.txt", ios::binary | ios::app);
        //     iofile.write((char *)&d, sizeof(d));
        //     countm++;
        // }
        // else
        // {
        //     found = d.email.find("gmail.com");
        //     if (found != string::npos)
        //     {
        //         ofstream file("gmail.txt", ios::binary | ios::app);
        //         file.write((char *)&s, sizeof(s));
        //         counts++;
        //     }
        // }
    }

    if (ifile.eof())
    {
        // Successfully reached end of file
        ifile.close();
    }
    else
    {
        // Error reading file
        cout << "\nError reading file.";
        exit(1);
    }

    cout << "\nIDs ending with manipal.edu: " << countm;
    cout << "\nIDs ending with gmail.com: " << counts;
}
int main()
{
    const int numStudents = 2; // You can change this to the desired number of students
    Student s[numStudents];

    for (int i = 0; i < numStudents; i++)
    {
        cin >> s[i];
    }

    //process_content();

    return 0;
}
