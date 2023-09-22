#include<iostream>
#include<cstring>
using namespace std;
class Solution {
public:
    int romanToInt(string s) {
        int num=0;
        for (int i = 0; i < s.length(); i++) {
        switch (s[i]) {
            case 'M':
                num += 1000;
                break;
            case 'D':
                num += 500;
                break;
            case 'C':
                if (i < s.length() - 1 && (s[i + 1] == 'D' || s[i + 1] == 'M')) {
                    num -= 100; // Subtract 100 for "CM" or "CD" cases
                } else {
                    num += 100;
                }
                break;
            case 'L':
                num += 50;
                break;
            case 'X':
                if (i < s.length() - 1 && (s[i + 1] == 'L' || s[i + 1] == 'C')) {
                    num -= 10; // Subtract 10 for "XC" or "XL" cases
                } else {
                    num += 10;
                }
                break;
            case 'V':
                num += 5;
                break;
            case 'I':
                if (i < s.length() - 1 && (s[i + 1] == 'V' || s[i + 1] == 'X')) {
                    num -= 1; // Subtract 1 for "IV" or "IX" cases
                } else {
                    num += 1;
                }
                break;
        }
    }
       return num;
    }
 
};