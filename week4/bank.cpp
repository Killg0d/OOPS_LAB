//Create a Bank class that has data members and member functions
//tarun
//230970005
//4-09-2023
#include<iostream>
#include<cstring>
using namespace std;
class Bank{
        char name[25];
        int acc_no;
        char type[10];
        float bal;

        public: Bank(){
                        bal=500;
                }
                void get_data(void){
                        cout<<"\nEnter the customer name:";cin>>name;
                        cout<<"\nEnter the account number:";cin>>acc_no;
                        while(true){
                                cout<<"\nEnter the type Saving(S) Fixed(F) Current(C):";
                                char ch;
                                cin>>ch;
                                switch(ch){
                                        case 'S':strcpy(type,"Savings");
                                                 break;
                                        case 'F':strcpy(type,"Fixed");
                                                break;
                                        case 'C':strcpy(type,"Current");
   break;
                                        default:cout<<"Invalid Choice\n";
                                                continue;
                                }
                                break;
                        }
                }
                void deposit(void){
                        float amt;
                        cout<<"\nEnter the amount to be deposited:";
                        cin>>amt;
                        bal+=amt;
                }
                friend void withdraw(Bank &);
                void display(void){
                cout<<"\nAccount no:"<<acc_no;
                cout<<"\nName:"<<name;
                cout<<"\nType:"<<type;
                cout<<"\nBal:"<<bal;cout<<endl;
                }

};
void withdraw(Bank &b){
        float amt;
        cout<<"Enter the amount to be withdrawn:";
        cin>>amt;
        if(b.bal-amt>500){
                b.bal-=amt;
        }
 else
                cout<<"\nBalance cannot be less than 500\n";
}

int main(){
        Bank b1,b2;
        b1.get_data();
        b1.deposit();
        withdraw(b1);
        b1.display();
        b2.get_data();
        b2.deposit();
        withdraw(b2);
        b2.display();
}
