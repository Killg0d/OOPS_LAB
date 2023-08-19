//program to find area of circle and triangle
//230970005
//tarun
//14-08-23
#include<iostream>
using namespace std;
int main(){
    double area,radius,height,base;
    cout<<"Enter the radius of circle:";
    cin>>radius;
    area=3.14159*radius*radius;
    cout<<"Area of the circle="<<area<<endl;
    cout<<"Enter the base and height:";
    cin>>base>>height;
    area=0.5*base*height;
    cout<<"Area of the triangle="<<area<<endl;

    return 0;
}