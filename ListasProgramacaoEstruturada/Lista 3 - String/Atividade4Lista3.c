//Atividade 4 - Lista 3
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main(){
    char texto[1000];
    int tamanhoTexto, quantPalavras = 1;
    
    printf("Digite o seu texto:\n");
    fgets(texto, sizeof(texto), stdin);
    tamanhoTexto = strlen(texto);
    system("cls");
    texto[0] = toupper(texto[0]);
    for(int i = 0; i < tamanhoTexto; i++){
        if(texto[i] == ' '){
            quantPalavras++;
            texto[i+1] = toupper(texto[i+1]);
        } else{
            texto[i+1] = tolower(texto[i+1]);
        }
    }
    printf("%s", texto);
    printf("Esse texto possui %d palavras.", quantPalavras);

}