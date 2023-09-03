//Write a C++ program to calculate mean, standard deviation, variance of the input
//data points.
//tarun
//230970005
//-9-23
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
float sum(float a[],int n){
    float sum=0;
    for(int i=0;i<n;i++)
        {
            sum+=a[i];
        }
        return sum;
}
float mean(float a[], int n){
    return sum((a),n)/n;
}
float standard_dev(float a[],int n){
    float var=0;
    for (int i = 0; i < n; i++)
    {
        var += pow((a[i]-mean(a,n)),2)/n;
    }
    return var;
}
int main() {
    int n;
    float array[50];
    cout<<"Enter number of elements: ";cin>>n;
    cout<<"\nEnter "<< n <<" numbers:\n";
    for(int i=0;i<n;i++)
    {
        cin>>array[i];
    }
    
    cout<<"Mean(X) = "<<mean(array,n)<<endl;
    cout<<"Std_deviation(X) = "<<setprecision(3)<<standard_dev(array,n)<<endl;
    cout<<"var(X) = "<<setprecision(3)<<sqrt(standard_dev(array,n));
    cout<<endl;
    return 0;
}