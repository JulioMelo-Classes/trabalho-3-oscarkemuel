#include "SnakeGame.h"
#include <fstream>
#include <iostream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep
#include <string>
#include <vector>

using namespace std;

vector<string> split(string str, char delimiter = ' '){
    vector<string> ret;

    int start = 0;

    for(int i = 0; i < str.length(); ++i) {
        if(str[i] == delimiter) {
            ret.push_back(str.substr(start, i-start));
            start = i+1;
        }
    }

    ret.push_back(str.substr(start, start - str.length()));

    return ret;
}

SnakeGame::SnakeGame(string data){
    choice = "";
    frameCount = 0;
    initialize_game(data);
}

void SnakeGame::initialize_game(string data){

  //carrega o nivel ou os níveis
  ifstream levelFile(data); //só dá certo se o jogo for executado dentro da raíz do diretório (vc vai resolver esse problema pegando o arquivo da linha de comando)
  int lineCount = 0;
  string line;
  if(levelFile.is_open()){
      while(getline(levelFile, line)){ //pega cada linha do arquivo

          if (lineCount == 0){ // Definindo quantidade de maçãs
            vector<string> values = split(line);

            maze.setHeight(stoi(values[0]));
            maze.setWidth(stoi(values[1]));

            apple.setCurrentAmount(0);
            apple.setTotalAmout(stoi(values[2]));
          }

          if(lineCount > 0){ //ignora a primeira linha já que ela contem informações que não são uteis para esse exemplo
            maze.addLineInMaze(line);
          }
          lineCount++;
      }
  }


  state = RUNNING;
}

void SnakeGame::process_actions(){
    //processa as entradas do jogador de acordo com o estado do jogo
    //nesse exemplo o jogo tem 3 estados, WAITING_USER, RUNNING e GAME_OVER.
    //no caso deste trabalho temos 2 tipos de entrada, uma que vem da classe Player, como resultado do processamento da IA
    //outra vem do próprio usuário na forma de uma entrada do teclado.
    switch(state){
        case WAITING_USER: //o jogo bloqueia aqui esperando o usuário digitar a escolha dele
            cin>>std::ws>>choice;
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

void SnakeGame::update(){
    //atualiza o estado do jogo de acordo com o resultado da chamada de "process_input"
    switch(state){
        case RUNNING:
            if(frameCount>0 && frameCount%10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
                state = WAITING_USER;
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                state = GAME_OVER;
                game_over();
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                state = RUNNING;
            }
            break;
        default:
            //nada pra fazer aqui
            break;
    }
}

/**
 * @brief função auxiliar para fazer o programa esperar por alguns milisegundos
 * @param ms a quantidade de segundos que o programa deve esperar
 */
void wait(int ms){
    this_thread::sleep_for(chrono::milliseconds(ms));
}

/**
 * @brief função auxiliar para limpar o terminal
 */
void clearScreen(){
  //some C++ voodoo here ;D
  #if defined _WIN32
      system("cls");
  #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
      system("clear");
  #elif defined (__APPLE__)
      system("clear");
  #endif
}

void SnakeGame::render(){
    clearScreen();

    cout << maze.getSnakePosition().first << " " << maze.getSnakePosition().second << endl;

    cout << "\nLives: " << (snake.get_lives()) << " | Score: " << snake.get_score() << "     | Food eaten: " << apple.getCurrentAmount() << " of " << apple.getTotalAmout() << "\n\n";
    cout << "----------------------------------------------------\n";

    switch(state){
        case RUNNING:
            //desenha todas as linhas do labirinto
            maze.printMaze();
            break;
        case WAITING_USER:
            cout<<"Você quer continuar com o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            game_over();
            break;
    }
    frameCount++;
}

void SnakeGame::game_over(){
  clearScreen();

  cout << "#######################################################################" << endl;
	cout << "#######################################################################" << endl;
	cout << "##        ##      ##          ##      ##       ##  #####  ##      #   #" << endl;
	cout << "##  ########  ##  ##  ##  ##  ##  ######  ###  ##  ####  ###  ##### # #" << endl;
	cout << "##  ########  ##  ##  ##  ##  ##    ####  ###  ###  ###  ###    ### # #" << endl;
	cout << "##  ####  ##      ##  ######  ##  ######  ###  ####  #  ####  #####   #" << endl;
	cout << "##  ####  ##  ##  ##  ######  ##  ######  ###  ####  #  ####  ##### # #" << endl;
	cout << "##        ##  ##  ##  ######  ##      ##       #####   #####      # # #" << endl;
	cout << "#######################################################################" << endl;
	cout << "#######################################################################" << endl;
}

void SnakeGame::loop(){
    while(state != GAME_OVER){
        process_actions();
        update();
        render();
        wait(1000);// espera 1 segundo entre cada frame
    }
}
