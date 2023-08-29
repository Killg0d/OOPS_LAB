#include <iostream>
using namespace std;

int main()
{
   int n;
    cout << "Enter the n numbers:";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int j,a[32],count=0;
        int decimal=i;
        
                for (j = 0; decimal > 0; j++)
                {
                    a[j] = decimal % 2;
                    if(decimal%2==1)
                    count++;
                    decimal /= 2;
                }
        if(count%2==0)
        {
            for (j = j - 1; j >= 0; j--)
            {
            
                cout << a[j];
            }
            cout << endl;
        }

       
    }
    return 0;
}
