//Create a flight class that has private data members and public member functions
//tarun
//230970005
//4-09-2023
#include<iostream>
using namespace std;
class flight{
        int flight_no;
        char destination[20];
        float distance,fuel;

        void calculate_fuel(void);
        public: flight(){
                distance=500;
                }
                void information_entry(void);
                void display_info(void);
};
void flight :: information_entry(void){
        cout<<"Enter the flight number:";cin>>flight_no;
        cout<<"Enter the destination:";cin>>destination;
        cout<<"Enter the distance:";cin>>distance;
        calculate_fuel();
}
void flight :: display_info(void){
        cout<<"\nFlight number:"<<flight_no;
        cout<<"\nDestination:"<<destination;
        cout<<"\nDistance:"<<distance;
        cout<<"\nFuel used:"<<fuel;
  cout<<endl;
}
void flight :: calculate_fuel(void){
        if(distance<=1000)
                fuel=500;
        else if(distance<=2000)
                fuel=1100;
        else if(distance>2000)
                fuel=2200;
}
int main(){
        flight f;
        f.information_entry();
        f.display_info();
        cout<<endl;
        return 0;
}
