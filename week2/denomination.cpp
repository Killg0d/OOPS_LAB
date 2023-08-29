#include <iostream>
using namespace std;

int main()
{
    
    int coins[] = { 500, 200, 100, 50, 20, 10, 5, 2, 1 };
    // cout<<sizeof(coins)<<" "<<sizeof(coins[0])<<endl;//Calculating size by total bytes by byte of integer
    int n = sizeof(coins)/sizeof(coins[0]);
    int bill;
    cout<<"Enter the total bill:";
    cin>>bill;
    int paid;
    cout<<"Enter the amount paid:";
    cin>>paid;
    if(paid<bill){
        cout<<"Paid is less than bill";
        return 1;
    }
    int total=paid-bill;
    cout << "The minimum number of coins required to get the change for " << total << " is: ";

    // Go through all denomination starting from the highest
    for (int i = 0; i < n; i++)
    {
        while (total >= coins[i])// Will work till value gets lower than denomiation
        {
            total -= coins[i];
            cout << coins[i] << " ";
        }
    }

    return 0;
}
