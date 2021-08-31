#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>
#include "apple.h"

class Maze{
	private:
    int width;
    int height;
    std::vector<std::string> maze;
    Apple aplle;

	public:
    void addLineInMaze(std::string line);
    void printMaze();
    std::pair<int,int> getSnakePosition();
    std::pair<int,int> getCoordFreeToApple();
    void setHeight(int height);
    void setWidth(int width);
    void configureAplle(int value);
    void newApple();
};

#endif
