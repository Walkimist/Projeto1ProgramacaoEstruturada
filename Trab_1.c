#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

//Funções
void incluirUsuario (void);
void editarUsuario (void);
void excluirUsuario (void);
void buscarUsuario (void);
void imprimirUsuarios (void);
void fazerBackup (void);
void fazerRestauracao (void);
void alterarInformacoes (int idUsuario);

//Variáveis
int opcao, id[1000],backupId[1000], numUsuario = 0, buscaId;
double altura[1000], backupAltura[1000];
char nomeUsuario[1000][32],sexo[1000][15],email[1000][64],endereco[1000][200];
char backupNomeUsuario[1000][32],backupSexo[1000][32],backupEmail[1000][64],backupEndereco[1000][200], buscaEmail[64];
bool vacinou[1000], backupVacinou[1000], fezBackup = false, temArroba;

int main(){
    do {
        printf("=================== Bem Vindo Usuario! ===================\n\n");
        printf("Digite o numero ao lado da opcao que deseja:\n\n");
        printf("==========================================================\n\n");
        printf("1-Incluir um usuario           2-Editar um usuario\n\n");
        printf("3-Excluir um usuario           4-Buscar um usuario\n\n");
        printf("5-Imprimir todos os usuarios   6-Fazer Backup dos usuarios\n\n");
        printf("7-Fazer restauracao dos dados\n\n");
        printf("==========================================================\n\n");
        scanf("%d", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 8);

    switch(opcao) {
        case 1: //inluir usuário
            incluirUsuario();
        break;

        case 2: //editar usuário
            editarUsuario();
        break;

        case 3: //excluir usuário
            excluirUsuario();
        break;
        
        case 4: //buscar usuário
            buscarUsuario();
        break;

        case 5: //imprimir usuários cadastrados
            imprimirUsuarios();
        break;

        case 6: //fazer backup dos usuários
            fazerBackup();
        break;
        
        case 7: //fazer restauração dos dados
            fazerRestauracao();
        break;
    }
}

void incluirUsuario(void) {
    if (numUsuario < 1000) {
        do {
            printf("========= Inclusao de Usuario =========\n\n");
            printf("Insira o nome completo do novo usuario:\n\n");
            printf("=======================================\n\n");
            fflush(stdin);
            fgets(nomeUsuario[numUsuario], 32, stdin);
            system("cls");

            do {
                printf("====== Inclusao de Usuario ======\n\n");
                printf("Insira o e-mail do novo usuario:\n\n");
                printf("=================================\n\n");
                scanf("%s", &email[numUsuario]);
                system("cls");
                for (int i = 0; i < 64; i++) {
                    if(email[numUsuario][i] == '@'){
                        temArroba = true;
                    }
                }
            } while (temArroba == false);

            do {
                printf("===================== Inclusao de Usuario =====================\n\n");
                printf("Insira o sexo do usuario (Masculino, Feminino ou Nao declarar):\n\n");
                fflush(stdin);
                fgets(sexo[numUsuario], 15, stdin);
                system("cls");
            } while (strcmp(sexo[numUsuario], "Masculino\n") != 0 && strcmp(sexo[numUsuario], "Feminino\n") != 0 && strcmp(sexo[numUsuario], "Nao declarar\n") != 0);
            
            printf("==== Inclusao de Usuario ====\n\n");
            printf("Insira o endereco do usuario:\n\n");
            printf("=============================\n\n");
            fflush(stdin);
            fgets(endereco[numUsuario], 200, stdin);
            system("cls");
            
            do {
                printf("=== Inclusao de Usuario ===\n\n");
                printf("Insira a altura do usuario:\n\n");
                printf("===========================\n\n");
                scanf("%lf", &altura[numUsuario]);
                system("cls");
            } while (altura[numUsuario] < 1 && altura[numUsuario] > 2);

            printf("============ Inclusao de Usuario ============\n\n");
            printf("O usuario vacinou? (1 para sim e 0 para nao):\n\n");
            scanf("%i", &opcao);
            if (opcao == 1) vacinou[numUsuario] = true; else vacinou[numUsuario] = false;
            system("cls");

            srand(time(NULL));
            id[numUsuario] = rand() % 9999;
            printf("============== Inclusao de Usuario ==============\n\n");
            printf("Usuario de ID %i criado com sucesso! Escolha uma opcao:\n\n", id[numUsuario]);
            printf("=================================================\n\n");
            printf("1-Criar outro usuario            2-Voltar ao menu\n\n");
            printf("=================================================\n\n");
            scanf("%i", &opcao);
            system("cls");

            numUsuario ++;
        } while (opcao != 2 && numUsuario < 1000);
        main();
    } else {
        printf("nao");
    }
}

void editarUsuario() {
    do {
        printf("=================== Edicao de Usuario ==================\n\n");
        printf("Deseja buscar o usuario para edicao por ID ou por email?\n\n");
        printf("========================================================\n\n");
        printf("1-Busca por ID    2-Busca por Email     3-Voltar ao menu\n\n");
        printf("========================================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 3);

    if (opcao == 1) {
        printf("=== Edicao de Usuario ===\n\n");
        printf("Digite o ID do usuario:\n\n");
        printf("=========================\n\n");
        scanf("%i", &buscaId);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(id[i] == buscaId){
                alterarInformacoes(i);
            break; 
            }
        }
    } else if (opcao == 2) {
        printf("==== Edicao de Usuario ====\n\n");
        printf("Digite o Email do usuario:\n\n");
        printf("===========================\n\n");
        scanf("%s", &buscaEmail);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(strcmp(email[i], buscaEmail) == 0){
                alterarInformacoes(i);
            break;
            }
        }
    } else main();
}

void alterarInformacoes(int idUsuario) {
    do {
         do {
            printf("===================== Edicao de Usuario ====================\n\n");
            printf("Usuario encontrado! Qual informacao gostaria de alterar?\n\n");
            printf("============================================================\n\n");
            printf("1-Nome   2-Email   3-Sexo   4-Endereco   5-Altura   6-Vacina\n\n");
            printf("============================================================\n\n");
            scanf("%i", &opcao);
            system("cls");
        } while (opcao < 1 && opcao > 6);

        switch (opcao) {
        case 1: //Novo nome
            printf("=== Edicao de Usuario ===\n\n");
            printf("Insira o novo nome:\n\n");
            printf("=========================\n\n");
            fflush(stdin);
            fgets(nomeUsuario[idUsuario], 32, stdin);
            system("cls");
        break;

        case 2: //Novo email
            do {
                printf("====== Edicao de Usuario ======\n\n");
                printf("Insira o novo e-mail do usuario:\n");
                printf("===============================\n\n");
                scanf("%s", &email[idUsuario]);
                system("cls");
                for (int i = 0; i < 64; i++) {
                    if(email[idUsuario][i] == '@'){
                    temArroba = true;
                    }
                }
            } while (temArroba == false);
        break;

        case 3: //Novo sexo
            do {
                printf("======================== Edicao de Usuario =========================\n\n");
                printf("Insira o novo sexo do usuario (Masculino, Feminino ou Nao declarar):\n\n");
                printf("====================================================================\n\n");
                fflush(stdin);
                fgets(sexo[idUsuario], 15, stdin);
                system("cls");
            } while (strcmp(sexo[idUsuario], "Masculino\n") != 0 && strcmp(sexo[idUsuario], "Feminino\n") != 0 && strcmp(sexo[idUsuario], "Nao declarar\n") != 0);
        break;
                        
        case 4: //Novo endereço
            printf("======== Edicao de Usuario ========\n\n");
            printf("Insira o novo endereco do usuario:\n");
            printf("===================================\n\n");
            fflush(stdin);
            fgets(endereco[idUsuario], 200, stdin);
            system("cls");
        break;

        case 5: //Nova altura
            do {
                printf("======= Edicao de Usuario =======\n\n");
                printf("Insira a nova altura do usuario:\n");
                printf("=================================\n\n");
                scanf("%lf", &altura[idUsuario]);
                system("cls");
            } while (altura[idUsuario] < 1 && altura[idUsuario] > 2);
        break;

        case 6: //Novo estado de vacinação
            do {
                printf("============= Edicao de Usuario =============\n\n");
                printf("O usuario vacinou? (1 para sim e 0 para nao):\n");
                printf("=============================================\n\n");
                scanf("%i", &opcao);
                system("cls");
            } while (opcao != 0 && opcao != 1);
            if (opcao == 1) vacinou[numUsuario] = true; else vacinou[numUsuario] = false;
        break;
        }

        do {
            printf("Informacao alterada, Escolha uma das seguintes opcoes:\n1-Alterar outra informacao\n2-Voltar ao menu");
            scanf("%i", &opcao);
        } while (opcao < 1 && opcao > 2);
    } while (opcao != 2);
    main();
}

void excluirUsuario(void){
    do {
        printf("Deseja buscar o usuario para exclusao por ID ou por email?\n1-ID;\n2-Email\n3-Voltar ao menu\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 3);

    if (opcao == 1) {
        printf("Digite o ID do usuario: ");
        scanf("%i", &buscaId);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(id[i] == buscaId){
                fflush(stdin);
                strcpy(nomeUsuario[i],"\0");
                strcpy(email[i], "\0");
                strcpy(sexo[i], "\0");
                strcpy(endereco[i], "\0");
                altura[i] = 0;
                id[i] = NULL;
                vacinou[i] = NULL;
            break; 
            }
        }
    } else if (opcao == 2) {
        printf("Digite o Email do usuario: ");
        scanf("%s", &buscaEmail);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(strcmp(email[i], buscaEmail) == 0){
                fflush(stdin);
                strcpy(nomeUsuario[i],"\0");
                strcpy(email[i], "\0");
                strcpy(sexo[i], "\0");
                strcpy(endereco[i], "\0");
                altura[i] = 0;
                id[i] = NULL;
                vacinou[i] = NULL;
            break;
            }
        }
    } else main();
    do{
            printf("Digite 1 para voltar ao menu: ");
            scanf("%i", &opcao);
            if(opcao < 1 && opcao > 1){
                printf("Opcao inexistente, tente novamente.\n");
                system("cls");
            }
            if(opcao == 1){
                system("cls");
                main();
            }
        }while(opcao != 1);
}

void buscarUsuario(void){
    do {
        printf("Deseja buscar o usuario por ID ou por email?\n1-ID;\n2-Email\n3-Voltar ao menu\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 3);

    if(opcao == 1){
        printf("Digite o ID do usuario: ");
        scanf("%d", &buscaId);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(id[i] == buscaId){
                printf("Usuario de Id: %d\n\n", id[i]);
                printf("Nome: %s\n", nomeUsuario[i]);
                printf("Email: %s\n\n", email[i]);
                printf("Sexo: %s\n", sexo[i]);
                printf("Endereco: %s\n", endereco[i]);
                printf("Altura: %.2lf\n\n", altura[i]);
                printf("Esta vacinado: ");
                if(vacinou[i] == true){
                    printf("Sim\n\n\n");
                } else printf("Nao\n\n\n");
                break;
            }
        }
        do{
            printf("Digite 1 para voltar ao menu: ");
            scanf("%i", &opcao);
            if(opcao < 1 && opcao > 1){
                printf("Opcao inexistente, tente novamente.\n");
                system("cls");
            }
            if(opcao == 1){
                system("cls");
                main();
            }
        }while(opcao != 1);
    } else if(opcao == 2){
        printf("Digite o Email do usuario: ");
        scanf("%s", &buscaEmail);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(strcmp(email[i], buscaEmail) == 0){
                printf("Usuario de Id: %d\n\n", id[i]);
                printf("Nome: %s\n", nomeUsuario[i]);
                printf("Email: %s\n\n", email[i]);
                printf("Sexo: %s\n", sexo[i]);
                printf("Endereco: %s\n", endereco[i]);
                printf("Altura: %.2lf\n\n", altura[i]);
                printf("Esta vacinado: ");
                if(vacinou[i] == true){
                    printf("Sim\n\n\n");
                } else printf("Nao\n\n\n");
                break;
            }
        }
        do{
            printf("Digite 1 para voltar ao menu: ");
            scanf("%i", &opcao);
            if(opcao < 1 && opcao > 1){
                printf("Opcao inexistente, tente novamente.\n");
                system("cls");
            }
            if(opcao == 1){
                system("cls");
                main();
            }
        }while(opcao != 1);
    } else {
        main();
    }
}

void imprimirUsuarios(void){
    for(int i = 0; i < numUsuario; i++){
        printf("Nome: %s\nId: %d\n\nEmail: %s\n\n\n",nomeUsuario[i], id[i], email[i]);
    }
    do{
            printf("Digite 1 para voltar ao menu: ");
            scanf("%i", &opcao);
            if(opcao < 1 && opcao > 1){
                printf("Opcao inexistente, tente novamente.\n");
                system("cls");
            }
            if(opcao == 1){
                system("cls");
                main();
            }
        }while(opcao != 1);
}

void fazerBackup(void){
    for(int i = 0; i < 1000; i++){
            strcpy(backupNomeUsuario[i],nomeUsuario[i]);
            strcpy(backupEmail[i],email[i]);
            strcpy(backupSexo[i],sexo[i]);
            strcpy(backupEndereco[i],endereco[i]);
            backupAltura[i] = altura[i];
            backupId[i] = id[i];
            if(vacinou[i] == true){
                backupVacinou[i] = true;
            }else if(vacinou[i] == false){
                backupVacinou[i] = false;
            }
    }
    fezBackup = true;
    do{
        printf("Backup feito com sucesso!\nDigite 1 para voltar ao menu: ");
        scanf("%i", &opcao);
        if(opcao < 1 && opcao > 1){
            printf("Opcao inexistente, tente novamente.\n");
            system("cls");
        }
        if(opcao == 1){
            system("cls");
            main();
        }
    }while(opcao != 1);
}

void fazerRestauracao(void){
    if(fezBackup == false){
        printf("Nao ha backups para poder fazer uma restauracao.\n");
        main();
    }
    for(int i = 0; i < 1000; i++){
            strcpy(nomeUsuario[i],backupNomeUsuario[i]);
            strcpy(email[i],backupEmail[i]);
            strcpy(sexo[i],backupSexo[i]);
            strcpy(endereco[i],backupEndereco[i]);
            altura[i] = backupAltura[i];
            id[i] = backupId[i];
            if(backupVacinou[i] == true){
                vacinou[i] = true;
            }else if(backupVacinou[i] == false){
                vacinou[i] = false;
            }
    }
    do{
        printf("Restauracao feita com sucesso!\nDigite 1 para voltar ao menu: ");
        scanf("%i", &opcao);
        if(opcao < 1 && opcao > 1){
            printf("Opcao inexistente, tente novamente.\n");
            system("cls");
        }
        if(opcao == 1){
            system("cls");
            main();
        }
    }while(opcao != 1);
}