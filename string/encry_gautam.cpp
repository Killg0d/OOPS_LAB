#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include <iomanip>
using namespace std;

class File{
    char *content;
    int key;
    public: void getData(){
        cout<<"Enter file data: ";
        cin.getline(content,1000,'$');
        cout<<"Enter encryption key: ";
        cin>>key;
        ofstream out("dataFile.txt");
        out<<content;
    }
    void encrypt(){
        char c;
        ifstream in("dataFile.txt");
        ofstream out("encrypt.txt",ios::app);
        if(in.is_open()){
            while(in.get(c)){
                if(c==' ')
                    out.put('$');
                else
                    out.put(c+key);
            }
            cout<<"\nEncrypted successfully";
        }
    }
    void decrypt(){
        char c;
        ofstream out("decrypt.txt",ios::app);
        ifstream in("encrypt.txt");
        if(in.is_open()){
            while(in.get(c)){
                if(c=='$')
                    out.put(' ');
                else
                    out.put(c-key);
            }
            cout<<"\nDecrypted successfully";
        }
    }
    void display(char *name){
        char c;
        ifstream in(name);
        if(in.is_open()){
            while(in.get(c)){
                cout<<c;
            }
        }
    }
};


int main(){
    File f;
    f.getData();
    f.encrypt();
    f.decrypt();
    cout<<"\nEncryption: ";
    f.display("encrypt.txt");
    cout<<"\nDecryption: ";
    f.display("decrypt.txt");
    return 0;
}