 //Write necessary class and member function definitions for a cricket player object
//tarun
//230970005
//4-09-2023
#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
class Cricket{
        char code[10];
        char name[25];
        int no_of_matches;
        float total_runs;
        int no_of_not_outs;

public: 
        Cricket(){
                get_details();
        }  
        void average(Cricket c[],int n){
                        int total=0;
                        for(int i=0;i<n;i++)
                        {
                                total += c[i].total_runs;
                        }
                        cout<<"Total = "<<(double)total<<endl;
                        cout<<"Average = "<<(double)total/n<<endl;
                }
                void average(Cricket c){
                        cout<<"Average of "<<c.name<<" ="<<(double) c.total_runs/c.no_of_matches;
                }
                void get_details(void){
                        cout<<"\nEnter the player code:";cin>>code;
                        cout<<"\nEnter the player name:";cin>>name;
                        cout<<"\nEnter the no of matches played:";cin>>no_of_matches;
                        cout<<"\nEnter the total runs:";cin>>total_runs;
                        cout<<"\nEnter the no of not outs:";cin>>no_of_not_outs; 
                }
                friend bool sort_totalruns(Cricket&,Cricket&);
                void display(Cricket c[],int n){
                        for(int i=0;i<n;i++)
                        cout<<c[i].code<<"\t"<<c[i].name<<"\t"<<c[i].no_of_matches<<"\t"<<c[i].total_runs<<"\t"<<c[i].no_of_matches<<endl;

                }
};
bool sort_totalruns(Cricket &c1,Cricket &c2){
        return c1.total_runs<c2.total_runs;
}
int main(){
       
        int ch,n,code;
        cout<<"Enter the number of players:";
        cin>>n;
        Cricket players[n];
        while(ch!=4){
                cout<<"\nEnter the choice(1/2/3/4):";
                cin>>ch;
                switch(ch){
                        case 1: players[0].average(players[0]);
                                break;
                                
                        case 2:players[0].average(players,n);
                                break;

                        case 3: sort(players,players+n,sort_totalruns);
                        cout << setw(10) << left << "Player Code" << setw(25) << left << "Player Name" << setw(15) << right << "Matches Played" << setw(10) << "Total Runs" << setw(10) << "Not Outs" << endl;
                                players[0].display(players,n);
                                break;
                }
        }
        cout<<endl;
        return 0;
}