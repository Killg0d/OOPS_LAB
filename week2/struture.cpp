//Program to create a structure to represent bank account
#include<iostream>
#include<string>
using namespace std;
struct Bank
{
    string cname;
    int acc_no;
    string acc_type;
    double balance;
};

int main(){
    Bank b;
    int choice_type;
    double amt;
    cout<<"Enter name of the customer: ";cin>>b.cname;
    cout<<"\nEnter Account Number:"; cin>>b.acc_no;
    //Checking if user wants savings or fixed accounts
    while(true){
        cout<<"Choose account type:\n1) Savings\n2) Current\n3) Fixed\nEnter choice:";
        cin>>choice_type;
        switch (choice_type){
            case 1:
                    b.acc_type="Savings";
                    break;
            case 2:b.acc_type="Current";
            break;
            case 3:b.acc_type="Fixed";
            break;
            
            default :cout<<"\nInvalid Choice.\n\n";
            continue;
        }
        break;
    }
    cout<<"Enter the balance:";
    cin>>b.balance;
    cout<<endl;
    while(true){
        cout<<"Choose option:\n1) Deposit\n2) Withdraw\n3) Check Balance\n4) Exit\nEnter choice:";
        cin>>choice_type;
        switch (choice_type){
            case 1:
                    cout<<"Enter amount to deposit:";
                    cin>>amt;
                    b.balance+=amt;
                    cout<<endl;
                    break;
            case 2: cout<<"Enter amount to withdraw:";
                    cin>>amt;
                    if((double)(b.balance-amt)<0 ) {
                        cout << "\nInsufficient funds.\n\n";
                        break;
                    }
                    else{
                        b.balance-=amt;
                        cout<<endl;
                        }
                    break;
            case 3: cout<<"Balance = "<<b.balance<<endl<<endl;
                    break;
            case 4: cout<<"\nThankyou";
                    exit(0);
            default:  
                    cout<<"\nInvalid Choice.\n\n";
                    continue;
        }
        
    }

    return 0;
}