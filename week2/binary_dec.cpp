#include <iostream>
using namespace std;
int main()
{

    int binary, decimal = 0;
    cout << "Enter a binary number:";
    cin >> binary;
    int temp = binary, base = 1, last_digit;
    while (temp)
    {
        if (temp % 10 != 1 && temp % 10 != 0)
        {
            cout << "Enter a valid binary number" << endl;
            return 0;
        }
        last_digit = temp % 10;
        temp /= 10;
        decimal += last_digit * base;
        base *= 2;
    }
    cout << binary << "=" << decimal;

    return 0;
}