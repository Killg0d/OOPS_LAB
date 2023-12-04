#include<iostream>
using namespace std;
char* encrypt(char* c,int k)
{
    for(int i=0;c[i]!='\0';i++)
    {
        c[i]+=k;
    }
    return c;
}
char* decrypt(char* c,int k)
{
    for(int i=0;c[i]!='\0';i++)
    {
        c[i]-=k;
    }
    return c;
}
int main()
{
    char c[]="hello";
    int key=4;
    char* (*func)(char*,int);
    func = encrypt;
    char* e=(*func)(c,key);
    cout<<e<<endl;
    func = decrypt;
    cout<<(*func)(e,key);
    return 0;
}