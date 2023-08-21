#include<iostream>
using namespace std;

int main() {
    int a = 0, b = 1, num, i, c;
    
    cout << "Enter the upper limit: ";
    cin >> num;
    //invalid input
    if (num <= 0) {
        cout << "Invalid input. Please enter a positive number." << endl;
        return 1;
    }
    
    cout << a;
    if (num > 1) {
        cout << " " << b;

        for (i = 2; i < num; i++) {
            c = a + b;
            cout << " " << c;
            a = b;
            b = c;
        }
    }

    return 0;
}
