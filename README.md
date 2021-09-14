Trabalho 3
# Trabalho-3
Repositório contendo as especificações do Trabalho 3 da disciplina de LP1

## Clonar, Compilar e Executar

### Clonar
Para clonar o trabalho, rode os seguintes comandos:
```
git clone https://github.com/JulioMelo-Classes/trabalho-3-oscarkemuel.git
cd trabalho-3-oscarkemuel
```

### Compilação
Para compilar o trabalho, rode os seguintes comandos:
```
mkdir build && cd build
cmake ../
make
```

### Execução
Para executar com um labirinto inicial, rode o seguinte comando:
```
./snaze <nome do arquivo> <tipo do game (pacman || cobra)>
```

### Atividades que não conclui a tempo
* Implementação da classe player
  * find_solution
* Uso de níveis
* Modo de jogo cobra
* Conta de score

## Testando funcionalidades
### Teste 1 - A cobra sempre vai conseguir comer (com a lógica que fiz);
```
./snaze maze1.txt pacman
```
### Teste 2 - A cobra nem sempre vai comer toda comida que deveria (consequencia de não ter implementado o find_solution);
```
./snaze maze2.txt pacman
```

### Teste 3 - A cobra sempre morre;
```
./snaze maze3.txt pacman
```
