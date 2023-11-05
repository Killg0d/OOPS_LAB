// Write a menu driven C++ program to create a single line text file and then
// implement the following:
// a) Convert every lower-case letter to upper case and upper-case letter to lower
// case.
// b) Display the content of the file.
// c) Determine how many times a character ‘a’ is present in the file.
// tarun
// 230270005
// 04/11/2023
#include <iostream>
#include <fstream>


using namespace std;

void createFile(string fileName){
    string fileString;
    ofstream outFile(fileName);//Create file with username
    cout << "Enter some text into the file: ";
    cin.ignore(); // Clear the newline left in the buffer
    getline(cin, fileString);//gets from keyboard stores in string
    outFile << fileString;//writes it to the file
    outFile.close();//close the file so that it will print it into file
}

void convertCase(string fileName) {
    ifstream inFile(fileName);//create a obj pointing to file
    ofstream outFile("temp.txt");//Creates error if same file opened in read and write mode
    char ch;
    cout<<"case conversion ongoing";
    while (inFile.get(ch)) {//get method retrieves one char at a time
        if (islower(ch)) {
            
            ch = toupper(ch);
            cout<<ch;
            outFile<<ch;
        } else if (isupper(ch)) {
            ch = tolower(ch);
            cout<<ch;
            outFile<<ch;
        }
        
    }

    inFile.close();
    outFile.close();
    cout<<fileName.c_str();
    remove(fileName.c_str());
    
    rename("temp.txt", fileName.c_str());
}

void displayContent(string fileName) {
    ifstream inFile(fileName);
    char ch;

    while (inFile.get(ch)) {
        cout << ch;
    }

    inFile.close();
}

int countCharA(string fileName) {
    ifstream inFile(fileName);
    char ch;
    int count = 0;

    while (inFile.get(ch)) {
        if (tolower(ch) == 'a') {
            count++;
        }
    }

    inFile.close();

    return count;
}

int main() {
    int choice;
    string fileName;

    cout << "Enter the file name: ";
    cin >> fileName;
    createFile(fileName);
    do {
        cout << "\nMenu\n";
        cout << "1. Convert case\n";
        cout << "2. Display content\n";
        cout << "3. Count occurrences of 'a'\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                convertCase(fileName);
                cout << "Case conversion done.\n";
                break;
            case 2:
                cout << "\nFile content:\n";
                displayContent(fileName);
                break;
            case 3:
                cout << "\nNumber of 'a' occurrences: " << countCharA(fileName) << endl;
                break;
            case 4:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    return 0;
}
