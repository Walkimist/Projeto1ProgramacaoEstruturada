//Atividade 5 - Lista 6
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>

int main() {
    int vetor[5], i;
    int *ponteiro;

    ponteiro = &vetor[5];

    for (i = 0; i < 5; i++) {
        printf("Insira o valor %i: ", i+1);
        scanf("%i", &vetor[i]);
        system("cls");
    }

    printf("Vetor antes de somar um em cada posicao:\n");
    for (i = 0; i < 5; i ++) {
        printf("%i  ", vetor[i]);
    }

    for (ponteiro = vetor; ponteiro < vetor + 5; ponteiro ++) {
        *ponteiro += 1;
    }

    printf("\n\nVetor depois de somar 1 em cada posicao:\n");
    for (ponteiro = vetor; ponteiro < vetor + 5; ponteiro ++) {
        printf("%i  ", *ponteiro);
    }
}