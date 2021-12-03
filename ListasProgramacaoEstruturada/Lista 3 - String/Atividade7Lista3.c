//Atividade 7 - Lista 3
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void main(){
    char frase[50], nome[16], doisPontos[30] = ": ";
    printf("Digite a frase:\n");
    fgets(frase,50,stdin);

    printf("Digite o primeiro nome do candidato: ");
    scanf("%s", nome);
    for(int i = 0; i < strlen(nome); i++){
        nome[i] = toupper(nome[i]);
    }
    strcat(nome,doisPontos);
    strcat(nome,frase);

    system("cls");
    printf("\n\n\n\n%s", nome);
    Sleep(10000);
    exit;


}