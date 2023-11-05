// Write a C++ program to create a multiline text file and then determine the
// following: Total number of characters, letters of the alphabet, digits, lines and
// spaces. 
//tarun
//04-11-23
//230970005
#include <iostream>
#include <fstream>

using namespace std;

void createFile(string fileName){
    string fileString;
    ofstream outFile(fileName);//Create file with username
    cout << "Enter some text into the file: ";
    cin.ignore(); // Clear the newline left in the buffer
    getline(cin, fileString,'q');//gets from keyboard stores in string q is defined as end.
    outFile << fileString;//writes it to the file
    outFile.close();//close the file so that it will print it into file
}
void displayContent(string fileName) {
    ifstream inFile(fileName);
    char ch;

    while (inFile.get(ch)) {
        cout << ch;
    }

    inFile.close();
}
void countChars(string fileName){
    ifstream inFile(fileName);
    char ch;
    int chars = 0,digits=0,space=0,line=0,symb=0;

    while (inFile.get(ch)) {
        if(isalpha(ch)){
            chars++;
        }
        else if(isdigit(ch)){
            digits++;
        }
        else if(ch=='\n'){
            line++;
        }
        else if(isspace(ch)){
            space++;
        }
        else
            symb++;
    }
    cout << "Character count: " << chars << endl;
    cout << "Digit count: " << digits << endl;
    cout << "Line count: " << line << endl;
    cout << "Space count: " << space << endl;
    cout << "Symbol count: " << symb << endl;

    inFile.close();
}
int main(){
int choice;
    string fileName;

    cout << "Enter the file name: ";
    cin >> fileName;
    createFile(fileName);
    do {
        cout << "\nMenu\n";
        cout << "1. Count type of char\n";
        cout << "2. Display content\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:cout << "\nCount Chars:\n";
                countChars(fileName);
                break;
            case 2:
                cout << "\nFile content:\n";
                displayContent(fileName);
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
