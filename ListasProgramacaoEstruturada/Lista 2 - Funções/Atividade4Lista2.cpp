//Atividade 4 - Lista 2
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include <stdio.h>
#include <stdlib.h>
int apresentaClassificacao(int anoNascimento,int anoAtual);
int obtemNivel(int idade);

int main(){
    int anoNascimento, anoAtual, idade, classificacao;
    while(true){
        printf("Digite seu ano de nascimento: ");
        scanf("%d", &anoNascimento);
        printf("Digite o ano atual: ");
        scanf("%d", &anoAtual);
        system("cls");
        if(anoNascimento > anoAtual){
            printf("Alguma data esta errada, digite novamente.\n");
        } else break;
    }
    idade = apresentaClassificacao(anoNascimento, anoAtual);
    classificacao = obtemNivel(idade);
    printf("Sua provavel idade: %d\nSua classificacao: ", idade);
    switch(classificacao){
        case 1: printf("Crianca"); break;
        case 2: printf("Adolescente"); break;
        case 3: printf("Jovem"); break;
        case 4: printf("Adulto"); break;
        case 5: printf("Idoso"); break;
    }
    return 0;
}
int apresentaClassificacao(int anoNascimento,int anoAtual){
    int idade;
    return idade = anoAtual - anoNascimento;
}
int obtemNivel(int idade){
    int classificacao;
    if(idade > 58){
        classificacao = 5;
    }else if(idade >= 25){
        classificacao = 4;
    }else if(idade >= 18){
        classificacao = 3;
    }else if(idade >= 10){
        classificacao = 2;
    }else classificacao = 1;
    return classificacao;
}