//Program to swap 2 numbers
#include<iostream>
using namespace std;
int main(){
	int num1,num2;
	cout<<"Enter 2 numbers";
	cin>>num1>>num2;
	num1=num1+num2;
	num2=num1-num2;
	num1=num1-num2;
	cout<<"num1="<<num1<<" num2="<<num2<<endl;
}