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
}

void Maze::setFirstSnakePosition(Snake &snake){
  std::pair<int, int> snaze = getSnakePosition();

  // this->maze[snaze.first][snaze.second] = 'o';
  snake.setInitialPosition(snaze.first, snaze.second);
}

int Maze::getHeight(){
  return this->height;
}

int Maze::getWidth(){
  return this->width;
}

void Maze::printSnake(vector<pair<int, int>> body, char head){
  for (size_t i = 0; i < body.size(); i++){
    auto element = body[i];

    if(i == 0){
      maze[element.first][element.second] = head;
    }else {
      maze[element.first][element.second] = '-';
    }
  }
}

void Maze::printApple(pair<int, int> coord){
  maze[coord.first][coord.second] = 'o';
}

char Maze::getValue(int x, int y){
  char charact = maze[x][y];
  return charact;
}

void Maze::clearValue(int x, int y){
  if(x && y){
    maze[x][y] = ' ';
  }
}
