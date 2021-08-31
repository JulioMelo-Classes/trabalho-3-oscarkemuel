#include "level.h"
#include "maze.h"

#include <vector>
#include <string>

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

void Level::addMaze(Maze map){
  this->levels.push_back(map);
}

void Level::readMazes(string patch){
  int currentHeigth;
  int currentWidth;
  int currentAplle;

  vector<string> maze;

  ifstream levelFile(patch); //só dá certo se o jogo for executado dentro da raíz do diretório (vc vai resolver esse problema pegando o arquivo da linha de comando)
  int lineCount = 0;
  string line;
  if(levelFile.is_open()){
    while(getline(levelFile, line)){
      vector<string> values = split(line);

      if ((values[0][0] != '#') && (values[0][0] != '*') && (values[0][0] != '.') ){
        if(maze.size() > 0){
          Maze map;

          for(auto lineToAdd : maze){
            map.addLineInMaze(lineToAdd);
          }

          map.configureAplle(currentAplle);
          map.setHeight(currentHeigth);
          map.setWidth(currentWidth);


          addMaze(map);
          maze.clear();
        }

        currentHeigth = stoi(values[0]);
        currentWidth = stoi(values[1]);
        currentAplle = stoi(values[2]);
      }else{
        maze.push_back(line);
      }

      lineCount++;
    }

    if(maze.size() > 0){
      Maze map;

      for(auto lineToAdd : maze){
        map.addLineInMaze(lineToAdd);
      }

      map.configureAplle(currentAplle);
      map.setHeight(currentHeigth);
      map.setWidth(currentWidth);

      addMaze(map);
      maze.clear();
    }

    // for (int i = 0; i < levels.size(); i++){
    //   levels[i].printMaze();
    //   cout << endl;
    // }
  }

  this->currentLevel = 0;
}

int Level::getNumberOfLevels(){
  return this->levels.size();
}

Maze Level::getCurrentMaze(){
  return this->levels[this->currentLevel];
}
