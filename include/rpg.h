#ifndef RPG_H
#define RPG_H
#define MAX_BUF 200

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

typedef struct personagem {
	char nickname[15];
	int life;
	int gun;
	int coins;
	int level;
	int medicine;
} personagem;

typedef struct enemy {
	char name[15];
	int life;
	int biome;
	int price;
	int damage;
} enemy;

void Dialogue(char text[], char color[], int seconds)
{   
	system("cls");
	int x; double y;
	// Adicionar delay de x segundos
	sleep(seconds);
	 
	if (color == "black") {
		printf("\n\033[0;30m");
	} else if (color == "red") {
		printf("\n\033[0;31m");
	} else if (color == "green") {
		printf("\n\033[0;32m");
	} else if (color == "yellow") {
		printf("\n\033[0;33m");
	} else if (color == "blue") {
		printf("\n\033[0;34m");
	} else if (color == "purple") {
		printf("\n\033[0;35m");
	} else if (color == "cyan") {
		printf("\n\033[0;36m");
	} else if (color == "white") {
		printf("\n\033[0;37m");
	}
    	// Mostrar o texto
    	for(x=0; text[x] != NULL; x++)
    	{
		printf("%c",text[x]);
		for(y=0; y<=4800000; y++)
		{
		}
    	}
    
	// SÃ³ continuar quando Enter for pressionado
	printf("\n\n\t\t\t\e[1m[Enter para continuar...]\e[m \033[m");
	char enter = 0;
	while (enter != '\r' && enter != '\n')
	{
		enter = getchar();
	}
    
	// Limpar console
	system("cls");
}

void SaveGame(personagem *p)
{	
	// Pegar diretÃ³rio atual
	char path[MAX_BUF];
	getcwd(path, MAX_BUF);
	
	// Criar pasta 'player_data'
	mkdir("player_data");
	// Declarando arquivo
	FILE *fptr;
	// Concatenando diretÃ³rio atual com o nome do arquivo que vai ser criado
	strcat(path, "\\player_data\\player.txt");
	// Criando arquivo
	fptr = fopen(path,"w");
	
	// Se o diretÃ³rio for nulo...
	if(fptr == NULL)
	{
		printf("\n\t\t\tErro ao salvar.");      
	}
	// SenÃ£o...
	else
	{
		// Salvando arquivo
		fprintf(fptr,"%s\n", p->nickname);
		fprintf(fptr,"%d\n", p->life);
		fprintf(fptr,"%d\n", p->gun);
		fprintf(fptr,"%d\n", p->coins);
		fprintf(fptr,"%d\n", p->level);
		fprintf(fptr,"%d", p->medicine);
		fclose(fptr);
		Dialogue("\t\t\tO jogo foi salvo com sucesso!", "green", 0);
	}

}

void LoadGame(personagem *p)
{	
	char path[MAX_BUF];
	getcwd(path, MAX_BUF);
	// Declarando arquivo
	FILE *fptr;
	// Concatenando diretÃ³rio atual com o nome do arquivo que vai ser criado
	strcat(path, "\\player_data\\player.txt");
	// Criando arquivo
	fptr = fopen(path,"r");
	
	// Se o diretÃ³rio for nulo...
	if(fptr == NULL)
	{
		printf("\t\t\tErro ao carregar.");      
	}
	// SenÃ£o...
	else
	{
		// Salvando arquivo
		fscanf(fptr,"%s", p->nickname);
		fscanf(fptr,"%d", &p->life);
		fscanf(fptr,"%d", &p->gun);
		fscanf(fptr,"%d", &p->coins);
		fscanf(fptr,"%d", &p->level);
		fscanf(fptr,"%d", &p->medicine);
		fclose(fptr);
		
		Loading(2);
		History(&p);
	}

}

int Enemy(int biome, enemy *e)
{

	switch (biome)
    	{
        	case 0:
        		strcpy(e->name, "Javaré");
        		e->price = 20;
            	e->life = 50;
            	e->damage = 20;
            	break;
        	case 1:
        		strcpy(e->name, "Bruno");
        		e->price = 30;
            	e->life = 100;
            	e->damage = 30;
            	break;
        	case 2:
        		strcpy(e->name, "Pedro");
        		e->price = 40;
            	e->life = 150;
            	e->damage = 40;
            	break;
        	case 3:
        		strcpy(e->name, "Carlos Informática");
        		e->price = 60;
            	e->life = 200;
            	e->damage = 60;
            	break;
        	case 4:
        		strcpy(e->name, "Crateús Cópias");
        		e->price = 70;
            	e->life = 300;
            	e->damage = 70;
            	break;
        	default:
            	return 0;
    	}
}

int Attack(personagem *p)
{
	int damage;
    
    	// Assumindo que 0 = facão, 1 = escopeta, 3 = revolver, default = inaptidÃ£o, tal que:
    	// - 0 pode causar de 10 a 20 de dano;
    	// - 1 pode causar de 20 a 40 de dano;
    	// - 2 pode causar de 25 a 35 de dano;
    	// - default nÃ£o causa dano.
    	switch (p->gun)
    	{
		// Se o jogador possuir um revÃ³lver
		case 0:
		    // Sortear nÃºmero entre 10 e 20
		    damage = rand() % 10 + 11;
		    // Retornar o dano sorteado
		    return damage;
		    break;

		// Se o jogador possuir uma escopeta  
		case 1:
		    // Sortear nÃºmero entre 20 e 40
		    damage = rand() % 20 + 21;
		    // Retornar o dano sorteado
		    return damage;
			break;
		// Se o jogador possuir um facÃ£o  
		case 2:
		    // Sortear nÃºmero entre 25 e 35
		    damage = rand() % 10 + 26;
		    // Retornar o dano sorteado
		    return damage;
			break;
		// Se o jogador nÃ£o estiver apto a realizar um ataque   
		default:
		    return 0;
    	}
}

