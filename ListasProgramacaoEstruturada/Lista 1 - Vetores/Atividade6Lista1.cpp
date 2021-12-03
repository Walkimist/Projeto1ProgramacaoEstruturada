//Atividade 6 - Lista 1
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include<stdio.h>
#include<stdlib.h>

double salarioFuncionario[4];
int matriculaFuncionario[4];

double obterMaiorSalario();
double obterMenorSalario();

int main() {
	for(int i = 0; i < 4; i ++) { //Pega as informacoes dos funcionarios
		printf("Insira a matricula do funcionario %i (apenas numeros): ", i+1);
		scanf("%i", &matriculaFuncionario[i]);
		printf("Insira o salario do funcionario %i: ", i+1);
		scanf("%lf", &salarioFuncionario[i]);
		system("cls");
	}
	
	//Printa o menor e maior salario
	printf("O maior salario de todos os funcionarios e: R$%.2lf\n", obterMaiorSalario());
	printf("O menor salario de todos os funcionarios e: R$%.2lf\n\n", obterMenorSalario());
	
	for (int i = 0; i < 4; i ++) { //Printa o resto das informacoes
		printf("Salario do funcionario de matricula %i e de R$%.2lf\n", matriculaFuncionario[i], salarioFuncionario[i]);
	}
}

double obterMaiorSalario() { //Determina o maior salario
	double maiorSalario = salarioFuncionario[0];
	for (int i = 0; i < 4; i ++) {
		if (salarioFuncionario[i] > maiorSalario) {
			maiorSalario = salarioFuncionario[i];	
		}
	}
	return maiorSalario;
}

double obterMenorSalario() { //Determina o menor salario
	double menorSalario = salarioFuncionario[0];
	for (int i = 1; i < 4; i ++) {
		if (salarioFuncionario[i] < menorSalario) {
			menorSalario = salarioFuncionario[i];	
		}
	}
	return menorSalario;
}
