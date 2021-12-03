//Atividade 4 - Lista 1
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include<stdio.h>
#include<stdlib.h>

int main() {
	char letras[30];
	
	for (int i = 0; i < 30; i ++) { //Pega as letras
		printf("Insira uma letra qualquer: ");
		letras[i] = getchar();
		fflush(stdin);
		system("cls");
	}
	for (int i = 30 - 1; i >= 0; i--) { //Printa as letras em ordem inversa
		printf("Letra %i: ", i+1);
		putchar(letras[i]);
		printf("\n");
	}
}
