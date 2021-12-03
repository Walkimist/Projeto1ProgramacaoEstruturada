//Atividade 5 - Lista 5
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct carro {
    char proprietario[30], combustivel[8], modelo[30], cor[20], placa[8];
    int chassi, ano
};

struct carro carros[3];
int a = 0;

void registrarCarros(void);
void listarProprietarios(void);
void listarPlacas(void);
void listarModeloCor(void);
void trocarProprietario(void);

int main(){
    if (a == 0) registrarCarros();
    int opcao;
    printf("O que deseja fazer?\n1-Listar todos os proprietarios cujos carros sao do ano de 2010 ou posterior e que sejam movidos a diesel");
    printf("\n2-Listar todas as placas que comecem com a letra J e terminem com 0, 2, 4 ou 7 e seus respectivos proprietarios");
    printf("\n3-Listar o modelo e a cor dos veiculos cujas placas possuem como segunda letra uma vogal e cuja soma dos valores numericos fornece um numero par.");
    printf("\n4-Trocar o proprietario\n");
    scanf("%d", &opcao);
    fflush(stdin);
    system("cls");

    switch(opcao){
        case 1: listarProprietarios(); break;
        case 2: listarPlacas(); break;
        case 3: listarModeloCor(); break;
        case 4: trocarProprietario(); break;
    }
}

void registrarCarros(void) {
    strcpy(carros[0].proprietario, "Jorge");
    strcpy(carros[0].combustivel, "Alcool");
    strcpy(carros[0].modelo, "Fiat Uno");
    strcpy(carros[0].cor, "Preto");
    strcpy(carros[0].placa, "JOR6333");
    carros[0].chassi = 13;
    carros[0].ano = 2015;

    strcpy(carros[1].proprietario, "Abner");
    strcpy(carros[1].combustivel, "Diesel");
    strcpy(carros[1].modelo, "Fiat Dos");
    strcpy(carros[1].cor, "Branco");
    strcpy(carros[1].placa, "ABN3728");
    carros[1].chassi = 7;
    carros[1].ano = 2019;

    strcpy(carros[2].proprietario, "Amelia");
    strcpy(carros[2].combustivel, "Gasolina");
    strcpy(carros[2].modelo, "Fiat Tres");
    strcpy(carros[2].cor, "Cinza");
    strcpy(carros[2].placa, "JEE3337");
    carros[2].chassi = 77;
    carros[2].ano = 1970;
    
    a++;
    return NULL;
}

void listarProprietarios(void) {
    for (int i = 0; i < 3; i ++) {
        if (carros[i].ano >= 2010) {
            if (stricmp(carros[i].combustivel, "Diesel") == 0) {
                printf("Proprietario(a): %s", carros[i].proprietario);
            }
        }
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void listarPlacas(void){
    for (int i = 0; i < 3; i++){
        if(carros[i].placa[0] == 'J' && carros[i].placa[6] == '0' || carros[i].placa[6] == '2' || carros[i].placa[6] == '4' || carros[i].placa[6] == '7'){
            printf("Placa: %s\nProprietario: %s\n\n", carros[i].placa, carros[i].proprietario);
        }
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void listarModeloCor(void) {
    int somaNumeros = 0;
    for (int i = 0; i < 3; i++){
        for (int j = 3; j < 7; j ++) {
            somaNumeros += (int)carros[i].placa[j];
        }
        if(carros[i].placa[1] == 'A' || carros[i].placa[1] == 'E' || carros[i].placa[1] == 'I' || carros[i].placa[1] == 'O' || carros[i].placa[1] == 'U') {
            if (somaNumeros % 2 == 0) {
                printf("Modelo: %s\nCor: %s\n\n", carros[i].modelo, carros[i].cor);
            }
        }
        somaNumeros = 0;
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void trocarProprietario(void){
    int opcao;
    printf("Insira o numero do chassis para troca de proprietario: ");
    scanf("%i", &opcao);
    fflush(stdin); 

    for (int i = 0; i < 3; i ++) {
        if (carros[i].chassi == opcao && carros[i].placa[3] != '0' && carros[i].placa[4] != '0' && carros[i].placa[5] != '0' && carros[i].placa[6] != '0') {
            printf("Carro encontrado, insira o nome do proprietario: ");
            fgets(carros[i].proprietario, 30, stdin);
            break;
        }
    }
    system("cls");
    main();
}