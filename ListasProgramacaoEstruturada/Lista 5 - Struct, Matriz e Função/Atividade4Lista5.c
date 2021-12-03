//Atividade 4 - Lista 5
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct dieta {
    char nome[50];
    double peso, calorias;
};

struct dieta dietas[2];

void buscarDados(void);
void listarDados(void);
void cadastrar(void);

int numDieta = 0;

int main() {
    int opcao;

    printf("O que deseja fazer?\n1- Cadastrar uma nova dieta\n2- Buscar uma dieta\n3- Listar dietas\n");
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
    if (numDieta == sizeof(dietas)) {
        printf("Erro ao adicionar, numero de dietas no maximo");
        main();
    }

    printf("Insira o nome da comida: ");
    fgets(dietas[numDieta].nome, 50, stdin);
    fflush(stdin);
    system("cls");

    printf("Insira o peso da comida: ");
    scanf("%lf", &dietas[numDieta].peso);
    fflush(stdin);
    system("cls");

    printf("Insira as calorias da comida: ");
    scanf("%lf", &dietas[numDieta].calorias);
    fflush(stdin);
    system("cls");

    numDieta ++;
    main();
}

void listarDados(void) {
    for (int i = 0; i < numDieta; i ++) {
        printf("Nome: %s", dietas[i].nome);
        printf("Peso: %.1lf\n", dietas[i].peso);
        printf("Calorias: %.0lf\n\n", dietas[i].calorias);
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void buscarDados(void) {
    char entrada[50];
    printf("Insira o nome da dieta para buscar: ");
    fgets(entrada, 50, stdin);
    system("cls");
    
    for (int i = 0; i < numDieta; i ++) {
        if (stricmp(entrada, dietas[i].nome) == 0) {
            printf("Nome: %s", dietas[i].nome);
            printf("Peso: %.1lf\n", dietas[i].peso);
            printf("Calorias: %.0lf\n\n", dietas[i].calorias);
            break;
        }
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}