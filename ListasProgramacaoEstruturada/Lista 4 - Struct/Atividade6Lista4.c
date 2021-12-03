//Atividade 6 - Lista 4
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void cadastrar(void);
void encontrarPessoasComMaiorIdade(void);
void encontrarPessoasDoSexoMasculino(void);
void encontrarPessoasComMaiorSalario(void);
void encontrarPessoaPorRg(void);

struct endereco{
        char rua[20],bairro[20],cidade[20],estado[20];
        int cep;
    };
struct cadastro{
    char nome[20],estadoCivil[20],sexo[13];
    struct endereco moradia;
    int rg,cpf,telefone,idade;
    double salario;
};

struct cadastro cadastros[5];
int menu, cadastroNum = 0;

void main(){

    printf("Qual acao deseja fazer?\n1-Cadastrar\n2-Encontrar pessoa com maior idade\n");
    printf("3-Encontrar pessoas do sexo masculino\n4-Encontrar pessoas com salario maior que 1000\n");
    printf("5-Encontrar uma pessoa por RG\n");
    scanf("%d", &menu);
    system("cls");

    switch (menu){
        case 1:
            cadastrar();
        break;
        case 2:
            encontrarPessoasComMaiorIdade();
        break;
        case 3:
            encontrarPessoasDoSexoMasculino();
        break;
        case 4:
            encontrarPessoasComMaiorSalario();
        break;
        case 5:
            encontrarPessoaPorRg();
        break;
        default:
            return 0;
        break;
    }


}

void cadastrar(void){
    if(cadastroNum == 4){
        printf("Limite de cadastros alcancados.");
        main();
    }

    fflush(stdin);
    printf("Digite o nome da pessoa: ");
    scanf("%s", &cadastros[cadastroNum].nome);
    fflush(stdin);
    system("cls");

    printf("Digite a rua onde voce mora: ");
    fgets(cadastros[cadastroNum].moradia.rua,20,stdin);
    fflush(stdin);
    system("cls");

    printf("Digite o bairro onde voce mora: ");
    fgets(cadastros[cadastroNum].moradia.bairro,20,stdin);
    fflush(stdin);
    system("cls");

    printf("Digite a cidade onde voce mora: ");
    fgets(cadastros[cadastroNum].moradia.cidade,20,stdin);
    fflush(stdin);
    system("cls");

    printf("Digite o Estado onde voce mora: ");
    fgets(cadastros[cadastroNum].moradia.estado,20,stdin);
    fflush(stdin);
    system("cls");

    printf("Digite o seu CEP: ");
    scanf("%d", &cadastros[cadastroNum].moradia.cep);
    fflush(stdin);
    system("cls");

    printf("Digite o seu salario: ");
    scanf("%lf", &cadastros[cadastroNum].salario);
    fflush(stdin);
    system("cls");

    printf("Digite a seu CPF: ");
    scanf("%d", &cadastros[cadastroNum].cpf);
    fflush(stdin);
    system("cls");

    printf("Digite o seu RG: ");
    scanf("%d", &cadastros[cadastroNum].rg);
    fflush(stdin);
    system("cls");

    printf("Digite seu estado civil: ");
    fgets(cadastros[cadastroNum].estadoCivil,20,stdin);
    fflush(stdin);
    system("cls");

    printf("Digite o seu telefone: ");
    scanf("%d", &cadastros[cadastroNum].telefone);
    fflush(stdin);
    system("cls");

    printf("Digite a sua Idade: ");
    scanf("%d", &cadastros[cadastroNum].idade);
    fflush(stdin);
    system("cls");
    
    do{    
        printf("Digite o seu sexo(Masculino, Feminino ou Nao Declarar): ");
        fgets(cadastros[cadastroNum].sexo,13,stdin);
        fflush(stdin);
        system("cls");
    }while(stricmp(cadastros[cadastroNum].sexo,"Masculino\n") &&
           stricmp(cadastros[cadastroNum].sexo,"Feminino\n") &&
           stricmp(cadastros[cadastroNum].sexo,"Nao Declarar\n"));

    system("cls");
    cadastroNum++;
    main();
}

void encontrarPessoasComMaiorIdade() {
    int maiorIdade = 0, i;
    for(i = 0; i < cadastroNum; i++){
        if(maiorIdade < cadastros[i].idade){
            maiorIdade = cadastros[i].idade;
        }    
    }
    for(i = 0; i < cadastroNum; i++){
        if(maiorIdade = cadastros[i].idade){
            printf("%s tem a maior idade.\n", cadastros[i].nome);
        }
    }
    printf("Aperte enter para continuar.");
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void encontrarPessoasDoSexoMasculino() {
    for (int i = 0; i < cadastroNum; i ++) {
        if (stricmp(cadastros[i].sexo, "Masculino\n") == 0) {
            printf("Nome: %s\tSexo: %s\n", cadastros[i].nome, cadastros[i].sexo);
        }
    }
    printf("Aperte enter para continuar.");
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void encontrarPessoasComMaiorSalario() {
    for (int i = 0; i < cadastroNum; i ++) {
        if (cadastros[i].salario >= 1000) {
            printf("Nome: %s\tSalario: R$%.2lf\n\n", cadastros[i].nome, cadastros[i].salario);
        }
    }
    printf("Aperte enter para continuar.");
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void encontrarPessoaPorRg() {
    int rgBusca;
    bool pessoaEncontrada = false;
    printf("Insira o RG para realizar a busca de um cadastro: ");
    scanf("%i", &rgBusca);
    system("cls");
    
    for (int i = 0; i < cadastroNum; i ++) {
        if (cadastros[i].rg == rgBusca) {
            pessoaEncontrada = true;
            printf("Nome: "); puts(cadastros[i].nome);
            printf("\nRG: %i\n\n", cadastros[i].rg);
            printf("CPF: %i\n\n", cadastros[i].cpf);
            printf("Sexo: "); puts(cadastros[i].sexo);
            printf("Idade: %i\n\n", cadastros[i].idade);
            printf("Estado Civil: "); puts(cadastros[i].estadoCivil);
            printf("Telefone: %i\n\n", cadastros[i].telefone);
            printf("Salario: R$%.2lf\n\n", cadastros[i].salario);
            printf("Rua: "); puts(cadastros[i].moradia.rua);
            printf("Bairro: "); puts(cadastros[i].moradia.bairro);
            printf("Cidade: "); puts(cadastros[i].moradia.cidade);
            printf("Estado: "); puts(cadastros[i].moradia.estado);
            printf("CEP: %i\n\n", cadastros[i].moradia.cep);
            break;
        }
    }
    if (pessoaEncontrada != true) {
        printf("Cadastro nao encontrado\n\n");
    }
    printf("Aperte enter para continuar.");
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}