#include "snake.h"

using namespace std;

Snake::Snake(){
  this->lives = 5;
  this->score = 0;
  this->x = 1;
  this->y = 1;
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
