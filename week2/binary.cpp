#include <iostream>
using namespace std;
int main() {
    int decimalNumber;
    cout << "Enter a decimal number: ";
    cin >> decimalNumber;

    int a[32],i,n=decimalNumber;
    
cout << "Binary representation: "<< endl;
    if (decimalNumber == 0) {
        cout<<"0";
    }
else {
    for(i=0;n>0;i++)
    {
        a[i]=n%2;
        n/=2;
    }
    
    for(i=i-1;i>=0;i--)
    {
        cout<<a[i];
    }

    }

    return 0;
}