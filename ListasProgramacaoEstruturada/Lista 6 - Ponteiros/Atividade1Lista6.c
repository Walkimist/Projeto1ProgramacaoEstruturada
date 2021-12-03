//Atividade 1 - Lista 6
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>

int valores[3];

int main() {
    int i;
    for (i = 0; i < 3; i++) {
        printf("Insira o valor %i: ", i+1);
        scanf("%i", &valores[i]);
    }
    for (i = 0; i < 3; i ++) {
        printf("Valor %i: %i\n", i+1, &valores[i]);
    }
}