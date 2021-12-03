//Atividade 10 - Lista 2
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
float calculaMedia(float nota1, float nota2);
int verificaAprovacao(float media);
int main(){
    char nome[32];
    float nota1,nota2,media;
    int aprovacao;

    printf("Digite a nota da prova teorica: ");
    scanf("%f", &nota1);
    printf("Digite a nota da prova pratica: ");
    scanf("%f", &nota2);

    media = calculaMedia(nota1, nota2);
    printf("Media final: %.2f\n", media);
    aprovacao = verificaAprovacao(media);


    return 0;
}
float calculaMedia(float nota1, float nota2){
    return (nota1*3 + nota2*7)/10;
}
int verificaAprovacao(float media){
    if(media > 7){
        printf("Estado: Aprovado");
    }else printf("Estado: Reprovado");
}