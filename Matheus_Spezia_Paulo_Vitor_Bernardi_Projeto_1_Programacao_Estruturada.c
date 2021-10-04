//Primeiro projeto Programação estruturada
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<time.h>

//Funções
void incluirUsuario (void);
void editarUsuario (void);
void excluirUsuario (void);
void realizarExclusao (int idUsuario);
void buscarUsuario (void);
void mostrarInformacoes (int idUsuario);
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
    do { //Menu inicial para escolha da ação
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
        case 1: //Inluir usuário
            incluirUsuario();
        break;

        case 2: //Editar usuário
            editarUsuario();
        break;

        case 3: //Excluir usuário
            excluirUsuario();
        break;
        
        case 4: //Buscar usuário
            buscarUsuario();
        break;

        case 5: //Imprimir usuários cadastrados
            imprimirUsuarios();
        break;

        case 6: //Fazer backup dos usuários
            fazerBackup();
        break;
        
        case 7: //Fazer restauração dos dados
            fazerRestauracao();
        break;
    }
}

void incluirUsuario(void) { //Sub algoritmo de inclusão de usuario
    if (numUsuario < 1000) {
        do {//Nome
            printf("========= Inclusao de Usuario =========\n\n");
            printf("Insira o nome completo do novo usuario:\n\n");
            printf("=======================================\n\n");
            fflush(stdin);
            fgets(nomeUsuario[numUsuario], 32, stdin);
            system("cls");

            do {//Email
                printf("====== Inclusao de Usuario ======\n\n");
                printf("Insira o e-mail do novo usuario:\n\n");
                printf("=================================\n\n");
                scanf("%s", &email[numUsuario]);
                system("cls");
                for (int i = 0; i < 64; i++) {//Verificação se possui @
                    if(email[numUsuario][i] == '@'){
                        temArroba = true;
                    }
                }
            } while (temArroba == false);

            do {//Sexo
                printf("===================== Inclusao de Usuario =====================\n\n");
                printf("Insira o sexo do usuario (Masculino, Feminino ou Nao declarar):\n\n");
                printf("===============================================================\n\n");
                fflush(stdin);
                fgets(sexo[numUsuario], 15, stdin);
                system("cls");
                //Verficação do sexo
            } while (strcmp(sexo[numUsuario], "Masculino\n") != 0 && strcmp(sexo[numUsuario], "Feminino\n") != 0 && strcmp(sexo[numUsuario], "Nao declarar\n") != 0);
            
            //Endereço
            printf("==== Inclusao de Usuario ====\n\n");
            printf("Insira o endereco do usuario:\n\n");
            printf("=============================\n\n");
            fflush(stdin);
            fgets(endereco[numUsuario], 200, stdin);
            system("cls");
            
            do { //Altura
                printf("=== Inclusao de Usuario ===\n\n");
                printf("Insira a altura do usuario:\n\n");
                printf("===========================\n\n");
                scanf("%lf", &altura[numUsuario]);
                system("cls");
            } while (altura[numUsuario] < 1 && altura[numUsuario] > 2);//Verificação da altura

            //Vacinação
            printf("============ Inclusao de Usuario ============\n\n");
            printf("O usuario vacinou? (1 para sim e 0 para nao):\n\n");
            scanf("%i", &opcao);
            if (opcao == 1) vacinou[numUsuario] = true; else vacinou[numUsuario] = false;
            system("cls");

            srand(time(NULL));
            id[numUsuario] = rand() % 99999; //Selecionar um ID aleatório para o usuário

            //Conclusão da inclusão, permitindo ao usuário a incluir mais um ou voltar ao menu
            printf("================= Inclusao de Usuario =================\n\n");
            printf("Usuario de ID %i criado com sucesso! Escolha uma opcao:\n\n", id[numUsuario]);
            printf("=======================================================\n\n");
            printf("1-Criar outro usuario                  2-Voltar ao menu\n\n");
            printf("=======================================================\n\n");
            scanf("%i", &opcao);
            system("cls");

            numUsuario ++; //Aumentar o índice para inclusão do proximo usuário
        } while (opcao != 2 && numUsuario < 1000);
        main();
    } else {
        do {
            printf("=================== Inclusao de Usuario ===================\n\n");
            printf("Numero de usuarios no limite, digite 1 para voltar ao menu:\n\n");
            printf("===========================================================\n\n");
            scanf("%i", &opcao);
            system("cls");
        } while(opcao != 1);
        main();
    }
}

