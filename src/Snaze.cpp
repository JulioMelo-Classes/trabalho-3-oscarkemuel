#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

#include "SnakeGame.h"
#include "level.h"
#include "player.h"
#include "snake.h"

using namespace std;

int main(int argc, char *argv[]){
  string path = "../data/";
  path += argv[1];
  string type = argv[2];

  SnakeGame game(path, type);

  game.loop(); //bloqueia aqui e só saí quando o jogo termina

  return 0;
}
