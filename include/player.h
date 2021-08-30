#ifndef PLAYER_H
#define PLAYER_H

using Sequence = vector<pair<int,int>>;
class Player{
	private:
    Sequence sequence;

	public:
    enum Movimento{
      NORTH,
      SOUTH,
      EAST ,
      WEST
    };

  bool find_solution();
};

#endif
