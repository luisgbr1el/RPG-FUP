#include "include/rpg.h"
#include <stdlib.h>
#include <locale.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
//	
	personagem p;
	enemy e;
//	p.coins = 500;
	
	Dialogue("\t\t\tIntegrantes do grupo:\n\t\t\t- Francisco Diego\n\t\t\t- Jos? Luis Braga\n\t\t\t- Luis Gabriel", "yellow", 0);
	Menu(&p);
	
	//LoadGame(&p);
//	strcpy(p.nickname, "salve");
//	p.life = 114;
//	p.gun = 2;
	//Loading(20);
//	p.coins = 4812;
//	
//	printf("%s", p.nickname);
	// Exemplo de uso 'SaveGame()':
	//SaveGame(&p);
	// ----
	//system("cls");
	//Enemy(4, &e);
	
	//Battle(Attack(&p), &p, &e);
	
	return 0;
}
