#include <iostream>
#include<cmath>
using namespace std;

int main(){
    int num;
    cout<<"Enter a number:";
    cin>>num;
    int cubeRoot=cbrt(abs(num));
    
        if( cubeRoot * cubeRoot * cubeRoot == abs(num) ){
            cout<<"The number is a perfect cube"<<endl;
            return 0;
        }
    cout<<"The number is not a perfect cube"<<endl;
    return 0;
}