//Atividade 2 - Lista 7
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct restaurante res;
struct restaurante {
    char nome[50], endereco[50], tipoDeComida[50];
    double preco;
    res *proximo;
} *restaurantes;

res* inicializar();
res* cadastrar(res * restaurantes);
void listar(res * restaurantes);
void buscar(res * restaurantes);

int main() {
    int opcao;
    restaurantes = inicializar();
    do {
        printf("O que deseja fazer?\n1- Cadastrar um novo restaurante\n2- Buscar um restauramte\n3- Listar restaurantes\n");
        scanf("%d", &opcao);
        fflush(stdin);
        system("cls");
        
        switch(opcao){
            case 1: restaurantes = cadastrar(restaurantes); break;
            case 2: buscar(restaurantes); break;
            case 3: listar(restaurantes); break;
        }
    } while (opcao == 1 || opcao == 2 || opcao == 3);
    return 0;
}

res* cadastrar(res * restaurantes) {
    res* novo = (res*) malloc(sizeof(restaurantes)* 50);

    printf("Insira o nome do restaurante: ");
    gets(novo->nome);
    fflush(stdin);
    system("cls");

    printf("Insira o endereco do restaurante: ");
    gets(novo->endereco);
    fflush(stdin);
    system("cls");

    printf("Insira o tipo de comida do restaurante: ");
    gets(novo->tipoDeComida);
    fflush(stdin);
    system("cls");

    printf("Insira o preco medio do restaurante: ");
    scanf("%lf", &novo->preco);
    fflush(stdin);
    system("cls");

    novo->proximo = restaurantes;
    return novo;
}

void listar(res * restaurantes) {
    res* auxiliar;
    for (auxiliar = restaurantes; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        printf("Nome: %s\n", auxiliar->nome);
        printf("Endereco: %s\n", auxiliar->endereco);
        printf("Tipo de Comida: %s\n", auxiliar->tipoDeComida);
        printf("Preco medio: R$%.2lf\n\n", auxiliar->preco);
    }
    printf("Aperte enter para continuar.");
	fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
}

void buscar(res * restaurantes) {
    res *auxiliar;
    char nomeBusca[50];
    printf("Digite o nome do restaurante: ");
    fgets(nomeBusca, 50, stdin);
    fflush(stdin);
    system("cls");

    nomeBusca[strcspn(nomeBusca, "\n")] = 0;

    for (auxiliar = restaurantes; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        if (stricmp(nomeBusca, auxiliar->nome) == 0) {
            printf("Nome: %s\n", auxiliar->nome);
            printf("Endereco: %s\n", auxiliar->endereco);
            printf("Tipo de Comida: %s\n", auxiliar->tipoDeComida);
            printf("Preco medio: R$%.2lf\n\n", auxiliar->preco);
            break;
        }
    }
    printf("Aperte enter para continuar.");
	fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
}

res* inicializar(){
	return NULL; 
}