void Death(personagem *p) {
	
	if (p->level == 1) {
		Dialogue("\n\t\t\tVocê morreu antes mesmo de\n\t\t\tcomeçar a aventura...", "red", 1);
		Menu(p);
	} else if (p->level == 2) {
		Dialogue("\t\t\ta", "red", 2);
		Menu(p);
	}
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

void Menu(personagem *p)
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
			History(*p);
			break;
		case 2:
			system("cls");
			LoadGame(&p);
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

void Battle(int damageAttack, personagem *p, enemy *e)
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
      			damageAttack = Attack(p);
      			
      			if (p->life <= 0) {
      				Death(p);
				}
      			
				break;				
		}
        
    }
	system("cls");
	Dialogue("\t\t\tVocê matou o inimigo!", "green", 0);
	printf("\t\t\t[+%d MOEDAS]", e->price);
	p->coins += e->price;
	Sleep(1000);
}

void Loading(int time)
{
    system("cls");
    printf("\n");
	int i;
    for (i = 0; i < time; i++) 
	{
        int j;
		printf("\t\t\tCarregando save ");
        for ( j = 0; j < 3; j++)
		{
            printf(".");
            Sleep(200);
        }
        printf("\r");
        int k;
        for (k = k; k < 3; k++)
		{
            printf(" "); // apaga a linha anterior
        }
        printf("\r");
    }
}

void History(personagem *p){
	int tecla;
	
	while (1)
	{
		// o level determina a parte da história que será contada
		// 0 - inicio do jogo
		
		switch (p->level)
		{
			case 0:
				system("cls");
				//Dialogue("\t\t\tPara iniciar, digite seu nome: ", "green", 0);
				printf("\n\t\t\tPara iniciar, digite seu nome: ");
				gets(p->nickname);
					
				Dialogue("\t\t\t Você é um cara que sua filha fica Doente ", "cyan", 0);
				Dialogue("\t\t\tVocê decide então partir em uma jornada em busca de uma cura para ela", "cyan", 0);
				Dialogue("\t\t\tAssim, armado com um velho facão", "cyan", 0);
				
				Dialogue("\t\t\tVoce Adquiriu facão!!!", "blue", 0);
				
				printf("\t\t\tDeseja salvar o jogo? (s/n)");
				tecla = getch();
				
				p->gun = 0;
				p->life = 500;
				p->coins = 10;
				p->level = 1;
				
				
				if (tecla == 83 || tecla == 115) {
					SaveGame(p);
				} else if (tecla == 78 || tecla == 110) {
	
				}
				enemy e;
				Enemy(0, &e);
				Battle(Attack(p), p, &e);
				break;
			case 1:
				Dialogue("\t\t\tSegunda parte", "green", 0);
				break;
	
		}
	}
}

void StoreMenu(personagem *p){
	system("cls");
  	int position = 1, keyPressed = 0;
    
  	while (keyPressed != 13)
  	{
		system("cls");
	    	// Mostrando menu
	    	printf("\t\t\t======[LOJA]======\n");
	    	printf("\t\t\t    MOEDAS: %d\n  ", p->coins);
	    	ArrowHere(1, position); printf("100 - REVOLVER\n");
	    	ArrowHere(2, position); printf("200 - ESCOPETA\n");
	    	ArrowHere(3, position); printf("050 - REMÉDIO\n");
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
			if(p->gun >= 1){
				Dialogue("Você já possui essa arma ou outra melhor", "white", 0);
				StoreMenu(p);
			}
			else if(p->coins < 100){
				Dialogue("Você não possui moedas suficientes!", "white", 0);
				StoreMenu(p);
			}
			else{
				p->coins -=100;
				p->gun = 1;
				Dialogue("\t\t\tVoce Adquiriu um revolver!!!", "blue", 0);
				StoreMenu(p);
			}
			break;
		case 2:
			system("cls");
			if(p->gun >= 2){
				Dialogue("Você já possui essa arma", "white", 0);
				StoreMenu(p);
			}
			else if(p->coins < 200){
				Dialogue("Você não possui moedas suficientes!", "white", 0);
				StoreMenu(p);
			}
			else{
				p->coins -=200;
				p->gun = 2;
				Dialogue("\t\t\tVocê Adquiriu uma escopeta!!!", "blue", 0);
				StoreMenu(p);
			}
			break;
		case 3:
			system("cls");
			
			if(p->coins < 50){
				Dialogue("Você não possui moedas suficientes!", "white", 0);
				StoreMenu(p);
			}
			else{
				p->coins -=50;
				p->medicine +=1;
				Dialogue("\t\t\tVoce Adquiriu um medicamento!!!", "blue", 0);
				Dialogue("\t\t\tDurande a batalha você pode usá-lo para recuperar vida!!!", "blue", 0);
				StoreMenu(p);
			}
			break;
		case 4:
			system("cls");
			break;
	}
}

#endif
