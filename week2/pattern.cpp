#include <iostream>
using namespace std;

int main() {
    int lines;

    cout << "Enter the number of lines: ";
    cin >> lines;

    // Pattern 1
    cout << "Pattern 1:" << endl;
    for (int i = lines; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }

    // Pattern 2
    cout << "Pattern 2:" << endl;
    for (int i = lines; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << char(65 + j - 1) << " ";
        }
        cout << endl;
    }

    // Pattern 3
    cout << "Pattern 3:" << endl;
    int num = 1;
    for (int i = 1; i <= lines; i++) {
        for (int j = 1; j <= i; j++) {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }

    return 0;
}
