//Atividade 7 - Lista 2
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
int calculo(int n1,int n2,int n3);
int descobreParImpar(int resposta);
int main(){
    int n1,n2,n3,resposta,parImpar;

    printf("Digite o primeiro numero: ");
    scanf("%d", &n1);
    printf("Digite o segundo numero: ");
    scanf("%d", &n2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &n3);

    resposta = calculo(n1,n2,n3);
    parImpar = descobreParImpar(resposta);

    printf("Resposta: %d", resposta);
    if(parImpar == 0){
        printf("\nO numero e par.");
    }else{
        printf("\nO numero e impar.");
    }

    return 0;
}
int calculo(int n1,int n2,int n3){
    return n1 + n2 * n3;
}
int descobreParImpar(int resposta){
    if(resposta % 2 == 0){
        return 0;
    }else return 1;
}