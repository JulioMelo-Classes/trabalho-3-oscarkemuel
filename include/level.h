#ifndef LEVEL_H
#define LEVEL_H

#include "maze.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;
class Level{
	private:
    vector<Maze> levels; //<! Vetor de labirintos
    int currentLevel; //<! Labirinto atual (0 sempre por tratar apenas de 1 nível)

	public:
    /*! Ler todos os mapas do arquivo.
        @param patch string com o caminho do arquivo.
    */
    void readMazes(string patch);

    /*! Adiciona um novo mapa.
        @param map Maze novo mapa a ser adinionado.
    */
    void addMaze(Maze map);

    /*! Retorna a quantidade de mapas.
        @return int com a quantidade de mapas.
    */
    int getNumberOfLevels();

    /*! Retorna o mapa atual.
        @return Maze com o mapa atual.
    */
    Maze getCurrentMaze();
};

#endif
