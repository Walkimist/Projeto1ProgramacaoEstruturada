//Atividade 3 - Lista 2
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
#include<stdlib.h>
float calculoMedia1(float nota1[],float nota2[], int i);
float calculoMedia2(float nota1[],float nota2[], int i);
float calculoMedia3(float nota1[],float nota2[], int i);
int main () {
    int quantPessoas, i;
    float mediaAritmetica, mediaPonderada1, mediaPonderada2;

	while(true){
    	printf("Digite a quantidade de alunos: ");
    	scanf("%d", &quantPessoas);
    	system("cls");
    	if(quantPessoas > 20 or quantPessoas < 1){
    		printf("Quantidade de alunos invalida. Tente novamente.\n");
		}else break;
	}
    float nota1[quantPessoas], nota2[quantPessoas];

    for(i = 1; i <= quantPessoas; i++){
        printf("Digite a primeira nota do aluno %d: ", i);
        scanf("%f", &nota1[i]);
        printf("Digite a segunda nota do aluno %d: ", i);
        scanf("%f", &nota2[i]);
    }
	system("cls");

	printf("Media Aritmetica\n");
	for(i = 1; i <= quantPessoas; i++){
		mediaAritmetica = calculoMedia1(nota1, nota2, i);
		printf("A media do aluno %d e : %.2f\n",i, mediaAritmetica);
	}
	printf("\n\nMedia Ponderada(4 e 6)\n");
	for(i = 1; i <= quantPessoas; i++){
		mediaPonderada1 = calculoMedia2(nota1, nota2, i);
		printf("A media do aluno %d e : %.2f\n",i, mediaPonderada1);
	}
	printf("\n\nMedia Ponderada(3 e 7)\n");
	for(i = 1; i <= quantPessoas; i++){
		mediaPonderada2 = calculoMedia3(nota1, nota2, i);
		printf("A media do aluno %d e : %.2f\n",i, mediaPonderada2);
	}



	return 0;
}
float calculoMedia1(float nota1[],float nota2[], int i){
	return (nota1[i] + nota2[i])/2;
}
float calculoMedia2(float nota1[],float nota2[], int i){
	return (nota1[i] * 4 + nota2[i] * 6)/10;
}
float calculoMedia3(float nota1[],float nota2[], int i){
	return (nota1[i] * 3 + nota2[i] * 7)/10;
}
	
