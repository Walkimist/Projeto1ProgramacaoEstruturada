//Atividade 2 - Lista 5
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

struct aluno{
    char nome[20],sexo[13], naturalidade[20];
    int turma, matricula, serie, anoNascimento;
    double media;
    bool aprovado;
};

void cadastrar(void);
void listarAlunos(void);
void alunosAprovadosReprovados(void);
void porcentagemAlunosPorSexo(void);
void mediaIdadeSerie(void);

struct aluno alunos[30];
int numAluno = 0, opcao;

int main(){
    printf("Qual acao deseja fazer?\n1-Cadastrar Aluno\n2-Listar Alunos\n");   
    printf("3-Exibira porcentagem de alunos aprovados por turma\n4-Exibir aporcentagem de alunos do sexo masculino e do sexo feminino por turma\n");
    printf("5-Media das idades por serie\n");
    scanf("%d", &opcao);
    system("cls");

    switch (opcao){
        case 1:
            cadastrar();
        break;
        case 2:
            listarAlunos();
        break;
        case 3:
            alunosAprovadosReprovados();
        break;
        case 4:
            porcentagemAlunosPorSexo();
        break;
        case 5:
            mediaIdadeSerie();
        break;
        default:
            return 0;
        break;
    }
}

void cadastrar(void){
    if(numAluno == 30){
        printf("Limite de cadastros alcancados.");
        main();
    }

    printf("Digite a matricula do aluno(a): ");
    scanf("%lf", &alunos[numAluno].matricula);
    fflush(stdin);
    system("cls");

    fflush(stdin);
    printf("Digite o nome do aluno(a): ");
    scanf("%s", &alunos[numAluno].nome);
    fflush(stdin);
    system("cls");

    printf("Digite o sexo do aluno(Masculino, Feminino): ");
    fgets(alunos[numAluno].sexo,13,stdin);
    fflush(stdin);
    system("cls");

    printf("Digite a naturalidade do aluno(a): ");
    fgets(alunos[numAluno].naturalidade,20,stdin);
    fflush(stdin);
    system("cls");

    printf("Digite a turma do aluno(a) (1 ou 2): ");
    scanf("%d", &alunos[numAluno].turma);
    if (alunos[numAluno].turma != 1 && alunos[numAluno].turma != 2) {alunos[numAluno].turma = 2;}
    fflush(stdin);
    system("cls");

    printf("Digite a serie do aluno(a) (1, 2 ou 3): ");
    scanf("%d", &alunos[numAluno].serie);
    if (alunos[numAluno].serie != 1 && alunos[numAluno].serie != 2 && alunos[numAluno].serie != 3) {alunos[numAluno].serie = 3;}
    fflush(stdin);
    system("cls");

    printf("Digite a media do aluno(a): ");
    scanf("%lf", &alunos[numAluno].media);
    fflush(stdin);
    system("cls");

    printf("Digite o ano de nascimento do aluno(a): ");
    scanf("%d", &alunos[numAluno].anoNascimento);
    fflush(stdin);
    system("cls");

    printf("Digite se o aluno foi aprovado (1 - sim, 2 - nao):");
    scanf("%i", &opcao);
    if (opcao == 1) {alunos[numAluno].aprovado = true;} else {alunos[numAluno].aprovado = false;}

    system("cls");
    numAluno++;
    main();
}

void listarAlunos(void){
    for(int i = 0; i < numAluno; i++){
        printf("Nome: %s\n", alunos[i].nome);
        printf("Matricula: %d\n\n", alunos[i].matricula);
        printf("Naturalidade: %s\n\n\n", alunos[i].naturalidade);
        printf("Sexo: %s\n\n\n", alunos[i].sexo);
        printf("Turma: %s\n\n\n", alunos[i].turma);
        printf("Serie: %s\n\n\n", alunos[i].serie);
        printf("Ano de Nascimento: %i\n\n\n", alunos[i].anoNascimento);
        printf("Media: %.1lf\n\n\n", alunos[i].media);
        if (alunos[i].aprovado) {printf("Aprovado: Sim");} else {printf("Aprovado: Nao");}
    }
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void alunosAprovadosReprovados(void){
    double quantAprovados[2] = {0}, totalTurma[2] = {0};
    for (int i = 0 ; i < 30; i ++) {
        if (alunos[i].turma == 1) {
            totalTurma[0] ++;
            if (alunos[i].aprovado) {quantAprovados[0] ++;}
        } else {
            totalTurma[1] ++;
            if (alunos[i].aprovado) {quantAprovados[1] ++;}
        }
    }
    printf("A porcentagem de aprovacao da turma 1 e: %.0lf%%", (quantAprovados[0]/totalTurma[0])*100);
    printf("A porcentagem de aprovacao da turma 2 e: %.0lf%%", (quantAprovados[1]/totalTurma[1])*100);
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void porcentagemAlunosPorSexo(void){
    double quantHomens[2] = {0}, totalTurma[2] = {0};
    for (int i = 0 ; i < 30; i ++) {
        if (alunos[i].turma == 1) {
            totalTurma[0] ++;
            if (stricmp(alunos[i].sexo,"Masculino")) {quantHomens[0] ++;}
        } else {
            totalTurma[1] ++;
            if (stricmp(alunos[i].sexo,"Masculino")) {quantHomens[1] ++;}
        }
    }
    printf("A porcentagem de meninos e meninas da turma 1 e, respectivamente: %.0lf%% %.0lf%%", (quantHomens[0]/totalTurma[0])*100, 100-(quantHomens[0]/totalTurma[0])*100);
    printf("A porcentagem de meninos e meninas da turma 2 e, respectivamente: %.0lf%% %.0lf%%", (quantHomens[1]/totalTurma[1])*100, 100-(quantHomens[1]/totalTurma[1])*100);
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}

void mediaIdadeSerie(void) {
    double somaIdadeSerie[3] = {0}, totalSerie[3] = {0};
    for (int i = 0 ; i < 30; i ++) {
        if (alunos[i].serie == 1) {
            totalSerie[0] ++;
            somaIdadeSerie[0] += 2021 - alunos[i].anoNascimento;
        } else if (alunos[i].serie == 2) {
            totalSerie[1] ++;
            somaIdadeSerie[1] += 2021 - alunos[i].anoNascimento;
        } else {
            totalSerie[2] ++;
            somaIdadeSerie[2] += 2021 - alunos[i].anoNascimento;
        }
    }
    
    printf("A media de idades da serie 1 e: %.1lf", somaIdadeSerie[0]/totalSerie[0]);
    printf("A media de idades da serie 2 e: %.1lf", somaIdadeSerie[1]/totalSerie[1]);
    printf("A media de idades da serie 3 e: %.1lf", somaIdadeSerie[2]/totalSerie[2]);
    fflush(stdin);
	while(getchar() != '\n'){};
	system("cls");
    main();
}