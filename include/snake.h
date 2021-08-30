#ifndef SNAKE_H
#define SNAKE_H
#include <iostream>
#include <vector>

using namespace std;

class Snake{
	private:
    int score;
    int lives;
		vector<pair<int,int>> size;

    int x;
    int y;

	public:
    // Constructor
    Snake();

    // Retorna quantidades de vidas em formato de string
    string get_lives();

    int get_number_lives();

    // Retorna score atual
    int get_score();

    // Remove uma vida
    void remove_life();
};

#endif
