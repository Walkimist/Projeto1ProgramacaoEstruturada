//Atividade 9 - Lista 1
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include<stdio.h>
#include<stdlib.h>

int matriculaEmpregado[50];
int mesesEmpregado[50];

void ordenarMeses(int tamanho);

int main() {
	
	int n = 0; //Iteracao do while
	do {
		printf("Insira a matricula do empregado %i (0 para finalizar): ", n+1);
		scanf("%i", &matriculaEmpregado[n]);
		if (matriculaEmpregado[n] != 0) {
			printf("Insira o tempo em meses que o empregado %i esta na empresa: ", n+1);
			scanf("%i", &mesesEmpregado[n]);
			n ++;
		}
		system("cls");
	} while(matriculaEmpregado[n] != 0 && n < 50); //Finaliza a leitura quando 0 é inserido ou o limite é alcançado
	
	ordenarMeses(n); //Ordena os vetores
	
	for (int i = 0; i < 3; i ++) { //Printa os 3 empregados mais recentes
		printf("O empregado de matricula %i tem %i meses de contrato\n", matriculaEmpregado[i], mesesEmpregado[i]);
	}
}

void ordenarMeses(int tamanho) { //Bubble sort
	int auxiliar;
	for (int i = 0; i < tamanho; i ++) {
		for (int j = 0; j < tamanho-1; j ++) {
			if (mesesEmpregado[j] > mesesEmpregado[j+1]) {
				auxiliar = mesesEmpregado[j];
				mesesEmpregado[j] = mesesEmpregado[j+1];
				mesesEmpregado[j+1] = auxiliar;
				
				auxiliar = matriculaEmpregado[j];
				matriculaEmpregado[j] = matriculaEmpregado[j+1];
				matriculaEmpregado[j+1] = auxiliar;
			}
		}
	}
}
