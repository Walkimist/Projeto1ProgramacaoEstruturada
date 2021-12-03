//Atividade 4 - Lista 4
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>

void armazenarDados(void);
void mostrarDados(void);

struct carro{
    char marca[16],modelo[20],cor[16],motorizacao[20];
    int quantPortas;
};

struct carro registro[10];

int main(){
    int menu;

    printf("O que deseja fazer?\n1-Armazenar dados dos veiculos\n2-Mostrar dados armazenados\n");
    scanf("%d", &menu);

    switch(menu){
        case 1:
            armazenarDados();
        break;
        
        case 2:
            mostrarDados();
        break;
    }

    return 0;
}

void armazenarDados(){
    for(int i = 0; i < 10; i++){
        system("cls");
        getchar();
        printf("Digite a marca do carro %d: ", i+1);
        fgets(registro[i].marca,16,stdin);
        printf("Digite o modelo do carro %d: ", i+1);
        fgets(registro[i].modelo,20,stdin);
        printf("Digite a cor do carro %d: ", i+1);
        fgets(registro[i].cor,16,stdin);
        printf("Digite a quantidade de portas do carro %d: ", i+1);
        scanf("%d", &registro[i].quantPortas);
        getchar();
        printf("Digite a motorizacao do carro %d: ", i+1);
        fgets(registro[i].motorizacao,20,stdin);
    }
    system("cls");
    main();
}

void mostrarDados(void){
    system("cls");
    for(int i = 0; i < 10; i++){
        printf("Marca do carro %d: %s", i+1, registro[i].marca);
        printf("Modelo do carro %d: %s", i+1, registro[i].modelo);
        printf("Cor do carro %d: %s", i+1, registro[i].cor);
        printf("Quantidade de portas do carro %d: %d\n", i+1, registro[i].quantPortas);
        printf("Motorizacao do carro %d: %s\n", i+1, registro[i].motorizacao);
    }
}