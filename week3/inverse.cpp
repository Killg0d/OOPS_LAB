/*Write a C++ program that computes the inverse of an integer and the double of the
inverse. Example: Inverse (1367) = 7631 and double (7631) = 15262. Use functions
for calculating inverse and double of inverse. 
*/
#include<iostream>
using namespace std;
int inverse(int n){
        int rev=0;
        while(n>0){
        rev=rev*10+n%10;
        n/=10;
        }
        return rev;


}
int twice(int var1){
        return var1*2;
}
int main(){
        int n;
        cout<<"Enter a number to check inverse:";
        cin>>n;
        int i=inverse(n);
        int d=twice(i);
        cout<<"Inverse="<<i<<" Double="<<d<<endl;
        return 0;
}