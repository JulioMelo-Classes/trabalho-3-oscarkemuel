#ifndef APPLE_H
#define APPLE_H
#include <iostream>

using namespace std;

class Apple{
	private:
    int totalAmount; //<! Quantidade limite de comidas
    int currentAmount; //<! Quantidade atual de comidas
		pair<int,int> coords; //<! Coordenadas da comida (maçã)

	public:
    /*! Retorna a quantidade geral de maçãs a serem comidas.
      @return int com a quantidade de maçãs.
    */
    int getTotalAmout();

    /*! Retorna a quantidade de maçãs que já foram comidas.
      @return int com a quantidade de maçãs.
    */
    int getCurrentAmount();

    /*! Seta a quantidade total de maçãs a serem comidas.
        @param amount int com a quantidade.
    */
    void setTotalAmout(int amount);

    /*! Seta a quantidade total de maçãs que ja foram comdias.
        @param amount int com a quantidade.
    */
    void setCurrentAmount(int amount);

    /*! Seta as coordenadas da maçã.
        @param coord pair<int, int> com as coordenadas.
    */
    void setCoords(pair<int, int> coord);

    /*! Retorna as coordenadas da maçã.
      @return pair<int, int> com a coordenada atual da maçã.
    */
    pair<int, int> getCoodsApple();
};

#endif
