#include<iostream>
#include<cstring>
using namespace std;

class DNA{
    //virtual int length() const = 0;
    //virtual void count_nucleotides() const;
};

class Sequence : public DNA {
    char* seq;

public:
    Sequence(const char* s) {
        seq = new char[strlen(s) + 1];
        strcpy(seq, s);
    }

    int length() const  {
        return strlen(seq);
    };

    void count_nucleotides() const 
     {
        int t = 0, c = 0, a = 0, g = 0;
        cout << "Sequence Length is:" << length();
        for (int i = 0; i < length(); ++i) {
            if (seq[i] == 'A') a++;
            else if (seq[i] == 'T') t++;
            else if (seq[i] == 'C') c++;
            else if (seq[i] == 'G') g++;
        }
        cout << "\t Adenine Count:" << a << endl;
        cout << "\t Thymine Count:" << t << endl;
        cout << "\t Cytosine Count:" << c << endl;
        cout << "\t Guanine Count:" << g << endl;
    }

    bool operator==(const Sequence& s) const {
        int n = strlen(seq);
        if (n != strlen(s.seq)) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            if (toupper(seq[i]) != toupper(s.seq[i])) {
                return false;
            }
        }

        return true;
    }

    // Implement a destructor to free the allocated memory
    ~Sequence() {
        delete[] seq;
    }
};

int main() {
    Sequence s1("ATCG ATC FTU"), s2("atcg");
    s1.count_nucleotides();
    if (s1 == s2) {
        cout << "Equal";
    } else {
        cout << "Not equal";
    }

    return 0;
}
