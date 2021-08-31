#include "maze.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>

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

std::pair<int,int> Maze::getCoordFreeToApple(){
  std::vector<std::pair<int, int>> frees;

  for( auto i(0) ; i < this->height; ++i ){
    for( auto j(0); j < this->width ; ++j ){
      if(this->maze[i][j] == ' '){
        frees.push_back(std::make_pair(i, j));
      }
    }
  }

  srand(time(0));

  int range = frees.size() - 0 + 1;
  int num = rand() % range + 0;

  return frees[num];
}

void Maze::setHeight(int value){
  this->height = value;
}

void Maze::setWidth(int value){
  this->width = value;
}

void Maze::configureAplle(int value){
  this->aplle.setTotalAmout(value);
  this->aplle.setCurrentAmount(0);
}

void Maze::newApple(){
  auto coords = getCoordFreeToApple();

  this->aplle.setCoords(std::make_pair(coords.first, coords.second));
  this->maze[coords.first][coords.second] = 'o';
}
