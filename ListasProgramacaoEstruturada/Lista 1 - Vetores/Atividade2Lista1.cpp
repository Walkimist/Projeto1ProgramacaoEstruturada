//Atividade 2 - Lista 1
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include<stdio.h>
#include<stdlib.h>

int main() {
	int quantAlunos;
	
	do { //Pega a quantidade de alunos e checa se está entre 1 e 49
		printf("Insira a quantidade de alunos (devem haver menos de 50):\n");
		scanf("%i", &quantAlunos);
		system("cls");
	} while (quantAlunos <= 0 || quantAlunos >= 50);
	
	double notas[quantAlunos];
	
	for (int i = 0; i < quantAlunos; i ++) { //Pegar as notas
		printf("Insira a nota do aluno(a) %i: ", i+1);
		scanf("%lf", &notas[i]);
		system("cls");
	}
	for (int i = 0; i < quantAlunos; i ++) { //Printar as notas
		printf("Nota do aluno(a) %i: %.1lf", i+1, notas[i]);
		printf("\n");
	}
}
