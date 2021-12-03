//Atividade 9 - Lista 2
//Matheus Spezia Freire Lorenz - UC21103938
//Paulo Vitor Bernardi Theobald - UC21103812
#include<stdio.h>
float apresentaGrama(float pesoKg);
float apresentaTonelada(float pesoKg);
int leValidaPeso(float pesoGrama, float pesoTon);
int main(){
    float pesoKg, pesoGrama, pesoTon;
    int resposta;
    
    printf("Digite o peso em Quilogramas: ");
    scanf("%f", &pesoKg);

    pesoGrama = apresentaGrama(pesoKg);
    pesoTon = apresentaTonelada(pesoKg);
    resposta = leValidaPeso(pesoGrama, pesoTon);

    return 0;
}
float apresentaGrama(float pesoKg){
    return pesoKg*1000;
}
float apresentaTonelada(float pesoKg){
    return pesoKg/1000;
}
int leValidaPeso(float pesoGrama, float pesoTon){
    printf("Peso em grama: %f\nPeso em Tonelada: %f", pesoGrama, pesoTon);
}