//Terceiro projeto Programação estruturada
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h> 
#include<string.h>
#include<stdbool.h>
#include<time.h>

//Declaracao de struct
typedef struct usuario usu; 
struct usuario{ 
	int id; 
	char nome[30], email[40],sexo[15],endereco[50];
	double altura;
	bool vacinou;
	usu *proximo; 
} *usuarios; 

usu* backupUsuarios;

//Declaraco de funcoes
usu* inicializar(); 
usu* incluir(usu * usuarios);
usu* editar(usu * usuarios);
void imprimir(usu * usuarios);
void buscar(usu * usuarios);
usu* remover(usu * usuarios);
usu* fazerBackup(usu * usuarios);
usu* fazerRestauracao(usu * backupUsuarios);

int main(){
	int opcao;
	usuarios = inicializar();
	backupUsuarios = inicializar();
	do { //Pegar opcao do usuario
		printf("======================= Bem Vindo! =======================\n\n");
        printf("Digite o numero ao lado da opcao que deseja:\n\n");
        printf("==========================================================\n\n");
        printf("1-Incluir um usuario           2-Editar um usuario\n\n");
        printf("3-Excluir um usuario           4-Buscar um usuario\n\n");
        printf("5-Imprimir todos os usuarios   6-Fazer Backup dos usuarios\n\n");
        printf("7-Fazer restauracao dos dados  8-Sair\n\n");
        printf("==========================================================\n\n");
		scanf("%d",&opcao);
		system("cls");
		switch(opcao){
			case 1: usuarios=incluir(usuarios); break;
			case 2: usuarios=editar(usuarios); break;
			case 3: usuarios=remover(usuarios); break;
			case 4: buscar(usuarios); break;
			case 5: imprimir(usuarios); break;
			case 6: backupUsuarios=fazerBackup(usuarios); break;
			case 7: usuarios=fazerRestauracao(backupUsuarios); break;
			case 8: return 0; break;
			default: printf("\nOpcao invalida!\n\n");
		}
	} while (opcao!=8);
}

usu* inicializar(){ //Inicialização de ponteiro
	return NULL; 
}

usu* incluir(usu * usuarios){
	int opcao;
	bool temArroba = false;

	usu* novo = (usu*) malloc(sizeof(usuarios)* 50);

	//ID
	printf("==== Inclusao de Usuario ====\n\n");
	printf("Insira o ID do novo usuario:\n\n");
	printf("=============================\n\n");
	scanf("%d",&novo->id);
	fflush(stdin);
	system("cls");

	//Nome
	printf("========= Inclusao de Usuario =========\n\n");
    printf("Insira o nome completo do novo usuario:\n\n");
    printf("=======================================\n\n");
    gets(novo->nome);
	fflush(stdin);
    system("cls");
	
	do { //Email
        printf("====== Inclusao de Usuario ======\n\n");
        printf("Insira o e-mail do novo usuario:\n\n");
        printf("=================================\n\n");
        scanf("%s", &novo->email);
        fflush(stdin);
        system("cls");
        for (int i = 0; i < 64; i++) { //Verificar se tem @
            if(novo->email[i] == '@'){
                temArroba = true;
            }
        }
    } while (temArroba == false);

	do { //Sexo
        printf("===================== Inclusao de Usuario =====================\n\n");
        printf("Insira o sexo do usuario (Masculino, Feminino ou Nao declarar):\n\n");
        printf("===============================================================\n\n");
        fflush(stdin);
        gets(novo->sexo);
        system("cls");
    } while (strcmp(novo->sexo, "Masculino") != 0 &&
			 strcmp(novo->sexo, "Feminino") != 0 &&
             strcmp(novo->sexo, "Nao declarar") != 0);

	//Endereco
	printf("==== Inclusao de Usuario ====\n\n");
    printf("Insira o endereco do usuario:\n\n");
	printf("=============================\n\n");
    gets(novo->endereco);
	fflush(stdin);
    system("cls");

	do { //Altura
        printf("=== Inclusao de Usuario ===\n\n");
        printf("Insira a altura do usuario:\n\n");
        printf("===========================\n\n");
        scanf("%lf", &novo->altura);
        system("cls");
    } while (novo->altura < 1 || novo->altura > 2);

	//Vacina
	printf("============ Inclusao de Usuario ============\n\n");
    printf("O usuario vacinou? (1 para sim e 0 para nao):\n\n");
	printf("=============================================\n\n");
    scanf("%i", &opcao);
	fflush(stdin);
    if (opcao == 1) novo->vacinou = true; else novo->vacinou = false;
    system("cls");

	//Apontar o ponteiro para o proximo usuario que for criado e retornar o novo usuario
	novo->proximo=usuarios;
	return novo;
}

