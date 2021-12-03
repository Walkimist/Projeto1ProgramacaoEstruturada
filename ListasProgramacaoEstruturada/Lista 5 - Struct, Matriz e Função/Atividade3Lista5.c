//Atividade 3 - Lista 5
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct restaurante {
    char nome[50], endereco[50], tipoDeComida[50];
    double preco;
};

struct restaurante restaurantes[20];

void buscarDados(void);
void listarDados(void);
void cadastrar(void);

int numRestaurante = 0;

int main() {
    int opcao;

    printf("O que deseja fazer?\n1- Cadastrar um novo restaurante\n2- Buscar um restauramte\n3- Listar restaurantes\n");
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");
    
    switch(opcao){
        case 1: cadastrar(); break;
        case 2: buscarDados(); break;
        case 3: listarDados(); break;
        default: break;
    }
}

void cadastrar(void) {
    if (numRestaurante == sizeof(restaurantes)) {
        printf("Erro ao adicionar, numero de restaurantes no maximo");
        main();
    }

    printf("Insira o nome do restaurante: ");
    fgets(restaurantes[numRestaurante].nome, 50, stdin);
    fflush(stdin);
    system("cls");

    printf("Insira o endereco do restaurante: ");
    fgets(restaurantes[numRestaurante].endereco, 50, stdin);
    fflush(stdin);
    system("cls");

    printf("Insira o tipo de comida do restaurante: ");
    fgets(restaurantes[numRestaurante].tipoDeComida, 50, stdin);
    fflush(stdin);
    system("cls");

    printf("Insira o preco medio do restaurante: ");
    scanf("%lf", &restaurantes[numRestaurante].preco);
    fflush(stdin);
    system("cls");

    numRestaurante ++;
    main();
}

void listarDados(void) {
    for (int i = 0; i < numRestaurante; i ++) {
        printf("Nome: %s", restaurantes[i].nome);
        printf("Endereco: %s", restaurantes[i].endereco);
        printf("Tipo de Comida: %s", restaurantes[i].tipoDeComida);
        printf("Preco medio: R$%.2lf\n\n\n", restaurantes[i].preco);
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void buscarDados(void) {
    char entrada[50];
    printf("Insira o nome do restaurante para buscar: ");
    fgets(entrada, 50, stdin);
    system("cls");
    
    for (int i = 0; i < numRestaurante; i ++) {
        if (stricmp(entrada, restaurantes[i].nome) == 0) {
            printf("Nome: %s", restaurantes[i].nome);
            printf("Endereco: %s", restaurantes[i].endereco);
            printf("Tipo de Comida: %s", restaurantes[i].tipoDeComida);
            printf("Preco medio: R$%.2lf\n\n", restaurantes[i].preco);
            break;
        }
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}