/*To create a copy of the cstring header class as myString*/

#include <iostream>
using namespace std;

class myString
{
    char ch[50];

public:
    int strlen()
    {
        int i;
        for (i = 0; ch[i] != '\0'; i++)
            ;
        return i;
    }
    void showstring()
    {
        cout << ch;
    }
    friend myString strcatsmallest(myString, myString);

    void operator=(char str[])
    {
        int i = 0;
        for (i = 0; str[i] != '\0'; i++)
            ch[i] = str[i];
        ch[i] = '\0';
    }
    friend istream &operator>>(istream &input, myString &str);
};

myString strcatsmallest(myString str1, myString str2)
{
    if (str1.strlen() <= str2.strlen())
    {
        int i;
        int len = str1.strlen();
        for (i = 0; i < str2.ch[i] != '\0'; i++)
        {
            str1.ch[len + i] = str2.ch[i];
        }
        str1.ch[len + i] = '\0';

        return str1;
    }
    else
    {
        int i;
        int len = str2.strlen();
        for (i = 0; str1.ch[i] != '\0'; i++)
        {
            str2.ch[len + i] = str1.ch[i];
        }

        str2.ch[len + i] = '\0';
        return str2;
    }
}
istream &operator>>(istream &input, myString &str)
{
    input >> str.ch;
    return input;
}
int main()
{
    myString str, str1, str2, str3;
    cin >> str1;
    str1.showstring();
    // cin>>str2;
    // str3 = strcatsmallest(str1, str2);
    // str3.showstring();
    return 0;
}