#include "maze.h"

void Maze::addLineInMaze(std::string line){
  this->maze.push_back(line);
}

void Maze::printMaze(){
  for(auto line : maze){
    std::cout<<line<<std::endl;
  }
}

std::pair<int,int> Maze::getSnakePosition(){
  for( auto i(0) ; i < this->height; ++i ){
    for( auto j(0); j < this->width ; ++j ){
      if(this->maze[i][j] == '*'){
        return std::make_pair(i, j);
      }
    }
  }

  return std::make_pair(0,0);
}

void Maze::setHeight(int value){
  this->height = value;
}

void Maze::setWidth(int value){
  this->width = value;
}
