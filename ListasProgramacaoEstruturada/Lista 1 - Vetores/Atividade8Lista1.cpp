//Atividade 8 - Lista 1
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include<stdio.h>
#include<stdlib.h>

int main() {
	int idades[100];
	float media = 0;
	
	for (int i = 0; i < 100; i ++){ //Pega as idades e já soma na média
		printf("Insira a idade da pessoa %i: ", i+1);
		scanf("%i", &idades[i]);
		media += idades[i];
		system("cls");
	}
	
	int maiorIdade = idades[0];
	
	for (int i = 0; i < 100; i ++) { //Pega a maior idade
		if (idades[i] > maiorIdade) {
			maiorIdade = idades[i];
		}
	}
	
	printf("A media das idades das pessoas e de %.1f anos\n", media/100); //Termina o calculo da media e printa o resultado
	printf("A maior idade e de %i anos\n", maiorIdade); //Printa a maior idade
	
	for (int i = 0; i < 100; i ++) { //Acha todos os indices com a maior e idade e os printa
		if (idades[i] == maiorIdade) {
			printf("A pessoa de indice %i tem idade igual a %i\n", i, maiorIdade);
		}
	}
}
