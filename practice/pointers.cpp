#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class Account{
    double balance;
    char fname[20];
    public:
    void add_ac(double b, char *f){
        balance=b;
        strcpy(fname,f);
    }
    void get_acc(double &b,char *f){
        b=balance;
        strcpy(f,fname);
    }
}
;
int main(){
    for(int i=0;i<10;i++)
        cout<<i<<endl;
    return 0;
}