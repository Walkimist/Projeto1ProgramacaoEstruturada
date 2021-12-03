//Atividade 1 - Lista 1
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include<stdio.h>
#include<stdlib.h>

int main() {
	double notas[30];
	
	for (int i = 0; i < 30; i ++) { //Pegar as notas
		printf("Insira a nota do aluno(a) %i: ", i+1);
		scanf("%lf", &notas[i]);
		system("cls");
	}
	for (int i = 0; i < 30; i ++) { //Printar as notas
		rintf("Nota do aluno(a) %i: %.1lf", i+1, notas[i]);
		printf("\n");
	}
}
