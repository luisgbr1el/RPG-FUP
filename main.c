#include "include/rpg.h"
#include <stdlib.h>

int main()
{
	// Exemplo de uso 'SaveGame()':
	SaveGame("Astronildo", 100, "vazio");
	// ----
	
	// Exemplo de uso 'Attack()':
	srand(time(NULL));
	int life = 1000;

	// Simulando uma sequência de 10 ataques
	for (int i = 0; i < 10; i++) {
		printf("\n%d", life -= Attack(2));
	}
	// ----
	
	return 0;
}
