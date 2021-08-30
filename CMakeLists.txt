cmake_minimum_required(VERSION 3.5)
project(snake VERSION 0.1 LANGUAGES CXX )


### Executável
# Diretório contendo os .hpp
include_directories( include )

# Cria um executável com nome "concordo", adiciona neste executável os arquivos src/concordo.cpp src/sistema.cpp src/executor.cpp
add_executable( snaze
                src/snake.cpp
                src/apple.cpp
                src/maze.cpp
                src/SnakeGame.cpp
                src/Snaze.cpp )

# The end
