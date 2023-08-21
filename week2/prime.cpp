//Program to generate prime numbers between range
#include<iostream>
using namespace std;

int main() {
    int a, b, flag, j;
    cout << "Enter the range: ";
    cin >> a >> b;

    if (a == 1)
        a++;

    for (int i = a; i <= b; i++) {
        flag = 0;  // Initialize the flag to 0 for each iteration of i

        if (i == 2) {
            cout << i << " ";
            continue;
        }

        for (j = 2; j <= i / 2; j++) {  // Change condition to i / 2
            if (i % j == 0) {
                flag = 1;
                break;
            }
        }

        if (flag == 0) {
            cout << i << " ";
        }
    }

    return 0;
}
