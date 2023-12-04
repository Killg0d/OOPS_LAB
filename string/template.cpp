#include<iostream>
using namespace std;
template<class T>
T find_min(T* arr,int size)
{
    T min=arr[0];
    for(int i=1;i<size;i++)
    {
        if(arr[i]>arr[i+1])
        {
            min=arr[i+1];
        }
    }
    return min;
}
int main()
{
    int a[]={56,789,342,12};
    double d[]={25.2,75.4};
    char* e="HEllo";
    cout<<"integer:"<<find_min(a,4);
    
    cout<<"double:"<<find_min(d,2);
    
    cout<<"char:"<<find_min(e,4);
    
    return 0;
}