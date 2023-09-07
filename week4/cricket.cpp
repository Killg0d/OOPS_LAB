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
        int total_runs;
        int no_of_not_outs;
        public:  void average(Cricket c[],int n){
                        int total=0;
                        for(int i=0;i<n;i++)
                        {
                                total += c[i].total_runs;
                        }
                        cout<<"Total = "<<total<<endl;
                        cout<<"Average = "<<total/n<<endl;
                }
                void average(Cricket c){
                        cout<<"Average of "<<c.name<<" ="<< c.total_runs/c.no_of_matches;
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
                        cout<<setw(8)<<left<<code<<setw(6) << left<<name<<setw(10)<<right<<no_of_matches<<total_runs<<no_of_matches;

                }
};
bool sort_totalruns(Cricket &c1,Cricket &c2){
        return c1.total_runs<c2.total_runs;
}
int main(){
        Cricket players[10],p1;
        int ch,n,code;
        cout<<"Enter the number of players:";
                               cin>>n;
                               for(int i=0;i<n;i++)
                                       players[i].get_details();
        while(ch!=4){
                cout<<"\nEnter the choice(1/2/3/4):";
                cin>>ch;
                switch(ch){
                        case 1:p1.average(players[0]);
                                break;
                                
                        case 2:p1.average(players,n);
                                break;

                        case 3: sort(players,players+n,sort_totalruns);
                                p1.display(players,n);
                                break;
                }
        }
        cout<<endl;
        return 0;
}