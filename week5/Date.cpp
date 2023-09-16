#include<iostream>
using namespace std;


class Date{
    int day,month,year;
    public:
    Date():day(1),month(1),year(1){}
        Date(int d,int m,int y){
           day=d;month=m;year=y;
        }
        void operator ++();
        void displayDate(){
            cout<<endl<<day<<"/"<<month<<"/"<<year;
            
        }
        void get_Date();
        bool validate_date();
        bool isLeap(){
            if((year%4==0 && year%100!=0) || (year%400==0))
                return true;
            else 
                return false;
        }
};
void Date::operator++(){
   
    day++;
    if(month<8){
        if(month%2==0)
        {
            if(month==2)
            {   
                if(isLeap()){
                    if(day>=29){
                        month++;
                        day=1;
                    }
                }
                else if(day>=28)
                {
                    month++;
                    day=1;        
                }
            }
            else if(day>=30)
            {
                month++;
                day=1;
            }
        }
        else if(day>=31)
            {
                month++;
                day=1;
            }
    }
    else if (month%2==0)
    { if(day>=30)
        {
            month++;
            day=1;
        }
    }
    else if(day>=31){
        month++;
        day=1;
    }
   
    if(month>12){
        year++;
        month = 1;
    }
    
}


int main() {
    Date dt;
    dt.get_Date();
    ++dt;
    dt.displayDate();
    cout<<endl;
    return 0;
}

void Date::get_Date(){
    do{
        cout << "Enter a valid date: ";
        cin >> day >> month >> year ;
       
    }while(!validate_date());
}
bool Date:: validate_date(){
    if(year<0 || year>3000){
        cout<<"Year out of range."<<endl;
        return false;
    }
    if(month<1||month>12){
        cout<<"Month out of range."<<endl;
        return false;
    }
    int max_month_days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(isLeap())
    {
        max_month_days[2]=29;
    }
    if(max_month_days[month]<day){
        cout<<"Day out of range."<<endl;
        return false;
    }
    return true;
}