usu* editar(usu * usuarios) {
	usu *auxiliar; 
	bool temArroba = false;
	int id, i=0, tamanhoLista=0, opcao, j;

	//Pegar qual usuario deve ser editado
	printf("==== Edicao de Usuario ====\n\n");
	printf("Digite o id do usuario:\n\n");
	printf("===========================\n\n");
	scanf("%d",&id);
	system("cls");

	for(auxiliar=usuarios;auxiliar!=NULL;auxiliar=auxiliar->proximo) { //Buscar usuario
		tamanhoLista++;
		if(auxiliar->id==id) { //Caso encontre pega as novas entradas
			fflush(stdin);
        	//Nome
			printf("========== Edicao de Usuario ==========\n\n");
			printf("Insira o novo nome completo do usuario:\n\n");
			printf("=======================================\n\n");
			gets(auxiliar->nome);
			fflush(stdin);
			system("cls");
			
			do { //Email
				printf("======= Edicao de Usuario =======\n\n");
				printf("Insira o novo e-mail do usuario:\n\n");
				printf("=================================\n\n");
				scanf("%s", &auxiliar->email);
				fflush(stdin);
				system("cls");
				for (int j = 0; j < 64; j++) {
					if(auxiliar->email[j] == '@'){
						temArroba = true;
					}
				}
			} while (temArroba == false);

			do { //Sexo
				printf("====================== Edicao de Usuario ======================\n\n");
				printf("Insira o sexo do usuario (Masculino, Feminino ou Nao declarar):\n\n");
				printf("===============================================================\n\n");
				fflush(stdin);
				gets(auxiliar->sexo);
				system("cls");
			} while (strcmp(auxiliar->sexo, "Masculino") != 0 &&
					strcmp(auxiliar->sexo, "Feminino") != 0 &&
					strcmp(auxiliar->sexo, "Nao declarar") != 0);

			//Endereco
			printf("===== Edicao de Usuario =====\n\n");
			printf("Insira o endereco do usuario:\n\n");
			printf("=============================\n\n");
			gets(auxiliar->endereco);
			fflush(stdin);
			system("cls");

			do { //Altura
				printf("==== Edicao de Usuario ====\n\n");
				printf("Insira a altura do usuario:\n\n");
				printf("===========================\n\n");
				scanf("%lf", &auxiliar->altura);
				system("cls");
			} while (auxiliar->altura < 1 || auxiliar->altura > 2);

			//Vacina
			printf("============= Edicao de Usuario =============\n\n");
			printf("O usuario vacinou? (1 para sim e 0 para nao):\n\n");
			printf("=============================================\n\n");
			scanf("%i", &opcao);
			fflush(stdin);
			if (opcao == 1) auxiliar->vacinou = true; else auxiliar->vacinou = false;
			system("cls");

        	break; //Finaliza o for
    	} else i++;
    }

	if (tamanhoLista==i){ //Determina se o usuario foi encontrado ao longo do for
		printf("==== Edicao de Usuario ====\n\n");
    	printf("Usuario nao encontrado.\n\n");
		printf("==========================\n\n");
		printf("Aperte enter para continuar.");
		fflush(stdin);
		while(getchar() != '\n'){};
		system("cls");
		return usuarios;
	} else {
		printf("=== Edicao de Usuario ===\n\n");
		printf("Usuario editado.\n\n");
		printf("=========================\n\n");
		printf("Aperte enter para continuar.");
		fflush(stdin);
		while(getchar() != '\n'){};
		system("cls");
		auxiliar = usuarios;
		return auxiliar;
	}
}

