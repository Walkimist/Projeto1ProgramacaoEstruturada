//Atividade 3 - Lista 7
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct dieta die;
struct dieta {
    char nome[50];
    double peso, calorias;
    die *proximo;
} *dietas;

die* inicializar();
die* cadastrar(die * dietas);
void listar(die * dietas);
void buscar(die * dietas);

int main() {
    int opcao;
    dietas = inicializar();
    do {
        printf("O que deseja fazer?\n1- Cadastrar uma nova dieta\n2- Buscar uma dieta\n3- Listar dietas\n");
        scanf("%d", &opcao);
        fflush(stdin);
        system("cls");
        
        switch(opcao){
            case 1: dietas = cadastrar(dietas); break;
            case 2: buscar(dietas); break;
            case 3: listar(dietas); break;
        }
    } while (opcao == 1 || opcao == 2 || opcao == 3);
    return 0;
}

die* cadastrar(die * dietas) {
    die* novo = (die*) malloc(sizeof(dietas)* 50);

    printf("Insira o nome da comida: ");
    gets(novo->nome);
    fflush(stdin);
    system("cls");

    printf("Insira as calorias da comida: ");
    scanf("%lf", &novo->calorias);
    fflush(stdin);
    system("cls");

    printf("Insira o peso da comida: ");
    scanf("%lf", &novo->peso);
    fflush(stdin);
    system("cls");

    novo->proximo = dietas;
    return novo;
}

void listar(die * dietas) {
    die* auxiliar;
    for (auxiliar = dietas; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        printf("Nome: %s\n", auxiliar->nome);
        printf("Calorias: %.0lf\n", auxiliar->calorias);
        printf("Peso: %.1lf\n\n", auxiliar->peso);
    }
    printf("Aperte enter para continuar.");
	fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
}

void buscar(die * dietas) {
    die *auxiliar;
    char nomeBusca[50];
    printf("Digite o nome da dieta: ");
    fgets(nomeBusca, 50, stdin);
    fflush(stdin);
    system("cls");

    nomeBusca[strcspn(nomeBusca, "\n")] = 0;

    for (auxiliar = dietas; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        if (stricmp(nomeBusca, auxiliar->nome) == 0) {
            printf("Nome: %s\n", auxiliar->nome);
            printf("Calorias: %.0lf\n", auxiliar->calorias);
            printf("Peso: %.1lf\n\n", auxiliar->peso);
            break;
        }
    }
    printf("Aperte enter para continuar.");
	fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
}

die* inicializar(){
	return NULL; 
}