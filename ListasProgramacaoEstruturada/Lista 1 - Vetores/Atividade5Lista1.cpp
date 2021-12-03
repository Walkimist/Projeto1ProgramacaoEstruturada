//Atividade 5 - Lista 1
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include<stdio.h>
#include<stdlib.h>

int main() {
	int numeros[80];
	
	int quantEncontrados = 0;
	
	for (int i = 0; i < 80; i ++) {
		printf("Insira o numero %i: ", i+1);
		scanf("%i", &numeros[i]);
		system("cls");
	}
	
	int opcao;
	printf("Escolha um numero para ser buscado: ");
	scanf("%i", &opcao);
	system("cls");
	
	for (int i = 0; i < 80; i ++) { //Busca o vetor números
		if (numeros[i] == opcao) { //Caso encontre um número escolhido, conta o número encontrado e fala sua posição
			quantEncontrados ++;
			printf("Numero %i encontrado na posicao %i\n", opcao, i);
		}
	}
	printf("O numero %i foi encontrado %i vezes ao todo.", opcao, quantEncontrados); //Fala quantas vezes o número foi encontrado
}
