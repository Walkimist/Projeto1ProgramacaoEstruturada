//Atividade 5 - Lista 4
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
 
typedef struct vetor{
     int a,b,c;
 };

void main(){

struct vetor A;
struct vetor B;
struct vetor soma;


printf("Digite a primeira medidas do vetor A: ");
scanf("%d", &A.a);
printf("Digite a segunda medidas do vetor A: ");
scanf("%d", &A.b);
printf("Digite a terceira medidas do vetor A: ");
scanf("%d", &A.c);
printf("Digite a primeira medidas do vetor A: ");
scanf("%d", &B.a);
printf("Digite a segunda medidas do vetor A: ");
scanf("%d", &B.b);
printf("Digite a terceira medidas do vetor A: ");
scanf("%d", &B.c);

soma.a = A.a + B.a;
soma.b = A.b + B.b;
soma.c = A.c + B.c;

printf("Os 3 pontos da soma dos vetores sao:\n%d\n%d\n%d", soma.a, soma.b, soma.c);

}