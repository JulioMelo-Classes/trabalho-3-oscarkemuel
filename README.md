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


# Avaliação CP2

## FindSolution.pacman

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo pacman.

**Avaiação**

não implementado

## FindSolution.snake

O método find soluiton ou similar deve ser capaz de encontrar o conjunto de comandos que levam da posição atual da cobrinha até a posição da comida no modo snake.

**Avaliação**

não implementado

## Random start

Deveria ser implementado na execução do programa um comando que permita que a posição inicial seja sorteada aleatoriamente. A posição inicial precisa ser válida e não deve causar a cobrinha/pacman iniciar em uma posição encurralada.

**Avaliação**

não implementado

## Level Loop

Deveria se implementado na execução do programa um comando que permite que os níveis fiquem se repetindo infinitamente, com a transição de mapas indo do primeiro nível até o último nível e voltando para o primeiro, de forma que seja mantida a contagem de pontos bem como a contagem de nível.

**Avaliação**

não implementado

## Organização / Compilação automatizada / Casos de Teste

Para a entrega final a organização do código em scr/data/include e compilação automatizada de alguma forma deve ser feita.

**Avaliação**

ok

## Documentação do código / Readme / Documentação de Casos de Teste

**Avaliação**

ok

## Alterações no CP1

- snake/pacman atualizei pra 25%
- render.ui atualizei pra 50%
- logic.colision atualizei pra 50%
- classe player atualizei pra 50%