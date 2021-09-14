#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <vector>

using namespace std;

class Snake{
	private:
    int score; //<! INT com Score da cobra
    int lives; //<! INT com Quantidade de vidas da cobra
		vector<pair<int,int>> body; //<! Vetor com as cordenadas do corpo da cobra
    char head; //<! Char com a cabeça da cobra (<,>,v, A)

    int old_x; //<! Int com o x anterior ocupado pela cobra
    int old_y; //<! Int com o y anterior ocupado pela cobra
    bool snakeIsPacman; //<! Boll que diz se a cobra é pacman ou não

	public:
    // Constructor
    Snake();

    /*! Retorna as vidas em formato de coração "♥"
				@return uma string com a quantidade de vidas da cobra."
		*/
    string get_lives();

    /*! Retorna quantidades de vidas em formato de number
				@return um int com a quantidade de vidas da cobra."
		*/
    int get_number_lives();

    /*! Retorna o score atual.
				@return um int com o score atual.
		*/
    int get_score();

    /*! Atualiza o score atual.
        @param qtd int com a quantidade para ser atualizado.
    */
    void set_score(int qtd);

    /*! Remove uma vida da cobra. */
    void remove_life();

    /*! Atualiza se Pacman ou não.
        @param status bool com a informação se é pacman ou não.
    */
    void setIsPacman(bool status);

    /*! Retorna se é pacman ou não.
				@return um bool com a informação se é pacman ou não.
		*/
    bool isPacman();

    /*! Seta a posição inicial da cobra.
        @param x int com a coordenada x.
        @param y int com a coordenada y.
    */
    void setInitialPosition(int x, int y);

    /*! Seta a posição da cabeça da cobra.
        @param x int com a coordenada x.
        @param y int com a coordenada y.
    */
    void setHeadPosition(int x, int y);

    /*! Retorna o corpo da cobra.
				@return um vector<pair<int, int>> com o corpo da cobra.
		*/
    vector<pair<int, int>> getBody();

    /*! Seta a velha coordenada.
        @param x int com a coordenada x.
        @param y int com a coordenada y.
    */
    void setOldCoord(int x, int y);

    /*! Retorna o corpo da cobra.
				@return um pair<int, int> com a velha coordenada ocupada pela cobra.
		*/
    pair<int, int> getOldCoord();

    /*! Seta o char da cabeça da cobra (<,>,v, A).
        @param cabeca char com a cabeça a ser setada (<,>,v, A).
    */
    void setHead(char cabeca);

    /*! Retorna a cabeça da cobra (onde está olhando).
				@return um char com a cabeça da cobra.
		*/
    char getHead();

    /*! Adiciona um pedaço da cobra no final do corpo.
        @param x int com a coordenada x.
        @param y int com a coordenada y.
    */
    void addBody(int x, int y);

    /*! Move o corpo da cobra (IMCOMPLETO).*/
    void moveBody();
};

#endif
