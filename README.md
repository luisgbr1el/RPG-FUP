# RPG
RPG textual de aventura e ação feito em C - Trabalho de Fundamentos da Programação (Ciência da Computação).


## Biblioteca `rpg.h`
Para facilitar a execução do projeto, foi criada uma biblioteca chamada [`rpg.h`](https://github.com/luisgbr1el/RPG-c/blob/main/include/rpg.h), onde criamos todas as funções para, finalmente, serem importadas para a [`main.c`](https://github.com/luisgbr1el/RPG-c/blob/main/main.c).

|Função|Descrição|
|-|-|
|`SaveGame()`|Função que salva o jogo atual. (itens do jogador, moedas, etc.)|
|`Attack()`|Função que calcula - dependendo de qual arma o jogador possui -, o dano que será causado pelo jogador.|
|`Dialogue()`|Função que "printa" textos da forma clássica de RPG's (letra a letra).|
|`ArrowHere()`|Função para mostrar a seleção do jogador no Menu do jogo.|
|`Menu()`|Função que mostra o Menu do jogo para o jogador.|


