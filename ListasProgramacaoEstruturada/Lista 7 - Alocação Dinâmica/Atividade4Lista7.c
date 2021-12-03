//Atividade 4 - Lista 7
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct carro car;
struct carro {
    char proprietario[30], combustivel[8], modelo[30], cor[20], placa[8];
    int chassi, ano;
    car *proximo;
} *carros;

car* inicializar();
car* registrarCarros(car * carros);
void listarProprietarios(car * carros);
void listarPlacas(car * carros);
void listarModeloCor(car * carros);
car* trocarProprietario(car * carros);

int main(){
    carros = inicializar();
    int opcao;

    do {
        printf("O que deseja fazer?\n1-Cadastrar novo carro");
        printf("\n2-Listar todos os proprietarios cujos carros sao do ano de 2010 ou posterior e que sejam movidos a diesel");
        printf("\n3-Listar todas as placas que comecem com a letra J e terminem com 0, 2, 4 ou 7 e seus respectivos proprietarios");
        printf("\n4-Listar o modelo e a cor dos veiculos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numericos fornece um numero par.");
        printf("\n5-Trocar o proprietario\n");
        scanf("%d", &opcao);
        fflush(stdin);
        system("cls");

        switch(opcao){
        	case 1: carros = registrarCarros(carros); break;
            case 2: listarProprietarios(carros); break;
            case 3: listarPlacas(carros); break;
            case 4: listarModeloCor(carros); break;
            case 5: carros=trocarProprietario(carros); break;
        }
    } while (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5);
}

car* registrarCarros(car * carros) {
    car* novo = (car*) malloc(sizeof(carros)* 50);
    
    printf("Insira o nome do proprietario do veiculo: ");
    gets(novo->proprietario);
    fflush(stdin);
    system("cls");
    
    printf("Insira o tipo de combustivel do veiculo: ");
    gets(novo->combustivel);
    fflush(stdin);
    system("cls");
    
    printf("Insira o modelo do veiculo: ");
    gets(novo->modelo);
    fflush(stdin);
    system("cls");
    
    printf("Insira a cor do veiculo: ");
    gets(novo->cor);
    fflush(stdin);
    system("cls");
    
    printf("Insira a placa do veiculo");
    gets(novo->placa);
    fflush(stdin);
    system("cls");
    
    printf("Insira o numero do chassi do veiculo: ");
    scanf("%i", &novo->chassi);
    fflush(stdin);
    system("cls");
    
    printf("Insira o ano do veiculo: ");
    scanf("%i", &novo->ano);
    fflush(stdin);
    system("cls");
    
    novo->proximo = carros;
    return novo;
}

void listarProprietarios(car * carros) {
    car *auxiliar;
    for (auxiliar = carros; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        if (auxiliar->ano >= 2010) {
            if (stricmp(auxiliar->combustivel, "Diesel") == 0) {
                printf("Proprietario(a): %s\n\n", auxiliar->proprietario);
            }
        }
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
}

void listarPlacas(car * carros){
    car *auxiliar;
    for (auxiliar = carros; auxiliar != NULL; auxiliar = auxiliar->proximo){
        if(auxiliar->placa[0] == 'J' && (auxiliar->placa[6] == '0' || auxiliar->placa[6] == '2' || auxiliar->placa[6] == '4' || auxiliar->placa[6] == '7')){
            printf("Placa: %s\nProprietario: %s\n\n", auxiliar->placa, auxiliar->proprietario);
        }
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
}

void listarModeloCor(car * carros) {
    car *auxiliar;
    int somaNumeros = 0, j;
    for (auxiliar = carros; auxiliar != NULL; auxiliar = auxiliar->proximo){
        for (j = 3; j < 7; j ++) {
            somaNumeros += (int)auxiliar->placa[j];
        }
        if(auxiliar->placa[1] == 'A' || auxiliar->placa[1] == 'E' || auxiliar->placa[1] == 'I' || auxiliar->placa[1] == 'O' || auxiliar->placa[1] == 'U') {
            if (somaNumeros % 2 == 0) {
                printf("Modelo: %s\nCor: %s\n\n", auxiliar->modelo, auxiliar->cor);
            }
        }
        somaNumeros = 0;
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
}

car* trocarProprietario(car * carros){
    car *auxiliar;
    int opcao;
    printf("Insira o numero do chassis para troca de proprietario: ");
    scanf("%i", &opcao);
    fflush(stdin); 

    for (auxiliar = carros; auxiliar != NULL; auxiliar = auxiliar->proximo) {
        if (auxiliar->chassi == opcao && auxiliar->placa[3] != '0' && auxiliar->placa[4] != '0' && auxiliar->placa[5] != '0' && auxiliar->placa[6] != '0') {
            printf("Carro encontrado, insira o nome do proprietario: ");
            gets(auxiliar->proprietario);
            break;
        }
    }
    system("cls");
    auxiliar = carros;
    return auxiliar;
}

car* inicializar(){
	return NULL; 
}