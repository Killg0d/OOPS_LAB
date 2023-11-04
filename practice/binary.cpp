#include <iostream>
#include <string>
using namespace std;

int main() {
    int N = 2097151;  // The upper limit for the unknown integer
    int x = 1;        // The initial guess

    for (int i = 0; i < 21; ++i) {
        cout << x << endl;  // Output the guess as a question
        string response;
        cin >> response;    // Get the response from the opponent

        if (response == "Yes") {
            cout << "Congratulations! The unknown integer is " << x << endl;
            break;
        } else if (response == "<") {
            x = (x + N) / 2;  // Adjust the guess for x < y
        } else if (response == ">") {
            N = x - 1;        // Adjust the range for x > y
            x = (x - 1) / 2;   // Adjust the guess
        }
    }

    return 0;
}




