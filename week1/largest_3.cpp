//Program to find largest of 3 nos
//230970005
//tarun
//14-08-23
#include<iostream>
using namespace std;
int main(){
    int num1,num2,num3;
    cout<<"Enter 3 numbers:";
    cin>>num1>>num2>>num3;
    if(num1>num2){
        if(num1>num3)
            cout<<"num1 "<<num1<<" is the largest"<<endl;
        else
            cout<<"num3 "<<num3<<" is the largest"<<endl;
    }
    else if(num2>num3)
        cout<<"num2 "<<num2<<" is the largest"<<endl;
    else
        cout<<"num3 "<<num3<<" is the largest"<<endl;
    
    return 0;
}