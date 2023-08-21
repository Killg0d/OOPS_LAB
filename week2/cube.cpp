#include <iostream>
using namespace std;

int main(){
    int num;
    cout<<"Enter a number:";
    cin>>num;
    for(int i=1;i * i * i <=num;i++)
        if ( i * i * i == num ){
            cout<<"The number is a perfect cube"<<endl;
            return 0;
        }
    cout<<"The number is not a perfect cube"<<endl;
    return 0;
}