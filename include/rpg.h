#ifndef RPG_H
#define RPG_H
#define MAX_BUF 200

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

void SaveGame(char nickname[], int life, char inventory[])
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
		fprintf(fptr,"%s,%d,%s", nickname, life, inventory);
		fclose(fptr);
		printf("O jogo foi salvo com sucesso!");
	}

}

int Attack(int itemId)
{
	int damage;
    
    	// Assumindo que 0 = nenhuma arma, 1 = arco, 2 = espada, default = inaptidão, tal que:
    	// - 0 pode causar de 1 a 10 de dano;
    	// - 1 pode causar de 10 a 25 de dano;
    	// - 2 pode causar de 25 a 35 de dano;
    	// - default não causa dano.
    
    	switch (itemId)
    	{
		// Se o jogador não possuir nenhuma arma
		case 0:
		    // Sortear número entre 1 e 10
		    damage = rand() % 10 + 1;
		    // Retornar o dano sorteado
		    return damage;

		// Se o jogador possuir um arco    
		case 1:
		    // Sortear número entre 10 e 25
		    damage = rand() % 10 + 16;
		    // Retornar o dano sorteado
		    return damage;

		// Se o jogador possuir uma espada   
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

void Dialogue(char text[], int seconds)
{   
	system("clear");
	int x; double y;
	// Adicionar delay de x segundos
	sleep(seconds);
    
    	// Mostrar o texto
    	for(x=0; text[x]!=NULL; x++)
    	{
		printf("%c",text[x]);
		for(y=0; y<=8888888; y++)
		{
		}
    	}
    
	// Só continuar quando Enter for pressionado
	printf("\n\n[Enter para continuar...]");
	char enter = 0;
	while (enter != '\r' && enter != '\n')
	{
		enter = getchar();
	}
    
	// Limpar console
	system("clear");
}

void arrowHere(int realPosition, int arrowPosition)
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
	    	arrowHere(1, position); printf("NOVO JOGO\n");
	    	arrowHere(2, position); printf("CARREGAR JOGO\n");
	    	arrowHere(3, position); printf("CRÉDITOS\n");
	    	arrowHere(4, position); printf("SAIR\n");
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
			Dialogue("Será criado um novo jogo.", 0);
			break;
		case 2:
			system("cls");
			Dialogue("Será carregado o jogo salvo.", 0);
			break;
		case 3:
			system("cls");
			printf("Serão mostrados os créditos.");
			break;
		case 4:
			system("cls");
			break;
	}
}

#endif
