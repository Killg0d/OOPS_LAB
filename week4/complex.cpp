//program to create a class called complex anb implement the following
//by overloading funbctions that return the complex number
//tarun
//230970005
//8-9-23

#include<iostream>
using namespace std;


class Complex{
        int real,img;
        public: void getData(){
                        cout<<"Enter real part: ";
                        cin>>real;
                        cout<<"Enter imaginary part: ";
                        cin>>img;
                }

                Complex add(Complex c1,Complex c2){
                        Complex temp;
                        temp.real=c1.real+c2.real;
                        temp.img=c1.img+c2.img;
                        return temp;
                }

                Complex add(int num1,Complex c2){
                        Complex temp;
                        temp.real=num1+c2.real;
                        temp.img=c2.img;
                        return temp;

                }

                void display(){
                        cout<<real<<" + "<<img<<" i";
                }
};

int main(){  int choice,num;
        Complex c1,c2,c3,c4;
        system("clear");
        do{
                cout<<"\n\nMENU\n1.Add 2 complex number\n2. Add integer with complex number\nEnter your choice: ";
                cin>>choice;
                switch(choice){
                        case 1: cout<<"Enter complex number 1\n";
                                c1.getData();
                                cout<<"\nEnter complex number 2\n";
                                c2.getData();
                                c4=c3.add(c1,c2);
                                cout<<"\nResult : ";
                                c4.display();
                                break;
                        case 2:
                                cout<<"\nEnter integer number: ";
                                cin>>num;
                                cout<<"\nEnter complex number: ";
                                c1.getData();
                                c4=c3.add(num,c1);
                                cout<<"\nResult : ";
                                c4.display();
                                break;
                        case 3:break;
                        default:cout<<"\nInvalid choice\n";
                                continue;
                }
        }while(choice!=3);
        return 0;
}