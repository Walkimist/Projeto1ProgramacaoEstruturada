//Atividade 6 - Lista 3
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char nome[30], opcao[3];
    int tamanho, i;
    do{
        printf("Digite o nome: ");
        fgets(nome,30,stdin);
        tamanho = strlen(nome);
        for(i = 0; i < strlen(nome); i++){
            nome[i] = toupper(nome[i]);
            if(nome[i] == ' '){
                tamanho--;
            }
        }
        system("cls");
        printf("%s\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n", nome);
        printf("Quantidade de caracteres: %d\n\n", tamanho);
        printf("Deseja escrever outro nome(sim ou nao)? ");
        scanf("%s", opcao);
        getchar();
        system("cls");
        if(stricmp(opcao,"nao") == 0){
            system("exit");
        }
    }while(stricmp(opcao,"nao") != 0);

}