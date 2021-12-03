//Atividade 2 - Lista 3
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<string.h>

void main(){
    char equipamento[32][5];

    for(int i = 0; i < 5; i++){
        printf("Digite o equipamento %d: ", i+1);
        scanf("%s", &equipamento[i]);
    }
    for(int i = 0; i < 5; i++){
        
        for(int j = 0; j < 5; j++){
            if(strcmp(equipamento[i], equipamento[j]) == 0 && i > j){
                printf("%s repete\n", equipamento[i]);
            }
        }
    }
}