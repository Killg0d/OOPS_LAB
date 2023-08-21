#include <iostream>
using namespace std;

int main(){
    int a,b, flag = 0;
    cout<<"Enter a range :";
    cin>>a>>b;
    for( int i = a ; i <= b ; i++ )
            for( int j = 1 ; j * j * j <= i ; j++ )
                if( j * j * j % i == 0)
                {
                    cout<<i<<" ";
                    flag=1;
                }
    if(flag==0)
        cout<<"The number does not exist";
    return 0;
}