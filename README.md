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
./snaze maze1.txt
```

### Atividades que não conclui a tempo no CP1
* Implementação da classe player
  * Gerar coordenada para comida
* Implementação de níveis
* Diferenciação dos Modos de jogo (sem e com rabo)

<!-- ## Testando funcionalidades
### Teste 1 - Testes de Criação de usuário, login e desconnect;
```
./concordo < ../data/test_1.txt
```
### Teste 2 - Criação, remoção, descrição, listagem e convite de servidores;
```
./concordo < ../data/test_2.txt
```
### Teste 3 - Entrar, sair e listagem de participantes do servidor;
```
./concordo < ../data/test_3.txt
```
### Teste 4 - Criar, entrar e sair de canais;
```
./concordo < ../data/test_4.txt
```
### Teste 5 - Envio e listagem de mensagens;
```
./concordo < ../data/test_5.txt
``` -->

## Avaliação CP1

### Snake/Pacman
O jogo deveria conter o modo snake/pacman. Em ambos os modos não é possível andar pra trás. No modo snake deve ser desenhado o corpo.

**Avaliação**

não implementado

### Render.ui
O jogo deveria desenhar a UI corretamente, mostrando ao menos as vidas, o nível e o score.

**Avaliação**

não implementado

### Render.mapa
O jogo deveria desenhar o mapa corretamente, com base no arquivo passado como argumento. Ok

**Avaliação**

ok

### Render.snake
O jogo deveria desenhar a snake corretamente.

**Avaliação**

não implementado

### Logic.colisão e Logic.comida
O jogo deve se comportar corretamente quando ocorre uma colisão com comida e com paredes.

**Avaliação**

não implementado

### Transição de mapas
O jogo deve ter transição de mapa uma vez que um mapa é terminado.

**Avaliação**

Não implementado.

### Interação com o usuário
O jogo deve perguntar ao usuário se quer continuar/reiniciar o nível/reiniciar o jogo a cada transição de mapa

**Avaliação**

Não implementado

### Classe Level ou similar
O software deve encapsular as funcionalidades do nível em uma classe.

**Avaliação**

Ok

### Classe Player ou similar
O software deve encapsular as decisões do jogo em uma classe.

**Avaliação**

não implementado

### Classe Snake ou similar
O software deve encapsular as funcionalidades relacionadas à snake em uma classe. 

**Avaliação**

vou considerar 50% uma vez que ainda não está sendo útil para o sistema

## Comentários gerais CP1
- Acho que do modo que está você só teria como entregar o CP1, ainda faltam muitas coisas básicas do jogo, sugiro que você tente implementar ao menos a movimentação da snake no mapa.