/*Write a C++ program to read a string input, a key k, 1 <= k <= 25 and then encrypt
that. Verify your program, with the input “Rome is not built in one day”, the output
will be “Urph lv qrw exlow lq rqh gdb” if key is 3.
*/
#include <iostream>
using namespace std;
int main()
{
    char str[50], encrypt[50];
    cout << "Enter a string:";
    cin.getline(str, 50);
    int key = 3;
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (isalpha(str[i]))
        { char base=isupper(str[i])?'A':'a';
            encrypt[i] = (str[i]-base + key)%26+base;
        }else
            encrypt[i] = str[i];
    }
    encrypt[i] = '\0';
    cout << encrypt;
    return 0;
}