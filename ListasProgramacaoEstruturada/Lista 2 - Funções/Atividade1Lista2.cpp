//Atividade 1 - Lista 2
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include <stdio.h>
#include <stdlib.h>
float calculoMedia(float altura[], int quantPessoas);
int main () {
    int quantPessoas;
    float mediaAritmetica;

	while(true){
    	printf("Digite a quantidade de pessoas: ");
    	scanf("%d", &quantPessoas);
    	system("cls");
    	if(quantPessoas > 5 or quantPessoas < 1){
    		printf("Quantidade de pessoa invalida. Tente novamente.\n");
		}else break;
	}
    float altura[quantPessoas];

    for(int i = 1; i <= quantPessoas; i++){
        printf("Digite a altura da pessoas %d: ", i);
        scanf("%f", &altura[i]);
    }

	mediaAritmetica = calculoMedia(altura, quantPessoas);
	
	printf("A media de altura e : %.2f", mediaAritmetica);


	return 0;
}
float calculoMedia(float altura[], int quantPessoas){
	float media = 0;
	for(int i = 1; i <= quantPessoas; i++){
		media += altura[i]/quantPessoas;
	}
	return media;
}
	
