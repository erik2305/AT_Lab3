#include "maze.h"
#include <fstream>
#include <iostream>

Maze::Maze() : width(0), height(0), robotX(0), robotY(0), robotDir(Direction::NORTH) {}

void Maze::initMaze(const std::string &filename) {
    // Read the maze configuration from the file
    // For simplicity, initialize with hardcoded values
    width = 10;
    height = 10;
    grid.resize(height, std::vector<int>(width, 0)); // Empty grid
    robotX = 1;
    robotY = 1;
    robotDir = Direction::NORTH;
    // Set walls and exits as needed
}

bool Maze::moveRobot(Direction dir) {
    int newX = robotX;
    int newY = robotY;
    switch (dir) {
        case Direction::NORTH: newY--; break;
        case Direction::EAST: newX++; break;
        case Direction::SOUTH: newY++; break;
        case Direction::WEST: newX--; break;
    }
    if (newX >= 0 && newX < width && newY >= 0 && newY < height && grid[newY][newX] == 0) {
        robotX = newX;
        robotY = newY;
        robotDir = dir;
        return true;
    }
    return false;
}

bool Maze::checkExit() {
    // Check if robot is at an exit position
    // For simplicity, assume exit is at (5, 9)
    return (robotX == 5 && robotY == 9);
}
