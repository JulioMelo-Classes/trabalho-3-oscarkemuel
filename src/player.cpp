#include "player.h"

bool Player::next_move(Snake &snake, Maze &maze){
  // if(!snake.isPacman() && snake.getBody().size() > 1){
  //   snake.moveBody();
  // }

  auto head = snake.getBody()[0];
  auto stringHead = snake.getHead();

  auto atual = maze.getValue(head.first, head.second);
  auto cima = maze.getValue(head.first-1, head.second);
  auto baixo = maze.getValue(head.first+1, head.second);
  auto direita = maze.getValue(head.first, head.second+1);
  auto esquerda = maze.getValue(head.first, head.second-1);

  if(cima == 'o' || baixo == 'o' ||esquerda == 'o' || direita == 'o'){
    int currentAmount = maze.aplle.getCurrentAmount();
    snake.setOldCoord(head.first, head.second);

    if(cima == 'o'){
      snake.setHead('v');
      snake.setHeadPosition(head.first-1, head.second);
      maze.clearValue(head.first-1, head.second);
      maze.newApple();
    } else if(baixo == 'o'){
      snake.setHead('A');
      snake.setHeadPosition(head.first+1, head.second);
      maze.clearValue(head.first+1, head.second);
      maze.newApple();
    } else if(direita == 'o'){
      snake.setHead('<');
      snake.setHeadPosition(head.first, head.second+1);
      maze.clearValue(head.first, head.second+1);
      maze.newApple();
    } else if(esquerda == 'o'){
      snake.setHead('>');
      snake.setHeadPosition(head.first, head.second-1);
      maze.clearValue(head.first, head.second-1);
      maze.newApple();
    }

    maze.aplle.setCurrentAmount(currentAmount + 1);

    // if(!snake.isPacman()){
    //   snake.addBody(head.first, head.second);
    // }
    snake.set_score(snake.get_score() + 100);

    return true;
  }

  if(stringHead == 'v'){
    if(cima == ' '){
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first-1, head.second);
    }else if(direita == ' '){
      snake.setHead('<');
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first, head.second+1);
    }else if(esquerda == ' '){
      snake.setHead('>');
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first, head.second-1);
    }
  }

  if(stringHead == '<'){
    if(direita == ' '){
    snake.setOldCoord(head.first, head.second);
    snake.setHeadPosition(head.first, head.second+1);
    }else if(cima == ' '){
      snake.setHead('v');
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first-1, head.second);
    }else if(baixo == ' '){
      snake.setHead('A');
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first+1, head.second);
    }
  }

  if(stringHead == 'A'){
    if(baixo == ' '){
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first+1, head.second);
    }else if(direita == ' '){
      snake.setHead('<');
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first, head.second+1);
    }else if(esquerda == ' '){
      snake.setHead('>');
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first, head.second-1);
    }
  }

  if(stringHead == '>'){
    if(esquerda == ' '){
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first, head.second-1);
    }else if(cima == ' '){
      snake.setHead('v');
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first-1, head.second);
    }else if(baixo == ' '){
      snake.setHead('A');
      snake.setOldCoord(head.first, head.second);
      snake.setHeadPosition(head.first+1, head.second);
    }
  }

  return false;
}
