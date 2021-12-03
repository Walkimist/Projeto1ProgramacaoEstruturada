//Atividade 3 - Lista 1
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include<stdio.h>
#include<stdlib.h>

int main() {
	int numeros[100];
	int resultado = 0;

	for (int i = 0; i < 100; i ++) { //Pegar os numeros
		printf("Insira o %io numero: ", i+1);
		scanf("%i", &numeros[i]);
		system("cls");
	}
	for (int i = 0; i < 100; i ++) { //Somar os numeros
		resultado += numeros[i];
	}
	printf("A soma de todos os numeros e: %i", resultado); //Printar o resultado
}
