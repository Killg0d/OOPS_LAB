#include<iostream>
using namespace std;
int main() {
    int a[10][10];
    int n;
    cin>>n;
     for (int line = 0; line < n; line++)
    {
        // Every line has number of integers 
        // equal to line number
        for(int j=0;j<n-line;j++)
        cout<<" ";
        for (int i = 0; i <= line; i++)
        {
        // First and last values in every row are 1
        if (line == i || i == 0)
            a[line][i] = 1;
        // Other values are sum of values just 
        // above and left of above
        else
            a[line][i] = a[line - 1][i - 1] + 
                            a[line - 1][i];
        cout << a[line][i] << " ";
        }
        cout << "\n";
    }

    return 0;
}