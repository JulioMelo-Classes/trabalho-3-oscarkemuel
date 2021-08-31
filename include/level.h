#ifndef LEVEL_H
#define LEVEL_H

#include "maze.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
class Level{
	private:
    vector<Maze> levels;
    int currentLevel;

	public:
    void readMazes(string patch);
    void addMaze(Maze map);
    int getNumberOfLevels();

    Maze getCurrentMaze();
};

#endif
