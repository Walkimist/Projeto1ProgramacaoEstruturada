//Atividade 1 - Lista 3
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812

#include <stdio.h>
void main()
{
    char nome1[32], nome2[32];
    int tamanhoNome;
    printf("Digite o primeiro nome: ");
    scanf("%s", nome1);
    tamanhoNome = strlen(nome1);
    for(int i = 0; i < tamanhoNome; i++){
        nome1[i] = toupper(nome1[i]);
    }
    
    printf("Digite o segundo nome: ");
    scanf("%s", nome2);
    tamanhoNome = strlen(nome2);
    for(int i = 0; i < tamanhoNome; i++){
        nome2[i] = tolower(nome2[i]);
    }
    
    printf("%s\n", nome1);
    printf("%s", nome2);
}