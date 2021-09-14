#include "snake.h"
#include "maze.h"

using namespace std;

Snake::Snake(){
  this->lives = 5;
  this->score = 0;
  this->old_x = 0;
  this->old_y = 0;
  this->head = 'v';
}

string Snake::get_lives(){
  string aux;
  for (int i = 0; i < this->lives; i++){
    aux += "♥";
  }
  return aux;
}

int Snake::get_number_lives(){
  return this->lives;
}

int Snake::get_score(){
  return this->score;
}

void Snake::remove_life(){
  this->lives--;
}

void Snake::setIsPacman(bool status){
  this->snakeIsPacman = status;
}

bool Snake::isPacman(){
  return this->snakeIsPacman;
}

void Snake::setInitialPosition(int x, int y){
  this->body.push_back(make_pair(x, y));
}

void Snake::setHeadPosition(int x, int y){
  body[0] = make_pair(x, y);
}

vector<pair<int, int>> Snake::getBody(){
  return this->body;
}

void Snake::setOldCoord(int x, int y){
  this->old_x = x;
  this->old_y = y;
}

pair<int, int> Snake::getOldCoord(){
  return make_pair(old_x, old_y);
}

void Snake::setHead(char cabeca){
  this->head = cabeca;
}

char Snake::getHead(){
  return head;
}

void Snake::addBody(int x, int y){
  body.push_back(make_pair(x, y));
}

void Snake::set_score(int qtd){
  this->score = qtd;
}

void Snake::moveBody(){
  body[1].first = old_x;
  body[1].second = old_y;
}
