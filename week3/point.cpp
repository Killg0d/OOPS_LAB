#include <iostream>
#include <cmath>
using namespace std;

const int MAX_POINTS = 100; 

double distance(double point1[], double point2[]) {
    return sqrt((point1[0] - point2[0]) * (point1[0] - point2[0]) + (point1[1] - point2[1]) * (point1[1] - point2[1]));
}

int findNearestPoint(double points[][2], int n, double target[2]) {
    double minDist = distance(points[0], target);
    int nearestPointIndex = 0;

    for (int i = 1; i < n; ++i) {
        double dist = distance(points[i], target);
        if (dist < minDist) {
            minDist = dist;
            nearestPointIndex = i;
        }
    }

    return nearestPointIndex;
}

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    if (n <= 0 || n > MAX_POINTS) {
        cout << "Invalid number of points. Must be between 1 and " << MAX_POINTS << endl;
        return 1;  // Exit with an error code
    }

    double points[MAX_POINTS][2];

    for (int i = 0; i < n; ++i) {
        cout << "Enter coordinates of point " << i + 1 << " (x y): ";
        cin >> points[i][0] >> points[i][1];
    }

    double target[2];
    cout << "Enter the coordinates of the target point (x y): ";
    cin >> target[0] >> target[1];

    int nearestIndex = findNearestPoint(points, n, target);
    double nearestPoint[2] = {points[nearestIndex][0], points[nearestIndex][1]};

    cout << "The nearest point to (" << target[0] << ", " << target[1] << ") is (" << nearestPoint[0] << ", " << nearestPoint[1] << ")" << endl;

    return 0;
}
