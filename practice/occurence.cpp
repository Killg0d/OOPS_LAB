/*given a string change the occurence of l to z
2. change occourence of hello to hi
*/
#include <iostream>
using namespace std;
void replace_l(char ch[])
{
    int i;
    for (i = 0; ch[i] != '\0'; i++)
        if (ch[i] == 'l')
            ch[i] = 'z';
}
void replace_hello(char ch[])
{
    for (int i = 0; ch[i] != '\0'; i++)
        if (ch[i] == 'h' && ch[i + 1] == 'e' && ch[i + 2] == 'l' && ch[i + 3] == 'l' && ch[i + 4] == 'o')
        {
            ch[i + 1] = 'i';

            for (int j = i + 5; ch[j] != '\0'; j++, i++)
                ch[i + 2] = ch[j];
            ch[i + 2] = '\0';
            break;
        }
}
int main()
{
    char ch[50];
    cout << "Enter a string:";
    cin.getline(ch, 50);
    // replace_l(ch);
    //cout << ch;
    replace_hello(ch);
    cout << ch;
    return 0;
}