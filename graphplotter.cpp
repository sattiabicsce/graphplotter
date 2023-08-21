#include <iostream>

const int MAX_SIZE = 10; // Maximum number of coordinates

struct Point {
    int x;
    int y;
};

void plotCoordinates(const Point coordinates[], int numCoordinates, int maxX, int maxY, int scaleX, int scaleY) {
    char graph[maxY * scaleY][maxX * scaleX];

    // Initialize graph with empty spaces
    for (int i = 0; i < maxY * scaleY; ++i) {
        for (int j = 0; j < maxX * scaleX; ++j) {
            graph[i][j] = ' ';
        }
    }

    // Plots using arrays
    for (int i = 0; i < numCoordinates; ++i) {
        int x = coordinates[i].x;
        int y = coordinates[i].y;

        if (x >= 0 && x < maxX && y >= 0 && y < maxY) {
            int plotX = x * scaleX;
            int plotY = (maxY - y - 1) * scaleY;

            for (int dx = 0; dx < scaleX; ++dx) {
                for (int dy = 0; dy < scaleY; ++dy) {
                    graph[plotY + dy][plotX + dx] = '*';
                }
            }
        }
    }

    // Displays the graph
    std::cout << "Graph:" << std::endl;
    for (int i = 0; i < maxY * scaleY; ++i) {
        for (int j = 0; j < maxX * scaleX; ++j) {
            std::cout << graph[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    Point coordinates[MAX_SIZE];
    int numCoordinates;
    int maxX, maxY;
    int scaleX, scaleY;

    // Gathering info
    std::cout << "Enter the number of coordinates (up to " << MAX_SIZE << "): ";
    std::cin >> numCoordinates;

    std::cout << "Enter the maximum X value: ";
    std::cin >> maxX;

    std::cout << "Enter the maximum Y value: ";
    std::cin >> maxY;

    std::cout << "Enter the scale for the X-axis: ";
    std::cin >> scaleX;

    std::cout << "Enter the scale for the Y-axis: ";
    std::cin >> scaleY;

    std::cout << "Enter the coordinates in the format (x y):" << std::endl;
    for (int i = 0; i < numCoordinates; ++i) {
        std::cout << "Coordinate " << (i + 1) << ": ";
        std::cin >> coordinates[i].x >> coordinates[i].y;
    }

    // Plots the coordinates
    plotCoordinates(coordinates, numCoordinates, maxX, maxY, scaleX, scaleY);

    return 0;
}