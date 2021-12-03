//Atividade 7 - Lista 1
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include<stdio.h>
#include<stdlib.h>

double precoCDs[100];

void aumentarPrecosFixo();
void aumentarPrecosVariavel(double percentualAumento);

int main() {
	for (int i = 0; i < 100; i ++) { //Pegar precos de cds
		printf("Insira o preco do CD %i: ", i+1);
		scanf("%lf", &precoCDs[i]);
		system("cls");
	}
	
	int opcao;
	printf("Escolha o que deseja fazer:\n\n1.Aumentar precos em 10%%\n2.Aumentar precos em x%%\n3.Sair\n\n"); //Escolha de aumentar em 10% ou outro valor
	scanf("%i", &opcao);
	system("cls");
	
	double percentual;
	switch (opcao) {
		case 1: aumentarPrecosFixo(); break; //Aumentar em 10%
		case 2: //Aumentar em x%
			printf("Insira por quanto quer aumentar os precos (percentual): ");
			scanf("%lf", &percentual);
			system("cls");
			aumentarPrecosVariavel(percentual);
		break;
		default: return 0; break;
	}
	
	for (int i = 0; i < 100; i ++) { //Printar os precos antes e depois do aumento
		if (opcao == 1) {
			printf("O CD %i valia R$%.2lf, agora com aumento de 10%%, vale R$%.2lf.\n", i+1, precoCDs[i]/1.1, precoCDs[i]);
		} else {
			printf("O CD %i valia R$%.2lf, agora com aumento de %.0lf%%, vale R$%.2lf.\n", i+1, precoCDs[i]/(1 + (percentual/100)), percentual, precoCDs[i]);
		}
	}
}

void aumentarPrecosFixo() {
	for (int i = 0; i < 100; i ++) {
		precoCDs[i] *= 1.1;
	}
}

void aumentarPrecosVariavel(double percentualAumento) {
	for (int i = 0; i < 100; i ++) {
		precoCDs[i] *= (1 + (percentualAumento/100));
	}
}
