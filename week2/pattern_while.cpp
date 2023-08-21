#include <iostream>
using namespace std;

int main() {
    int lines;

    cout << "Enter the number of lines: ";
    cin >> lines;

    // Pattern 1
    cout << "Pattern 1:" << endl;
    int i = lines;
    while (i >= 1) {
        int j = 1;
        while (j <= i) {
            cout << "* ";
            j++;
        }
        cout << endl;
        i--;
    }

    // Pattern 2
    cout << "Pattern 2:" << endl;
    i = lines;
    while (i >= 1) {
        char c = 'A';
        int j = 1;
        while (j <= i) {
            cout << c << " ";
            c++;
            j++;
        }
        cout << endl;
        i--;
    }

    // Pattern 3
    cout << "Pattern 3:" << endl;
    int num = 1;
    i = 1;
    while (i <= lines) {
        int j = 1;
        while (j <= i) {
            cout << num << " ";
            num++;
            j++;
        }
        cout << endl;
        i++;
    }

    return 0;
}
