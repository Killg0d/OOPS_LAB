//Program to convert seconds into hrs mins and secs
//230970005
//tarun
//14-08-23
#include<iostream>
using namespace std;
int main(){
    int sec=0,min=0,hr=0;
    cout<<"Enter the seconds:";
    cin>>sec;
    while(sec>60)
    {
        min++;
        sec=sec-60;
    }
    while(min>60)
    {
        hr++;
        min=min-60;
    }
    cout<<"Converted time is:"<<hr<<" hour "<<min<<" minute "<<sec<<" second "<<endl;
    return 0;
}