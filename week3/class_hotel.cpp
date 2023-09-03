/*Solve using arrays only (may be more than one dimension)
A hotel consists of 5 floors. Each floor has 8 rooms numbered 1 to 8. Accept the
number of people staying in each room on each floor*/
#include <iostream>
using namespace std;

const int floors = 5;
const int rooms_per_floor = 8;
const int values_per_room = 2;

int hotel[floors][rooms_per_floor][values_per_room] = {0};

void displayOccupancy() {
    int totalOccupants = 0;
    int totalAdults = 0;
    int totalChildren = 0;
    int maxOccupancyFloor = 0;
    int minOccupancyFloor = 0;

    for (int floor = 0; floor < floors; ++floor) {
        int floorOccupants = 0;
        int floorAdults = 0;
        int floorChildren = 0;

        for (int room = 0; room < rooms_per_floor; ++room) {
            int adults = hotel[floor][room][0];
            int children = hotel[floor][room][1];
            floorOccupants += adults + children;
            floorAdults += adults;
            floorChildren += children;

            totalOccupants += adults + children;
            totalAdults += adults;
            totalChildren += children;
        }

        if (floorOccupants > hotel[maxOccupancyFloor][0][0]) {
            maxOccupancyFloor = floor;
        }
        if (floorOccupants < hotel[minOccupancyFloor][0][0]) {
            minOccupancyFloor = floor;
        }

        cout << "Floor " << floor + 1 << ": Occupants=" << floorOccupants << ", Adults=" << floorAdults << ", Children=" << floorChildren << endl;
    }

    cout << "\nTotal Number of Occupants = " << totalOccupants << endl;
    cout << "Total Number of Adults = " << totalAdults << endl;
    cout << "Total Number of Children = " << totalChildren << endl;
    cout << "Max. Occupancy is on floor " << maxOccupancyFloor + 1 << endl;
    cout << "Min. Occupancy is on floor " << minOccupancyFloor + 1 << endl;
}

int main() {
    while (true) {
        cout << "\nHotel Management Menu:" << endl;
        cout << "1. Enter occupancy details" << endl;
        cout << "2. Display occupancy statistics" << endl;
        cout << "3. Quit" << endl;
        cout << "Enter your choice (1/2/3): ";
        int choice;
        cin >> choice;

        if (choice == 1) {
            int floor, room, adults, children;
            cout << "Enter floor (1-5): ";
            cin >> floor;
            cout << "Enter room number (1-8): ";
            cin >> room;
            cout << "Enter the number of adults: ";
            cin >> adults;
            cout << "Enter the number of children: ";
            cin >> children;
            hotel[floor - 1][room - 1][0] = adults;
            hotel[floor - 1][room - 1][1] = children;
            cout << "Occupancy details updated." << endl;
        } else if (choice == 2) {
            displayOccupancy();
        } else if (choice == 3) {
            cout << "Goodbye!" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
