//Write a program to compute cube of a number using inline function. 
#include<iostream>
using namespace std;
inline int cube(int a){ return a* a* a;}
int main()
{
        int n;
        //system("clear");
        cout<<"Enter a number to find cube:";
        cin>>n;
        cout<<"Cube ="<<cube(n)<<endl;
        return 0;
}
