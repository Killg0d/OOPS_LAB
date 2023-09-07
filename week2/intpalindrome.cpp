#include<iostream>
using namespace std;
bool intpalindrome(int n){
        int rev=0;
        int temp=n;
        cout<<temp;
        while(n>0){
        rev=rev*10+n%10;
        n/=10;
        }
        cout<<rev;
        if (temp==rev)
        return true;
        else
        return false;
}
int main(){
        int n;
        cout<<"Enter a number to check inverse:";
        cin>>n;
        if(intpalindrome(n))
        cout<<"number is palindrome";
        else 
        cout<<"number is not palindrome";
        cout<<endl;
        return 0;
}