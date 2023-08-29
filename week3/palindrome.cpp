/*Write a function to determine if the given string is a palindrome or not. Accept
string in the main function and pass that as a parameter to the function (use c-style
strings)*/

#include<iostream>
#include<string.h>
using namespace std;
bool isPalindrome(char str[]){
        int i=0,j;
        j=strlen(str)-1;
        while(i<j){
                if(str[i]!=str[j])
                        return false;
                i++;j--;
        }
        return true;
}
int main()
{
        char str[32];
        //system("clear");
        cout<<"Enter a string:";
        cin>>str;
        if(isPalindrome(str))
                cout<<"String is palindrome"<<endl;
        else
                cout<<"String is not palindrome"<<endl;

        return 0;
}