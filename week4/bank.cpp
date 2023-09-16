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
                        get_data();
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
                        do{
                                
                                cout<<"\nEnter the amount to be deposited:";
                                cin>>amt;
                                if(amt<0){
                                        cout<<"Amount must be greater than 0"<<endl;
                                }
                                else{
                                        break;
                                }
                        }while(true);
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
        int ch1,accno;
        
        while (ch1!=4)
        {
                cout << "\nOptions:\n1. Deposit\n2. Withdraw\n3. Display Account Details\n4. Exit\n";
                cout << "Enter your choice: ";
                cin>>ch1;
                switch(ch1){
                        case 1: cout<<"Enter account to  deposit(1 or 2)";
                                cin>>accno;
                                if (accno == 1)
                                        b1.deposit();
                                else if (accno == 2)
                                        b2.deposit();
                                else
                                        cout << "Invalid account choice.\n";
                                break;
                        case 2:         
                                cout << "Choose an account (1 or 2): ";
                                cin >> accno;
                                if (accno == 1)
                                        withdraw(b1);
                                else if (accno == 2)
                                        withdraw(b2);
                                else
                                        cout << "Invalid account choice.\n";
                                break;
                        case 3:
                                cout << "Account Details:\n";
                                cout << "Account 1:\n";
                                b1.display();
                                cout << "\nAccount 2:\n";
                                b2.display();
                                break;
                        case 4: cout<<"\nExiting Program"<<endl;
                                return 0;
                        default: cout<<"\nInvalid choice\n";
                }
        }
        return 0;
}
