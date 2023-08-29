/*Write an interactive program in C++ for swapping two integers, floats, and
characters using function-overloading concept. */
#include<iostream>
using namespace std;
int swap(int a, int b){
        int temp=a;
        a=b;
        b=temp;
        cout<<"After swapping i="<<a<<" and j="<<b<<endl;
}

float swap(float a, float b){
        float temp=a;
        a=b;
        b=temp;
         cout<<"After swapping i="<<a<<" and j="<<b<<endl;
}
char swap(char a, char b){
        char temp=a;
        a=b;
        b=temp;
        cout<<"After swapping i="<<a<<" and j="<<b<<endl;
}
int main(){
        int ch;
        //system("clear");
                cout<<"1.Integer\n2.Float\n3.Char\nEnter your choice:";
 cin>>ch;
                switch(ch){
                        case 1: int i,j;
                                cout<<"Enter two integers:";
                                cin>>i>>j;
                                swap(i,j);
                                break;
                        case 2: float a,b;
                                cout<<"Enter two float:";
                                cin>>a>>b;
                                swap(a,b);
                                break;
                        case 3: char x,y;
                                cout<<"Enter two characters:";
                                cin>>x>>y;
                                swap(x,y);
                                break;
                        default: cout<<"Invalid choice\n";
                        break;
                }

        return 0;
}