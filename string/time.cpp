#include<iostream>
using namespace std;
class Time24;
class Time12
{
    int h,m,s;
    string sess;
    public:
    Time12(){}
    Time12(int h,int m,int s,string sess):h(h),m(m),s(s),sess(sess){}
    int geth()
    {
        return h;
    }
    int getm(){return m;}
    int gets(){return s;}
    string getsess(){return sess;}
    operator Time24()
    {
        if(sess=="am"){
            return Time24(h,m,s);
        }
        else
        {
            return Time24(h+12,m,s);
        }
    }
    void display()
    {
        cout<<"Time is:"<<h<<":"<<m<<":"<<s<<endl;
    }
};
class Time24
{
    int h,m,s;
    public:
    Time24(){}
    Time24(int h,int m,int s):h(h),m(m),s(s){}
    // Time24(Time12 t)
    // {
    //     if(t.getsess()=="am")
    //     {
    //         h=t.geth();
    //         m=t.getm();
    //         s=t.gets();
    //     }
    //     else
    //     {
    //         h=(t.geth())+12;
    //         m=t.getm();
    //         s=t.gets();
    //     }
    // }
    void display()
    {
        cout<<"Time is:"<<h<<":"<<m<<":"<<s<<endl;
    }
};
int main()
{
    Time12 t(10,12,13,"pm");
    Time24 t2;
    t2=t;
    t2.display();
    return 0;
}