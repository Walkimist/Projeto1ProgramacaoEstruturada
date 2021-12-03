//Atividade 2 - Lista 6
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>

void ordenar(int *numeros);

int main() {
    int valores[3];
    for (int i = 0; i < 3; i++) {
        printf("Insira o valor %i: ", i+1);
        scanf("%i", &valores[i]);
        system("cls");
    }
    ordenar(valores);
}

void ordenar(int *numeros) {
    int auxiliar, i;
    for (i = 0; i < 3; i ++) {
        for (int j = 0; j < 3-1; j++) {
            if (numeros[j] > numeros[j+1]) {
                auxiliar = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = auxiliar;
            }
        }
    }
    for (i = 0; i < 3; i ++) {
        printf("Numero %i: %i\n", i+1, numeros[i]);
    }
}