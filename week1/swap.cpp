//Program to swap 2 numbers
//tarun
//230970005
//14-08-2023
#include<iostream>
using namespace std;
int main(){
	int num1,num2;
	cout<<"Enter 2 numbers"<<endl;
	cin>>num1>>num2;
	cout<<"Before swapping num1="<<num1<<" num2="<<num2<<endl;
	num1=num1+num2;
	num2=num1-num2;
	num1=num1-num2;
	cout<<"After swapping num1="<<num1<<" num2="<<num2<<endl;
	return 0;
}