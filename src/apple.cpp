#include "apple.h"

using namespace std;

int Apple::getTotalAmout(){
  return this->totalAmount;
}

int Apple::getCurrentAmount(){
  return this->currentAmount;
}

void Apple::setTotalAmout(int amount){
  this->totalAmount = amount;
}

void Apple::setCurrentAmount(int amount){
  this->currentAmount = amount;
}

void Apple::setCoords(pair<int, int> coord){
  this->coords = make_pair(coord.first, coord.second);
}
