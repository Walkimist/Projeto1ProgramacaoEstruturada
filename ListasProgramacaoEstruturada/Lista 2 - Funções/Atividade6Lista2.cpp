//Atividade 6 - Lista 2
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include <stdio.h>
#include <stdlib.h>
int apresentaPorcentagem(float porAprovados, float porReprovados);
int main(){
    int apresenta;
    float quantAlunos, quantAprovados, quantReprovados, porAprovados, porReprovados;

    while(true){
        printf("Digite a quantidade de alunos: ");
        scanf("%d", &quantAlunos);
        printf("Digite a quantidade de alunos aprovados: ");
        scanf("%d", &quantAprovados);
        printf("Digite a quantidade de alunos reprovados: ");
        scanf("%d", &quantReprovados);
        if(quantAprovados + quantReprovados > quantAlunos or quantAprovados + quantReprovados < quantAlunos){
            system("cls");
            printf("Algum numero foi digitado errado, tente novamente.\n");
        }else break;
    }
    porAprovados = quantAprovados/quantAlunos;
    porReprovados = quantReprovados/quantAlunos;
    apresenta = apresentaPorcentagem(porAprovados, porReprovados);
    return 0;
}
int apresentaPorcentagem(float porAprovados, float porReprovados){
    printf("Porcentagem de alunos aprovados: %.2f\n", porAprovados*100);
    printf("Porcentagem de alunos reprovados: %.2f", porReprovados*100);
    return 0;
}