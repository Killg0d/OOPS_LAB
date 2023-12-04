#include<iostream>
using namespace std;
add(void){
    int a=10;
    return a;
}
int main() 
{
    string s1("**Computer***Application**"),s2,s3;
    s2="Master of"+s1;
    cout<<s2;
    for(int i=0;i<s2.length();i++)
    {
        if(s2[i]=='*')
        s2.erase(i,1);
    }
    cout<<s2;
    cout<<add();
    int x,y;
    try
    {
        cout<<"Enter 2 numbers>0:";
        cin>>x>>y;
        if(x<0||y<0)
        {
            throw "First quadrant coordinates only";
        }
    }
    catch(const char* msg)
    {
        cout<<msg<<endl;
    }
    return 0;
}
