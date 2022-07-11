# RPG
RPG textual de aventura e ação feito em C - Trabalho de Fundamentos da Programação (Ciência da Computação).

## Componentes
- [Diego Targino](https://github.com/diego-targino)
- [José Luis](https://github.com/yJoseLuis)
- [Luis Gabriel](https://github.com/luisgbr1el)

# Sinopse
Sua pequena filha possui uma doença desconhecida, só te resta tentar salva-la. Enfrente inimigos em uma aventura e traga a cura antes que o pior aconteça.


# Biblioteca `rpg.h`
Para facilitar a execução do projeto, foi criada uma biblioteca chamada [`rpg.h`](https://github.com/luisgbr1el/RPG-c/blob/main/include/rpg.h), onde criamos todas as funções para, finalmente, serem importadas para a [`main.c`](https://github.com/luisgbr1el/RPG-c/blob/main/main.c).

|Função|Descrição|
|-|-|
|`SaveGame()`|Função que salva o jogo atual. (itens do jogador, moedas, etc.)|
|`LoadGame()`|Função que carrega o jogo salvo. (itens do jogador, moedas, etc.)|
|`Attack()`|Função que calcula - dependendo de qual arma o jogador possui -, o dano que será causado pelo jogador.|
|`Dialogue()`|Função que "printa" textos da forma clássica de RPG's (letra a letra).|
|`ArrowHere()`|Função para mostrar a seleção do jogador no Menu do jogo.|
|`Menu()`|Função que mostra o Menu do jogo para o jogador.|
|`Enemy()`|Função que declara, dependendo do bioma, a vida do inimigo.|
|`Battle()`|Função que controla a mecânica das batalhas.|
|`Death()`|Função que controla qual mensagem aparecerá quando você morrer.|
|`Loading()`|Função que mostra uma tela de loading ao carregar save.|
|`History()`|Função que controla o "storytelling" do jogo, ordenando acontecimentos.|
|`StoreMenu()`|Função que mostra o menu da loja, onde o jogador pode usar suas moedas.|