void editarUsuario() {//Sub algoritmo para encontrar o usuário a ser editado
    do {//Menu para encontrar o usuario que se quer editar atravéz do ID ou email
        printf("=================== Edicao de Usuario ==================\n\n");
        printf("Deseja buscar o usuario para edicao por ID ou por email?\n\n");
        printf("========================================================\n\n");
        printf("1-Busca por ID    2-Busca por Email     3-Voltar ao menu\n\n");
        printf("========================================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 3);

    if (opcao == 1) {//Busca por ID
        printf("=== Edicao de Usuario ===\n\n");
        printf("Digite o ID do usuario:\n\n");
        printf("=========================\n\n");
        scanf("%i", &buscaId);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(id[i] == buscaId){
                alterarInformacoes(i); //Sub algoritmo leva como parâmetro o índice do usuário encontrado
            break; //Se o usuário for encontrado parar a busca
            }
        }
    } else if (opcao == 2) {//Busca por Email
        printf("==== Edicao de Usuario ====\n\n");
        printf("Digite o Email do usuario:\n\n");
        printf("===========================\n\n");
        scanf("%s", &buscaEmail);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(strcmp(email[i], buscaEmail) == 0){
                alterarInformacoes(i); //Sub algoritmo leva como parâmetro o índice do usuário encontrado
            break; //Se o usuário for encontrado parar a busca
            }
        }
    } else main();

    do { //Caso o usuário não seja encontrado
        printf("=================== Edicao de Usuario ====================\n\n");
        printf("Usuario nao encontrado. Escolha uma das seguintes opcoes:\n\n");
        printf("==========================================================\n\n");
        printf("1-Editar outro usuario                    2-Voltar ao menu\n\n");
        printf("==========================================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 2);
    if (opcao == 1) editarUsuario(); else main();
}

void alterarInformacoes(int idUsuario) {//Sub algoritmo de edição do usuario
    do {
         do {//Menu para escolher o que se dejesa editar
            printf("===================== Edicao de Usuario ====================\n\n");
            printf("Usuario encontrado! Qual informacao gostaria de alterar?\n\n");
            printf("============================================================\n\n");
            printf("1-Nome   2-Email   3-Sexo   4-Endereco   5-Altura   6-Vacina\n\n");
            printf("============================================================\n\n");
            scanf("%i", &opcao);
            system("cls");
        } while (opcao < 1 && opcao > 6);

        switch (opcao) { //Essas verificações de variáveis são as mesmas presentes da inclusão de usuário
        case 1: //Novo nome
            printf("== Edicao de Usuario ==\n\n");
            printf("Insira o novo nome:\n\n");
            printf("=======================\n\n");
            fflush(stdin);
            fgets(nomeUsuario[idUsuario], 32, stdin);
            system("cls");
        break;

        case 2: //Novo email
            do {
                printf("======= Edicao de Usuario =======\n\n");
                printf("Insira o novo e-mail do usuario:\n\n");
                printf("=================================\n\n");
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
            printf("Insira o novo endereco do usuario:\n\n");
            printf("===================================\n\n");
            fflush(stdin);
            fgets(endereco[idUsuario], 200, stdin);
            system("cls");
        break;

        case 5: //Nova altura
            do {
                printf("======= Edicao de Usuario =======\n\n");
                printf("Insira a nova altura do usuario:\n\n");
                printf("=================================\n\n");
                scanf("%lf", &altura[idUsuario]);
                system("cls");
            } while (altura[idUsuario] < 1 && altura[idUsuario] > 2);
        break;

        case 6: //Novo estado de vacinação
            do {
                printf("============= Edicao de Usuario =============\n\n");
                printf("O usuario vacinou? (1 para sim e 0 para nao):\n\n");
                printf("=============================================\n\n");
                scanf("%i", &opcao);
                system("cls");
            } while (opcao != 0 && opcao != 1);
            if (opcao == 1) vacinou[numUsuario] = true; else vacinou[numUsuario] = false;
        break;
        }

        do {//Menu para continuar ou parar a edição do usuário
            printf("================== Edicao de Usuario =================\n\n");
            printf("Informacao alterada, Escolha uma das seguintes opcoes:\n\n");
            printf("======================================================\n\n");
            printf("1-Alterar outra informacao            2-Voltar ao menu\n\n");
            printf("======================================================\n\n");
            scanf("%i", &opcao);
            system("cls");
        } while (opcao < 1 && opcao > 2);
    } while (opcao != 2);
    main();
}

void excluirUsuario(void){//Sub algortimo de busca de usuário para exclusão
    do {//Menu de busca de usuário
        printf("=================== Exclusao de Usuario ==================\n\n");
        printf("Deseja buscar o usuario para exclusao por ID ou por email?\n\n");
        printf("==========================================================\n\n");
        printf("1-ID                2-Email               3-Voltar ao menu\n\n");
        printf("==========================================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 3);

    if (opcao == 1) {//Busca por ID
        printf("== Exclusao de Usuario ==\n\n");
        printf("Digite o ID do usuario:\n\n");
        printf("=========================\n\n");
        scanf("%i", &buscaId);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(id[i] == buscaId){
                realizarExclusao(i); //Sub algoritmo leva como parâmetro o índice do usuário encontrado
            break; //Se o usuário for encontrado parar a busca
            }
        }
    } else if (opcao == 2) {//Busca por Email
        printf("=== Exclusao de Usuario ===\n\n");
        printf("Digite o Email do usuario:\n\n");
        printf("===========================\n\n");
        scanf("%s", &buscaEmail);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(strcmp(email[i], buscaEmail) == 0){
                realizarExclusao(i); //Sub algoritmo leva como parâmetro o índice do usuário encontrado
            break; //Se o usuário for encontrado parar a busca
            }
        }
    } else main();

    do { //Caso o usuário não seja encontrado
        printf("=================== Exclusao de Usuario ====================\n\n");
        printf("Usuario nao encontrado. Escolha uma das seguintes opcoes:\n\n");
        printf("============================================================\n\n");
        printf("1-Excluir outro usuario                     2-Voltar ao menu\n\n");
        printf("============================================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 2);
    if (opcao == 1) excluirUsuario(); else main();
}

void realizarExclusao(int idUsuario) {//Sub algoritmo que realiza a exclusão
    fflush(stdin);
    //Transforma todos os dados do usuário selecionado para dados nulos
    strcpy(nomeUsuario[idUsuario],"\0");
    strcpy(email[idUsuario], "\0");
    strcpy(sexo[idUsuario], "\0");
    strcpy(endereco[idUsuario], "\0");
    altura[idUsuario] = 0;
    id[idUsuario] = NULL;
    vacinou[idUsuario] = NULL;
    do {//Menu para excluir outro usuario ou retornar ao menu
        printf("=============== Exclusao de Usuario ===============\n\n");
        printf("Usuario excluido, Escolha uma das seguintes opcoes:\n\n");
        printf("===================================================\n\n");
        printf("1-Excluir outro usuario            2-Voltar ao menu\n\n");
        printf("===================================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 2);
    if (opcao == 1) excluirUsuario(); else main();
}

void buscarUsuario(void){//Sub algoritmo para encontrar um usuário para mostrar suas informações
    do {//Menu de busca
        printf("============= Busca de Usuario =============\n\n");
        printf("Deseja buscar o usuario por ID ou por email?\n\n");
        printf("============================================\n\n");
        printf("1-ID         2-Email        3-Voltar ao menu\n\n");
        printf("============================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 3);

    if(opcao == 1){//Busca por ID
        printf("=== Busca de Usuario ===\n\n");
        printf("Digite o ID do usuario:\n\n");
        printf("========================\n\n");
        scanf("%d", &buscaId);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(id[i] == buscaId){
                mostrarInformacoes(i); //Sub algoritmo leva como parâmetro o índice do usuário encontrado
                break; //Se o usuário for encontrado parar a busca
            }
        }
    } else if(opcao == 2){//Busca por Email
        printf("==== Busca de Usuario ====\n\n");
        printf("Digite o Email do usuario:\n\n");
        printf("==========================\n\n");
        scanf("%s", &buscaEmail);
        system("cls");
        for(int i = 0; i < 1000; i++){
            if(strcmp(email[i], buscaEmail) == 0){
                mostrarInformacoes(i); //Sub algoritmo leva como parâmetro o índice do usuário encontrado
                break; //Se o usuário for encontrado parar a busca
            }
        }
    } else main();

    do { //Caso o usuário não seja encontrado
        printf("=================== Busca de Usuario ====================\n\n");
        printf("Usuario nao encontrado. Escolha uma das seguintes opcoes:\n\n");
        printf("=========================================================\n\n");
        printf("1-Buscar outro usuario                   2-Voltar ao menu\n\n");
        printf("=========================================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 2);
    if (opcao == 1) buscarUsuario(); else main();
}

void mostrarInformacoes(int idUsuario) {//Sub algoritmo que mostra as informações do usuário
    printf("============== Busca de Usuario ==============\n\n");
    printf("Usuario de Id: %d\n\n", id[idUsuario]);
    printf("Nome: %s\n", nomeUsuario[idUsuario]);
    printf("Email: %s\n\n", email[idUsuario]);
    printf("Sexo: %s\n", sexo[idUsuario]);
    printf("Endereco: %s\n", endereco[idUsuario]);
    printf("Altura: %.2lf\n\n", altura[idUsuario]);
    printf("Esta vacinado: ");
    if(vacinou[idUsuario] == true) printf("Sim\n\n\n"); else printf("Nao\n\n\n");

    do {//Menu para buscar outro usuario ou retornar ao menu
        printf("==============================================\n\n");
        printf("Escolha uma das seguintes opcoes:\n\n");
        printf("==============================================\n\n");
        printf("1-Buscar outro usuario        2-Voltar ao menu\n\n");
        printf("==============================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while (opcao < 1 && opcao > 2);
    if (opcao == 1) buscarUsuario(); else main();
}

void imprimirUsuarios(void){//Sub algoritmo que imprime todos os usuários, com seus nomes, IDs e emails
    printf("============== Dados dos Usuarios ==============\n\n");
    for(int i = 0; i < numUsuario; i++){
        printf("Nome: %s\n", nomeUsuario[i]);
        printf("ID: %d\n\n", id[i]);
        printf("Email: %s\n\n\n", email[i]);
        printf("================================================\n\n");
    }
    do{
        printf("Digite 1 para voltar ao menu:\n\n");
        printf("================================================\n\n");
        scanf("%i", &opcao);
    } while(opcao != 1);
    if (opcao == 1) {
        system("cls");
        main();
    }
}

void fazerBackup(void){ //Sub algoritmo de backup dos usuários
    for(int i = 0; i < 1000; i++){ //Copia todas as informações para um backup
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
        printf("===================== Backup de dados =====================\n\n");
        printf("Backup efeituado com sucesso! Digite 1 para voltar ao menu:\n\n");
        printf("===========================================================\n\n");
        scanf("%i", &opcao);
    } while(opcao != 1);
    if (opcao == 1) {
        system("cls");
        main();
    }
}

void fazerRestauracao(void){ //Sub algoritmo de restauração dos usuários
    if(fezBackup == false){ //Restauração não pode ser realizada sem um backup existente 
        do{
            printf("================================ Restauracao =================================\n\n");
            printf("Nao ha backups para poder fazer uma restauracao. Digite 1 para voltar ao menu:\n\n");
            printf("==============================================================================\n\n");
            scanf("%i", &opcao);
            system("cls");
        } while(opcao != 1);
        main();
    }
    for(int i = 0; i < 1000; i++){ //Copia os dados do backup para o sistema ativo
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
        printf("======================== Restauracao =======================\n\n");
        printf("Restauracao feita com sucesso! Digite 1 para voltar ao menu:\n\n");
        printf("============================================================\n\n");
        scanf("%i", &opcao);
        system("cls");
    } while(opcao != 1);
    if (opcao == 1) main();
}