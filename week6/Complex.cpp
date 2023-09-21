//Write a C++ program to perform addition and subtraction on two complex numbers
//using operator overloading using member functions.
//tarun
//230970005
//18-09-23
#include<iostream>
using namespace std;


class Complex{
        int real,img;
        public:Complex():real(0),img(0){}
        void getData(){
                        cout<<"Enter real part: ";
                        cin>>real;
                        cout<<"Enter imaginary part: ";
                        cin>>img;
                }

                Complex operator+(Complex c2){
                        Complex temp;
                        temp.real=real+c2.real;
                        temp.img=img+c2.img;
                        return temp;
                }
                void operator=(Complex c1){
                        real=c1.real;
                        img=c1.img;
                }
                friend Complex operator-(Complex c1,Complex c2);

                void display(){
                        cout<<real<<" + "<<img<<" i";
                }
};
Complex operator-(Complex c1,Complex c2){
        Complex diff;
        diff.real=c1.real-c2.real;
        diff.img=c1.img-c2.img;
        return diff;}
int main(){
        int choice,num;
        Complex c1,c2,c3,c4;
        system("clear");
        do{
                cout<<"\n\nMENU\n1.Add 2 complex number\n2. Sub 2 complex number\nEnter your choice: ";
                cin>>choice;
                switch(choice){
                        case 1: cout<<"Enter complex number 1\n";
                                c1.getData();
                                cout<<"\nEnter complex number 2\n";
                                c2.getData();
                                c4=c1+c2;
                                cout<<"\nResult : ";
                                c4.display();
                                break;
                        case 2:
                                cout<<"\nEnter complex number1: \n";
                                c1.getData();
                                cout<<"\nEnter complex number2: \n";
                                c2.getData();
                                c4=c1-c2;
                                cout<<"\nResult : ";
                                c4.display();
                                break;
                        case 3:break;
                        default:cout<<"\nInvalid choice\n";
                                continue;
                }
        }while(choice!=3);
        return 0;
}0