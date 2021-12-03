//Atividade 2 - Lista 4
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>

struct dadosAluno {
    char nome[30];
    int idade;
};
void main(){
    struct dadosAluno dadosAluno;

        printf("Digite o nome do aluno: ");
        fgets(dadosAluno.nome,30,stdin);
        printf("Digite a idade do aluno: ");
        scanf("%d", &dadosAluno.idade);
        getchar();

    system("cls");
    printf("Nome: %sIdade: %d", dadosAluno.nome, dadosAluno.idade);

}