#ifndef RPG_H
#define RPG_H
#define MAX_BUF 200

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

struct personagem {
	char nickname[15];
	int life;
	int gun;
	int coins;
}p;

struct enemy {
	char name[15];
	int life;
	int biome;
	int price;
	int damage;
}e;

void SaveGame(struct personagem *p)
{	
	// Pegar diret√≥rio atual
	char path[MAX_BUF];
	getcwd(path, MAX_BUF);
	
	// Criar pasta 'player_data'
	mkdir("player_data");
	// Declarando arquivo
	FILE *fptr;
	// Concatenando diret√≥rio atual com o nome do arquivo que vai ser criado
	strcat(path, "\\player_data\\player.txt");
	// Criando arquivo
	fptr = fopen(path,"w");
	
	// Se o diret√≥rio for nulo...
	if(fptr == NULL)
	{
		printf("Erro ao salvar.");      
	}
	// Sen√£o...
	else
	{
		// Salvando arquivo
		fprintf(fptr,"%s\n", p->nickname);
		fprintf(fptr,"%d\n", p->life);
		fprintf(fptr,"%d\n", p->gun);
		fprintf(fptr,"%d", p->coins);
		fclose(fptr);
		printf("O jogo foi salvo com sucesso!");
	}

}

void LoadGame(struct personagem *p)
{	
	char path[MAX_BUF];
	getcwd(path, MAX_BUF);
	// Declarando arquivo
	FILE *fptr;
	// Concatenando diret√≥rio atual com o nome do arquivo que vai ser criado
	strcat(path, "\\player_data\\player.txt");
	// Criando arquivo
	fptr = fopen(path,"r");
	
	// Se o diret√≥rio for nulo...
	if(fptr == NULL)
	{
		printf("Erro ao carregar.");      
	}
	// Sen√£o...
	else
	{
		// Salvando arquivo
		fscanf(fptr,"%s", p->nickname);
		fscanf(fptr,"%d", &p->life);
		fscanf(fptr,"%d", &p->gun);
		fscanf(fptr,"%d", &p->coins);
		fclose(fptr);
		printf("%s,\n%d,\n%d,\n%d", p->nickname, p->life, p->gun, p->coins);
	}

}

int Attack(struct personagem *p)
{
	int damage;
    
    	// Assumindo que 0 = rev√≥lver, 1 = escopeta, 3 = fac√£o, default = inaptid√£o, tal que:
    	// - 0 pode causar de 10 a 20 de dano;
    	// - 1 pode causar de 20 a 40 de dano;
    	// - 2 pode causar de 25 a 35 de dano;
    	// - default n√£o causa dano.
    
    	switch (p->gun)
    	{
		// Se o jogador possuir um rev√≥lver
		case 0:
		    // Sortear n√∫mero entre 10 e 20
		    damage = rand() % 10 + 11;
		    // Retornar o dano sorteado
		    return damage;
		    break;

		// Se o jogador possuir uma escopeta  
		case 1:
		    // Sortear n√∫mero entre 20 e 40
		    damage = rand() % 20 + 21;
		    // Retornar o dano sorteado
		    return damage;
			break;
		// Se o jogador possuir um fac√£o  
		case 2:
		    // Sortear n√∫mero entre 25 e 35
		    damage = rand() % 10 + 26;
		    // Retornar o dano sorteado
		    return damage;
			break;
		// Se o jogador n√£o estiver apto a realizar um ataque   
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
    
	// S√≥ continuar quando Enter for pressionado
	printf("\n\n\t\t\t\e[1m[Enter para continuar...]\e[m");
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
	    	ArrowHere(3, position); printf("CR…DITOS\n");
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
			Dialogue("\t\t\tSer· criado um novo jogo.", "green", 0);
			break;
		case 2:
			system("cls");
			Dialogue("\t\t\tSer· carregado o jogo salvo.", "blue", 0);
			break;
		case 3:
			system("cls");
			Dialogue("\t\t\tSer„o mostrados os crÈditos.", "white", 0);
			break;
		case 4:
			system("cls");
			break;
	}
}

int Enemy(int biome, struct enemy *e)
{

	switch (biome)
    	{
        	case 0:
        		strcpy(e->name, "JavarÈ");
            	e->life = 50;
            	e->damage = 20;
            	break;
        	case 1:
        		strcpy(e->name, "Bruno");
            	e->life = 100;
            	e->damage = 30;
            	break;
        	case 2:
        		strcpy(e->name, "Pedro");
            	e->life = 150;
            	e->damage = 40;
            	break;
        	case 3:
        		strcpy(e->name, "Carlos Inform·tica");
            	e->life = 200;
            	e->damage = 60;
            	break;
        	case 4:
        		strcpy(e->name, "Crate˙s CÛpias");
            	e->life = 300;
            	e->damage = 70;
            	break;
        	default:
            		return 0;
    	}
}

void Battle(int damageAttack, struct personagem *p, struct enemy *e)
{
    
	while (e->life > 0)
    	{
  		int position = 1, keyPressed = 0;
    
  		#define MAX 4
  		#define MIN 1
    
  		while (keyPressed != 13)
  		{
	    		// Mostrando menu
	    		printf("\n\t\t\tInimigo: %d PV\n", e->life);
	    		printf("\t\t\tVida do jogador: %d PV\n", p->life);
	    		printf("\n\n\t\t\t======[MENU]======\n");
	    		ArrowHere(1, position); printf("ATACAR\n");
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
				e->life -= damageAttack;
				p->life -= e->damage;
      				printf("\n\t\t\t[%d DE DANO!]", damageAttack);
      				damageAttack = Attack(&p);
      			break;
      				
      			
		}
        
    	}
	system("cls");
    	printf("\n\t\t\tVocÍ matou o inimigo!");
}

#endif
