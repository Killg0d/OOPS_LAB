#include<iostream>
using namespace std;
template <class atype>
atype avg_array(atype *aname,int size)
{
    atype avg;
    for(atype i=0;i<size;i++)
    avg+=aname[i];
    return avg/size;
}
int avg_array(char* aname,int size){
    int avg;
    for(int i=0;i<size;i++)
    avg+=aname[i];
    return avg/size;
}
int main()
{
    int i[]={10,20,30,40};
    int i_avg=0;
    i_avg=avg_array(i,4);
    char c[]="Hello";
    cout<<avg_array(c,5);
    cout<<i_avg;
    return 0;
}