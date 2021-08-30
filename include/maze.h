#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>

class Maze{
	private:
    int width;
    int height;
    std::vector<std::string> maze;

	public:
    void addLineInMaze(std::string line);
    void printMaze();
    std::pair<int,int> getSnakePosition();
    void setHeight(int height);
    void setWidth(int width);
};

#endif
