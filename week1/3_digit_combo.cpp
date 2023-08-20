//Program to find all combinations of a 3 digit number
#include <algorithm>//Call the next_permutaion function
#include <iostream>
using namespace std;

int main() {
    int num, digit1, digit2, digit3;
    cout << "Enter the three-digit number: ";
    cin >> num;

    if (num < 100 || num > 999) {
        cout << "Please enter a valid three-digit number." << endl;
        return 1; // Exit with an error code
    }
    //Get individual digits
    digit1 = num % 10;
    digit2 = (num / 10) % 10;
    digit3 = (num / 100) % 10;

    int digits[] = {digit3, digit2, digit1};

    cout << "All combinations of the digits are:" << endl;

    sort(digits, digits + 3);
    //Sort is done as as next_permutation requires it to be in lexicographic order in ascending
    do {
        for (int i = 0; i < 3; i++) {
            cout << digits[i];
        }
        cout << endl;
    } while (next_permutation(digits, digits + 3));

    return 0;
}