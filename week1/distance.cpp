//Program to convert mm to cm,inch,feet
#include<iostream>
using namespace std;
int main(){
    double mm,cm,inch,feet;
    cout<<"Enter the distance in mm:";
    cin>>mm;
    cm=mm/10.0;
    inch=cm/2.5;
    feet=inch/12.0;
    cout<<"Distance in cm="<<cm<<" inch="<<inch<<" feet="<<feet<<endl;
    return 0;
} 