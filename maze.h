#ifndef MAZE_H
#define MAZE_H

#include <string>
#include <vector>

enum class Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST
};

class Maze {
private:
    int width;
    int height;
    std::vector<std::vector<int>> grid; // 0: empty, 1: wall
    int robotX;
    int robotY;
    Direction robotDir;

public:
    Maze();
    void initMaze(const std::string &filename);
    bool moveRobot(Direction dir);
    bool checkExit();
    // Other methods as needed
};

#endif // MAZE_H
