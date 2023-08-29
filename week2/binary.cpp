#include <iostream>
using namespace std;
int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    int a[32],i,n=decimalNumber;
    
    if (decimalNumber == 0) {
        cout<<"0";
    } 
    for(i=0;n>0;i++)
    {
        a[i]=n%2;
        n/=2;
    }
    cout << "Binary representation: "<< endl;
    for(i=i-1;i>=0;i--)
    {
        cout<<a[i];
    }

    

    return 0;
}