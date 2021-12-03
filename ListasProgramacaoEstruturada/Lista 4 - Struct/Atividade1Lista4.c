//Atividade 1 - Lista 4
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>

struct registro {
    char nome[30];
    char endereco[100];
    int telefone;
};
void main(){
    struct registro usuario[3];

    for(int i = 0; i < 3; i++){
        printf("Digite o nome da pessoa %d: ", i+1);
        fgets(usuario[i].nome,30,stdin);
        printf("Digite o endereco da pessoa %d: ", i+1);
        fgets(usuario[i].endereco,100,stdin);
        printf("Digite o telefone da pessoa %d: ", i+1);
        scanf("%d", &usuario[i].telefone);
        getchar();
    }

    system("cls");
    for(int i = 0; i < 3; i++){
        printf("Nome: %sEndereco: %sTeleforne: %d\n\n\n", usuario[i].nome, usuario[i].endereco, usuario[i].telefone);
        
    }

}