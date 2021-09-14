#include "SnakeGame.h"
#include <fstream>
#include <iostream>

#include <chrono> //por causa do sleep
#include <thread> //por causa do sleep
#include <string>
#include <vector>

using namespace std;

SnakeGame::SnakeGame(string data, string type){
    choice = "";
    frameCount = 0;
    initialize_game(data, type);
}

void SnakeGame::initialize_game(string data, string type){
  bool isPacman = type == "pacman";
  snake.setIsPacman(isPacman);

  level.readMazes(data);
  maze = level.getCurrentMaze();
  maze.newApple();
  maze.setFirstSnakePosition(snake);


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
            maze.printSnake(snake.getBody(), snake.getHead());
            maze.printApple(maze.aplle.getCoodsApple());
            maze.clearValue(snake.getOldCoord().first, snake.getOldCoord().second);
            player.next_move(snake, maze);
            if(maze.aplle.getCurrentAmount() == maze.aplle.getTotalAmout()) state = WAITING_USER;
            if(snake.get_number_lives() == 0)state = WAITING_USER;

            // if(frameCount>0 && frameCount%10 == 0) //depois de 10 frames o jogo pergunta se o usuário quer continuar
                // state = WAITING_USER;
            break;
        case WAITING_USER: //se o jogo estava esperando pelo usuário então ele testa qual a escolha que foi feita
            if(choice == "n"){
                if(maze.aplle.getCurrentAmount() != maze.aplle.getTotalAmout()){
                  state = GAME_OVER;
                }else {
                  state = WIN;
                }
            }
            else{
                //pode fazer alguma coisa antes de fazer isso aqui
                auto head = snake.getBody()[0];
                auto posicaoInicial = snake.getFirstPosition();
                maze.clearValue(head.first, head.second);
                maze.aplle.setCurrentAmount(0);
                snake.setHead('v');
                snake.setHeadPosition(posicaoInicial.first, posicaoInicial.second);
                snake.setLifes(5);

                state = RUNNING;
            }
            break;
        default:
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
    switch(state){
        case RUNNING:
            cout << "----------------------------------------------------\n";
            cout << "Lives: " << (snake.get_lives()) << " | Score: " << snake.get_score() << "     | Food eaten: " << maze.aplle.getCurrentAmount() << " of " << maze.aplle.getTotalAmout() << "\n";
            cout << "----------------------------------------------------\n";
            maze.printMaze();
            break;
        case WAITING_USER:
            cout<<"Você quer repetir o jogo? (s/n)"<<endl;
            break;
        case GAME_OVER:
            game_over();
            break;
        case WIN:
            win();
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
	cout << "##  ###   ##      ##  ######  ##  ######  ###  ####  #  ####  #####   #" << endl;
	cout << "##  ####  ##  ##  ##  ######  ##  ######  ###  ####  #  ####  ##### # #" << endl;
	cout << "##        ##  ##  ##  ######  ##      ##       #####   #####      # # #" << endl;
	cout << "#######################################################################" << endl;
	cout << "#######################################################################" << endl;
  cout << "----------------------------------------------------\n";
  cout << "Lives: " << (snake.get_lives()) << " | Score total: " << snake.get_score() << "     | Food eaten: " << maze.aplle.getCurrentAmount() << " of " << maze.aplle.getTotalAmout() << "\n";
  cout << "----------------------------------------------------\n";
}

void SnakeGame::win(){
  clearScreen();

  cout << "██████████████████████████████████████████████████████████" << endl;
  cout << "█░░░░░░██████████░░░░░░█░░░░░░░░░░█░░░░░░██████████░░░░░░█" << endl;
  cout << "█░░▄▀░░██████████░░▄▀░░█░░▄▀▄▀▄▀░░█░░▄▀░░░░░░░░░░██░░▄▀░░█" << endl;
  cout << "█░░▄▀░░██████████░░▄▀░░█░░░░▄▀░░░░█░░▄▀▄▀▄▀▄▀▄▀░░██░░▄▀░░█" << endl;
  cout << "█░░▄▀░░██████████░░▄▀░░███░░▄▀░░███░░▄▀░░░░░░▄▀░░██░░▄▀░░█" << endl;
  cout << "█░░▄▀░░██░░░░░░██░░▄▀░░███░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█" << endl;
  cout << "█░░▄▀░░██░░▄▀░░██░░▄▀░░███░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█" << endl;
  cout << "█░░▄▀░░██░░▄▀░░██░░▄▀░░███░░▄▀░░███░░▄▀░░██░░▄▀░░██░░▄▀░░█" << endl;
  cout << "█░░▄▀░░░░░░▄▀░░░░░░▄▀░░███░░▄▀░░███░░▄▀░░██░░▄▀░░░░░░▄▀░░█" << endl;
  cout << "█░░▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀▄▀░░█░░░░▄▀░░░░█░░▄▀░░██░░▄▀▄▀▄▀▄▀▄▀░░█" << endl;
  cout << "█░░▄▀░░░░░░▄▀░░░░░░▄▀░░█░░▄▀▄▀▄▀░░█░░▄▀░░██░░░░░░░░░░▄▀░░█" << endl;
  cout << "█░░░░░░██░░░░░░██░░░░░░█░░░░░░░░░░█░░░░░░██████████░░░░░░█" << endl;
  cout << "██████████████████████████████████████████████████████████" << endl;
  cout << "----------------------------------------------------\n";
  cout << "Lives: " << (snake.get_lives()) << " | Score total: " << snake.get_score() << "     | Food eaten: " << maze.aplle.getCurrentAmount() << " of " << maze.aplle.getTotalAmout() << "\n";
  cout << "----------------------------------------------------\n";
}

void SnakeGame::loop(){
    while(state != GAME_OVER && state != WIN){
        process_actions();
        update();
        render();
        wait(100);// espera 0.1 segundo entre cada frame
    }
}
