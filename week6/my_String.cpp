//Write a C++ program to overload the relational operators <= to compare 2 objects
//of my_String class
//tarun
//230970005
//18-09-2023
#include<iostream>
using namespace std;
class my_String{
        char ch[20];
        public: void getdata();
        bool operator<=(my_String);
};
void my_String::getdata(){
        cout<<"Enter a String:";
        cin>>ch;
}
bool my_String::operator<=(my_String S){
        for(int i =0; ch[i]!='\0'||S.ch[i]!='\0';i++)
                if(ch[i]==S.ch[i])
                        continue;
                else if(ch[i]<S.ch[i])
                        return 1;
                else
                        return 0;
        return 1;
}
int main(){
        system("clear");
        my_String s1,s2;
        s1.getdata();
        s2.getdata();
        if(s1<=s2)
                cout<<"String1 is smaller than or equal to string 2"<<endl;
        else cout<<"String2 smaller than string 1"<<endl;
        return 0;
        cout<<endl;
}