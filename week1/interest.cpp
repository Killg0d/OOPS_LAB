//compound interest
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    double principal,rate, num, time,compound_int,actual_val=0;
    cout<<"Enter the Principal Amount: ";
    cin>>principal;
    cout<<"Enter Rate of Interest(in %):"; 
    cin >> rate ;
    cout << "Enter Time Period (Years) : "; 
    cin>>time;
    cout<<"Number of times interest is compounded:";
    cin >> num;
    actual_val = principal * pow(1 + (rate/(num*100)),num*time);
    compound_int=actual_val - principal;
    cout<<"Future value="<<actual_val<<endl;
    cout<<"Compound interest="<<compound_int<<endl;
    return 0;
}