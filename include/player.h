#ifndef PLAYER_H
#define PLAYER_H
#include "snake.h"
#include "maze.h"

using namespace std;

using Sequence = vector<pair<int,int>>;
class Player{
	private:

	public:
    /*! Decide como mover a cobra.
      @param snake Snake com a cobra usada no jogo.
      @param maze Maze com o mapa atual.
      @return retorna true se comeu a maçã, se não, retorna false.
    */
    bool next_move(Snake &snake, Maze &maze);
};

#endif
