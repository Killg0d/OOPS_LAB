#include<iostream>
#include<fstream>
using namespace std;
class Student
{
    public:
    char email[50];
};
int main(){
fstream file("email.txt",ios::in);
char ch;
if(!file){
    cout<<"File not found";
    return 1;
}
Student s;

while(file.read((char*)&s,sizeof(s))){
    cout<<s.email;
    cout<<endl;
}
    //cout<<"not working";
}