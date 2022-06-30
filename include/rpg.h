#ifndef RPG_H
#define RPG_H
#define MAX_BUF 200

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

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
	// Adicionar delay de x segundos
	sleep(seconds);
    	// Mostrar o texto
	printf("%s", text);
    
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

void Menu()
{
    	int choose;
    
	// Mostrando menu
    	system("clear");
	printf("======[MENU]======");
	printf("\n1 - Novo jogo");
	printf("\n2 - Carregar jogo");
	printf("\n3 - Créditos");
    	printf("\n4 - Sair");
    	printf("\n=================\n");
    
    	printf("\n\nEscolha uma opção: ");
    	scanf("%d", &choose);
    
    	// Se a opção for inválida, continuar no menu
    	while (choose > 4 || choose < 1)
    	{	
		system("clear");
		printf("======[MENU]======");
		printf("\n1 - Novo jogo");
		printf("\n2 - Carregar jogo");
		printf("\n3 - Créditos");
		printf("\n4 - Sair");
		printf("\n=================\n");
        
		printf("\n\nEscolha uma opção: ");
		scanf("%d", &choose);
    	}
    
    	// Se a opção for válida, executar as funções necessárias
	switch (choose)
    	{
		case 1:
		    printf("\nNovo jogo será criado.");
		    break;
		case 2:
		    printf("\nJogo será carregado.");
		    break;
		case 3:
		    printf("\nOs créditos serão mostrados.");
		    break;
		case 4:
		    printf("\nO programa será encerrado...");
		    break;
    	}
}

#endif
