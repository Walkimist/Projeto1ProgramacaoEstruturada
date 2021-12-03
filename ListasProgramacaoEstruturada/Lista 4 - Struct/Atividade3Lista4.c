//Atividade 3 - Lista 4
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
//Para definir um tipo de ESTRUTURA que contenha 2 elementos, uma “STRING” de 10 caracteres e um INTEIRO
//é necessário criar um struct contendo uma string de 10 caracteres e um numero inteiro e depois, dentro da
//main, requisitá-los ao usuario
#include<stdio.h>

struct estrutura{
    char string[10];
    int inteiro;
};
void main(){
    struct estrutura dados;

    printf("Digite a string: ");
    fgets(dados.string,10,stdin);
    printf("Digite o numero inteiro: ");
    scanf("%d", &dados.inteiro);
    getchar();

}