void imprimir(usu * usuarios){
	usu* auxiliar;
	int i;
	printf("============== Dados dos Usuarios ==============\n\n");
	for(auxiliar=usuarios;auxiliar!=NULL;auxiliar=auxiliar->proximo){ //Imprime todos os usuarios do sistema
		printf("ID: %d\n",auxiliar->id);
		printf("Nome: %s\n",auxiliar->nome);
		printf("Email: %s\n",auxiliar->email);
		printf("Sexo: %s\n",auxiliar->sexo);
		printf("Endereco: %s\n",auxiliar->endereco);
		printf("Altura: %.2lf\n",auxiliar->altura);
		printf("Vacinou: ");
		if (auxiliar->vacinou == true) printf("Sim"); else printf("Nao");
		printf("\n\n============================================\n\n");
	}
	printf("Aperte enter para continuar.");
	fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
}

void buscar(usu * usuarios){
    usu *auxiliar;
	int id, i=0, tamanhoLista=0;

	//Pega qual usuario deve ser buscado
	printf("==== Busca de Usuario ====\n\n");
	printf("Digite o id do usuario:\n\n");
	printf("==========================\n\n");
	scanf("%d",&id);
	system("cls");

	for(auxiliar=usuarios;auxiliar!=NULL;auxiliar=auxiliar->proximo){ //Busca pelo usuario
		tamanhoLista++;
		if(auxiliar->id==id){ //Caso encontre imprime as informações
			printf("============= Busca de Usuario =============\n\n");
        	printf("ID: %d\n",auxiliar->id);
			printf("Nome: %s\n",auxiliar->nome);
			printf("Email: %s\n",auxiliar->email);
			printf("Sexo: %s\n",auxiliar->sexo);
			printf("Endereco: %s\n",auxiliar->endereco);
			printf("Altura: %.2lf\n",auxiliar->altura);
			printf("Vacinou: ");
			if (auxiliar->vacinou == true) printf("Sim"); else printf("Nao");
        	break; //Finaliza o for
    	} else i++;
    }
    if (tamanhoLista==i){ //Determina se o usuario foi encontrado ao longo do for
		printf("==== Busca de Usuario ====\n\n");
    	printf("Usuario nao encontrado!\n\n");
		printf("==========================\n\n");
		printf("Aperte enter para continuar.");
		fflush(stdin);
		while(getchar() != '\n'){};
		system("cls");
	} else {
		printf("\n\n============================================\n\n");
		printf("Aperte enter para continuar.");
		fflush(stdin);
		while(getchar() != '\n'){};
		system("cls");
	}
}

usu* remover(usu * usuarios){
	usu* anterior;  
 	usu* auxiliar; 
	int id;

	//Pega qual usuario será excluído
	printf("=== Exclusao de Usuario ===\n\n");
	printf("Digite o ID do cadastro:\n\n");
	printf("===========================\n\n");
 	scanf("%d",&id);
	system("cls");

	for(anterior=NULL,auxiliar=usuarios;auxiliar!=NULL&&auxiliar->id!=id;anterior=auxiliar,auxiliar=auxiliar->proximo){} //Exclui o usuario escolhido
	
	if(auxiliar==NULL){ //Caso o usuario não tenha sido encontrado
		printf("=== Exclusao de Usuario ===\n\n");
        printf("Usuario nao encontrado!\n\n");
		printf("===========================\n\n");
		printf("Aperte enter para continuar.");
		fflush(stdin);
		while(getchar() != '\n'){};
		system("cls");
		return usuarios;
	}

	if(anterior==NULL){ //Libera o espaço do usuario excluído
		usuarios=auxiliar->proximo;
		free(auxiliar);
	} else {
		anterior->proximo=auxiliar->proximo;
		free(auxiliar);
	}

	printf("=== Exclusao de Usuario ===\n\n");
	printf("Usuario removido.\n\n");
	printf("===========================\n\n");
	printf("Aperte enter para continuar.");
	fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
	return usuarios;
}

//Não conseguimos fazer o sistema de backup e restauração funcionar direito
//Ele só restaura o último usuário inserido no sistema

usu* fazerBackup(usu * usuarios) {
	usu* backup;
	backup = usuarios;
	return backup;
}

usu* fazerRestauracao(usu * backupUsuarios) {
	usu* restauracao;
	restauracao = backupUsuarios;
	return restauracao;
}
