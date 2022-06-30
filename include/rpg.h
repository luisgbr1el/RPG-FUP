#ifndef RPG_H
#define RPG_H
#define MAX_BUF 200

#include <stdio.h>
#include <string.h>

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
	
	// Se não for possível acessar o diretório (diretório nulo)...
	if(fptr == NULL)
	{
		printf("Erro ao salvar.");      
	}

	// Salvando arquivo
	fprintf(fptr,"%s,%d,%s", nickname, life, inventory);
	fclose(fptr);
	printf("O jogo foi salvo com sucesso!");
}

#endif
