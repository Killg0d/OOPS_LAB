#include<iostream>
#include<algorithm>
#include<iomanip>
#include<cstring>
using namespace std;

class Cricket {
    char code[10];
    char name[25];
    int no_of_matches;
    int total_runs;
    int no_of_not_outs;

public:
    Cricket() {
        // Default constructor
    }

    Cricket(char _code[], char _name[], int _no_of_matches, int _total_runs, int _no_of_not_outs) {
        strcpy(code, _code);
        strcpy(name, _name);
        no_of_matches = _no_of_matches;
        total_runs = _total_runs;
        no_of_not_outs = _no_of_not_outs;
    }

    void average() {
        cout << "Average of " << name << " = " << static_cast<double>(total_runs) / no_of_matches << endl;
    }

    static double average(Cricket players[], int n) {
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += players[i].total_runs;
        }
        return static_cast<double>(total) / n;
    }

    friend bool sort_totalruns(Cricket&, Cricket&);

    void display() {
        cout << setw(10) << left << code << setw(25) << left << name << setw(15) << right << no_of_matches << setw(10) << total_runs << setw(10) << no_of_not_outs << endl;
    }

    void get_details() {
        cout << "\nEnter the player code: ";
        cin >> code;
        cout << "Enter the player name: ";
        cin.ignore();
        cin.getline(name, sizeof(name));
        cout << "Enter the no of matches played: ";
        cin >> no_of_matches;
        cout << "Enter the total runs: ";
        cin >> total_runs;
        cout << "Enter the no of not outs: ";
        cin >> no_of_not_outs;
    }
};

bool sort_totalruns(Cricket &c1, Cricket &c2) {
    return c1.total_runs > c2.total_runs; // Sorting in descending order
}

int main() {
    Cricket players[10];
    int ch, n;

    cout << "Enter the number of players (up to 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter details for Player " << i + 1 << ":" << endl;
        players[i].get_details();
    }

    while (ch != 4) {
        cout << "\nMenu:" << endl;
        cout << "1. Display average runs of a single player" << endl;
        cout << "2. Display average runs of all players" << endl;
        cout << "3. Display the list of players in sorted order by total runs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1/2/3/4): ";
        cin >> ch;

        switch (ch) {
            case 1:
                int playerIndex;
                cout << "Enter the player index (0-" << n - 1 << "): ";
                cin >> playerIndex;
                if (playerIndex >= 0 && playerIndex < n) {
                    players[playerIndex].average();
                } else {
                    cout << "Invalid player index." << endl;
                }
                break;

            case 2:
                cout << "Average runs of all players = " << Cricket::average(players, n) << endl;
                break;

            case 3:
                sort(players, players + n, sort_totalruns);
                cout << setw(10) << left << "Player Code" << setw(25) << left << "Player Name" << setw(15) << right << "Matches Played" << setw(10) << "Total Runs" << setw(10) << "Not Outs" << endl;
                for (int i = 0; i < n; i++) {
                    players[i].display();
                }
                break;

            case 4:
                cout << "Exiting the program." << endl;
                break;

            default:
                cout << "Invalid choice. Please enter a valid choice (1/2/3/4)." << endl;
        }
    }

    return 0;
}
