//Atividade 8 - Lista 2
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include <stdio.h>
int ordenarPeso(int *peso);
int main() {
    int peso[3], chama;
    printf("Digite o peso da primeira pessoa: ");
    scanf("%d", &peso[0]);
    printf("Digite o peso da segunda pessoa: ");
    scanf("%d", &peso[1]);
    printf("Digite o peso da terceira pessoa: ");
    scanf("%d", &peso[2]);
    chama = ordenarPeso(peso);
    return 0;
}
int ordenarPeso(int *peso){
    int a;
    for (int i = 0; i < 3; i++){
        for (int j = i + 1; j < 3; j++){
            if (peso[i] > peso[j]){
                a =  peso[i];
                peso[i] = peso[j];
                peso[j] = a;
            }
        }
    }
    printf("Os pesos em ordem crescente sao:\n%d %d %d", peso[0], peso[1], peso[2]);
}