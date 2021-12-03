//Atividade 5 - Lista 2
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include <stdio.h>
#include <stdlib.h>
int obterClassificacao(int populacao);
int escreveClassificacao(int classificacao, char nome[64]);
int main(){
    char continuar;
    char nome[64];
    int populacao, classificacao, escreve;

    while(true){
        printf("Qual o nome da Organizacao populacional: ");
        scanf("%s", nome);
        while(true){
            printf("Qual a populacao da Organizacao populacional: ");
            scanf("%d", &populacao);
            if(populacao < 1){
                printf("Numero invalido, digite novamente.\n");
            }else break;
        }
        classificacao = obterClassificacao(populacao);
        escreve = escreveClassificacao(classificacao, nome);
        fflush(stdin);
        while(true){
            printf("\nDeseja continuar (s ou n)? ");
            scanf("%c", &continuar);
            fflush(stdin);
            if(continuar != 's' and continuar != 'n'){
                printf("Opcao invalida, tente novamente.\n");
            }else if(continuar == 'n'){
                return 0;
            }else{
                system("cls");   
                break;
            }
        }
    }
    
}
int obterClassificacao(int populacao){
    int classificacao;
    if(populacao > 1000001){
        classificacao = 4;
    }else if(populacao >= 15001){
        classificacao = 3;
    }else if(populacao >= 5001){
        classificacao = 2;
    }else classificacao = 1;
    return classificacao;
}
int escreveClassificacao(int classificacao, char nome[64]){
    printf("Nome: %s\n", nome);
    printf("Classificacao: ");
    switch(classificacao){
        case 1: printf("Vila"); break;
        case 2: printf("Distrito"); break;
        case 3: printf("Cidade"); break;
        case 4: printf("Metropole"); break;
    }
}