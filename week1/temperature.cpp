//Program to convert °F to °C and vica versa
#include<iostream>
using namespace std;
int main(){
    double celsius,fahrenheit;
    cout<<"Enter the temperature in fahrenheit:";
    cin>>fahrenheit;
    celsius=5*(fahrenheit-32)/9;
    cout<<"Celsius="<<celsius<<endl;
    cout<<"Enter the temperature in celsius:";
    cin>>celsius;
    fahrenheit=9*celsius/5+32;
    cout<<"Fahrenheit="<<fahrenheit<<endl;
    return 0;
}