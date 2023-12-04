#include <iostream>
#include <cmath>
#include <cstdlib>
#include <SFML/Graphics.hpp>

const int WINDOW_SIZE = 800;
const int POINT_SIZE = 2;

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Approximating Pi");
    window.setFramerateLimit(60);

    sf::CircleShape point(POINT_SIZE);
    point.setFillColor(sf::Color::Red);

    int insideCircle = 0;
    int totalPoints = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Generate a random point in the unit square
        float x = static_cast<float>(std::rand()) / RAND_MAX;
        float y = static_cast<float>(std::rand()) / RAND_MAX;

        // Check if the point is inside the unit circle
        if (std::hypot(x, y) <= 1.0) {
            point.setFillColor(sf::Color::Green);
            insideCircle++;
        } else {
            point.setFillColor(sf::Color::Red);
        }

        // Update total points
        totalPoints++;

        // Draw the point
        point.setPosition(x * WINDOW_SIZE, y * WINDOW_SIZE);
        window.draw(point);

        // Update the window
        window.display();

        // Calculate the current approximation of pi
        double piApproximation = 4.0 * static_cast<double>(insideCircle) / totalPoints;

        // Print the current approximation of pi
        std::cout << "Approximation of Pi: " << piApproximation << std::endl;
    }

    return 0;
}
