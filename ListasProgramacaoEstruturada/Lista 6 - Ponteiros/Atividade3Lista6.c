//Atividade 3 - Lista 6
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>

void checarPar(int *numeros);

int main() {
    int valores[5];
    for (int i = 0; i < 5; i++) {
        printf("Insira o valor %i: ", i+1);
        scanf("%i", &valores[i]);
        system("cls");
    }
    checarPar(valores);
}

void checarPar(int *numeros) {
    for (int i = 0; i < 5; i ++) {
        if (numeros[i] % 2 == 0) {
            printf("Numero %i: %i, endereco %i\n", i+1, numeros[i], &numeros[i]);
        }
    }
}