#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <string>
#include "apple.h"
#include "snake.h"

class Maze{
	private:
    int width; //<! INT com Largura do mapa
    int height; //<! INT com Altura do mapa
    std::vector<std::string> maze; //<! Vetor de strings com as caracteristicas do mapa

	public:
    Apple aplle; //<! Maçã do mapa

    /*! Adiciona uma nova linha no maze.
        @param line string a ser adiciona no maze.
    */
    void addLineInMaze(string line);

    /*! Atualiza a largura do mapa.
        @param width int com a largura do mapa.
    */
    void setWidth(int width);

    /*! Retorna a largura do mapa.
				@return um int com a largura do mapa.
		*/
    int getWidth();

    /*! Atualiza a altura do mapa.
        @param height int com a altura do mapa.
    */
    void setHeight(int height);

    /*! Retorna a altura do mapa.
				@return um int com a altura do mapa.
		*/
    int getHeight();

    /*! Printa o mapa no terminal.*/
    void printMaze();

    /*! Escreve a cobra no mapa.
        @param body vector<pair<int, int>> com as cordenadas do corpo da cobra.
        @param head char com a cabeça da cobra.
    */
    void printSnake(vector<pair<int, int>> body, char head);

    /*! Escreve a cobra no mapa.
        @param coord pair<int, int> com as cordenadas da maçã.
    */
    void printApple(pair<int, int> coord);

    /*! Retorna a posição inicial da cobra (*).
				@return um pair<int,int> com as coordenadas iniciais da cobra.
		*/
    pair<int,int> getSnakePosition();

    /*! Retorna uma posição aleatória para colocar a comida.
				@return um pair<int,int> com as coordenadas para colocar a comida.
		*/
    pair<int,int> getCoordFreeToApple();

    /*! Seta os valores iniciais da maçã (total e current).
        @param value int com o valor a ser setado.
    */
    void configureAplle(int value);

    /*! Seta uma nova maçã no mapa.*/
    void newApple();

    /*! Seta a primeira posição da cobra.
        @param snake Snake com a cobra do programa.
    */
    void setFirstSnakePosition(Snake &snake);

    /*! Retorna o valor da coordenada no mapa.
				@return um char com o valor da coordenada.
        @param x int com a coordenada x.
        @param y int com a coordenada y.
		*/
    char getValue(int x,int y);

    /*! Limpa um valor no mapa de acordo com a coordenada.
        @param x int com a coordenada x.
        @param y int com a coordenada y.
		*/
    void clearValue(int x, int y);
};

#endif
