//Atividade 4 - Lista 6
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>

void checarMaiorElemento(int *numeros, int tamanho);

int main() {
    int tamanho;
    printf("Insira o tamanho do vetor: ");
    scanf("%i", &tamanho);

    int valores[tamanho];

    for (int i = 0; i < tamanho; i++) {
        printf("Insira o valor %i: ", i+1);
        scanf("%i", &valores[i]);
        system("cls");
    }
    checarMaiorElemento(valores, tamanho);
}

void checarMaiorElemento(int *numeros, int tamanho) {
    int quantidade = 0, maiorNumero = numeros[0], i;
    for (i = 0; i < tamanho; i ++) {
        if (numeros[i] > maiorNumero) {
            maiorNumero = numeros[i];
        }
    }
    for (i = 0; i < tamanho; i ++) {
        if (numeros[i] == maiorNumero) {
            quantidade ++;
        }
    }
    printf("O numero %i apareceu %i vezes", maiorNumero, quantidade);
}
