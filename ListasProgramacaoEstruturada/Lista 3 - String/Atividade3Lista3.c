//Atividade 3 - Lista 3
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<string.h>

void main(){
    char nome[32][5],sobrenome[32][5];
    int tamanhoNome, tamanhoSobrenome;
    for(int i = 0; i < 5; i++){
        printf("Digite o nome da pessoa %d: ", i+1);
        scanf("%s", nome[i]);
        printf("Digite o sobrenome da pessoa %d: ", i+1);
        scanf("%s", sobrenome[i]);
        tamanhoNome = strlen(nome[i]);
        tamanhoSobrenome = strlen(sobrenome[i]);
        strcat(nome[i], sobrenome[i]);
        printf("Quantidade de letras no nome: %d\n", tamanhoNome);
        printf("Quantidade de letras no sobrenome: %d\n", tamanhoSobrenome);
        printf("Nome completo: %s\n", nome[i]);
    }
}