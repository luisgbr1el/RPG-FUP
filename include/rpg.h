#ifndef RPG_H
#define RPG_H
#define MAX_BUF 200

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

void SaveGame(char nickname[], int life, int gun, int coins)
{	
	// Pegar diretório atual
	char path[MAX_BUF];
	getcwd(path, MAX_BUF);
	
	// Criar pasta 'player_data'
	mkdir("player_data");
	// Declarando arquivo
	FILE *fptr;
	// Concatenando diretório atual com o nome do arquivo que vai ser criado
	strcat(path, "\\player_data\\player.txt");
	// Criando arquivo
	fptr = fopen(path,"w");
	
	// Se o diretório for nulo...
	if(fptr == NULL)
	{
		printf("Erro ao salvar.");      
	}
	// Senão...
	else
	{
		// Salvando arquivo
		fprintf(fptr,"%s,%d,%d,%d", nickname, life, gun, coins);
		fclose(fptr);
		printf("O jogo foi salvo com sucesso!");
	}

}

int Attack(int itemId)
{
	int damage;
    
    	// Assumindo que 0 = revólver, 1 = escopeta, 3 = facão, default = inaptidão, tal que:
    	// - 0 pode causar de 10 a 20 de dano;
    	// - 1 pode causar de 20 a 40 de dano;
    	// - 2 pode causar de 25 a 35 de dano;
    	// - default não causa dano.
    
    	switch (itemId)
    	{
		// Se o jogador possuir um revólver
		case 0:
		    // Sortear número entre 10 e 20
		    damage = rand() % 10 + 11;
		    // Retornar o dano sorteado
		    return damage;

		// Se o jogador possuir uma escopeta  
		case 1:
		    // Sortear número entre 20 e 40
		    damage = rand() % 20 + 21;
		    // Retornar o dano sorteado
		    return damage;

		// Se o jogador possuir um facão  
		case 2:
		    // Sortear número entre 25 e 35
		    damage = rand() % 10 + 26;
		    // Retornar o dano sorteado
		    return damage;

		// Se o jogador não estiver apto a realizar um ataque   
		default:
		    return 0;
    	}
}

void Dialogue(char text[], char color[], int seconds)
{   
	system("cls");
	int x; double y;
	// Adicionar delay de x segundos
	sleep(seconds);
	 
	if (color == "black") {
		printf("\033[0;30m");
	} else if (color == "red") {
		printf("\033[0;31m");
	} else if (color == "green") {
		printf("\033[0;32m");
	} else if (color == "yellow") {
		printf("\033[0;33m");
	} else if (color == "blue") {
		printf("\033[0;34m");
	} else if (color == "purple") {
		printf("\033[0;35m");
	} else if (color == "cyan") {
		printf("\033[0;36m");
	} else if (color == "white") {
		printf("\033[0;37m");
	}
    	// Mostrar o texto
    	for(x=0; text[x]!=NULL; x++)
    	{
		printf("%c",text[x]);
		for(y=0; y<=8888888; y++)
		{
		}
    	}
    
	// Só continuar quando Enter for pressionado
	printf("\n\n\e[1m[Enter para continuar...]\e[m");
	char enter = 0;
	while (enter != '\r' && enter != '\n')
	{
		enter = getchar();
	}
    
	// Limpar console
	system("cls");
}

void ArrowHere(int realPosition, int arrowPosition)
{
	if (realPosition == arrowPosition) {
		printf("\t\t\t-> ");
	}
	else {
		printf("\t\t\t   ");
	}
}

void Menu()
{
	system("cls");
  	int position = 1, keyPressed = 0;
    
  	#define MAX 4
  	#define MIN 1
    
  	while (keyPressed != 13)
  	{
		system("cls");
	    	// Mostrando menu
	    	printf("\t\t\t======[MENU]======\n");
	    	ArrowHere(1, position); printf("NOVO JOGO\n");
	    	ArrowHere(2, position); printf("CARREGAR JOGO\n");
	    	ArrowHere(3, position); printf("CRÉDITOS\n");
	    	ArrowHere(4, position); printf("SAIR\n");
	    	printf("\t\t\t==================\n");

	    	keyPressed = getch();
			
	    	if (keyPressed == 80 && position != MAX) {
			position++;
	    	} else if (keyPressed == 72 && position != MIN) {
			position--;
	    	} else {
			position = position;
	    	}
	}
	
	switch (position) {
		case 1:
			system("cls");
			Dialogue("\t\t\tSerá criado um novo jogo.", "green", 0);
			break;
		case 2:
			system("cls");
			Dialogue("\t\t\tSerá carregado o jogo salvo.", "blue", 0);
			break;
		case 3:
			system("cls");
			Dialogue("\t\t\tSerão mostrados os créditos.", "white", 0);
			break;
		case 4:
			system("cls");
			break;
	}
}

#endif
