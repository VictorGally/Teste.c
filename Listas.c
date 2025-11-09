#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Listas encadeadas
//struct No {
    //int dado;
    //struct No* proximo;
//};

//Remover o primeiro elemento de uma ista encadeada simples
//void removerDoInicio(struct No** inicio) {
    //if(*inicio != NULL){
        //struct No* temp = *inicio;
        //*inicio = (*inicio)->proximo;
        //free(temp);
    //}
//}

//Percorrer lista encadeada simples exibindo os elementos
//void listar(struct No* inicio){
    //struct No* atual = inicio;
    //while (atual != NULL){
        //printf("%d\n", atual->dado);
        //atual = atual->proximo;
    //}
//}

//void inserirNoInicio(struct No** inicio, int valor){
    //struct No* novo = (struct No*) malloc(sizeof(struct No));
    //novo->dado = valor;
    //novo->proximo = *inicio;
    //*inicio = novo;
//}

//Lista duplamente encadeada
//struct No{
    //int dado;
    //struct No* proximo;
    //struct No* anterior;
//};

//Lista circular simples
//struct No{
    //int dado;
    //struct No* proximo; // o úlrimo aponta para o primeiro
//};

//Lista circular duplamente encadeada
//struct No{
    //int dado;
    //struct No* proximo;
    //struct No* anterior;
//};

//int main(){
    //struct No* primeiro = (struct No*) malloc(sizeof(struct No));
    //struct No* segundo = (struct No*) malloc(sizeof(struct No));
    //struct No* terceiro = (struct No*) malloc(sizeof(struct No));

    //primeiro->dado = 10;
    //primeiro->proximo = segundo;

    //segundo->dado = 20;
    //segundo->proximo = terceiro;

    //terceiro->dado = 30;
    //terceiro->proximo = NULL;

    //Percorrendo a lista
    //struct No* atual = primeiro;
    //while (atual != NULL){
        //printf("%d\n", atual->dado);
        //atual = atual->proximo;
    //}

//Declarar vetor de inteiros com 5 posições
//int numeros[5] = {10, 20, 30, 40, 50};

//printf("%d", numeros[2]); // Imprime 30

//Criar a lista com 3 posições
//int* numeros = (int*) malloc(3 * sizeof(int));

//Atribuir os valores iniciais
//numeros[0] = 10;
//numeros[1] = 20;
//numeros[2] = 30;

//Expandir a lista para 5 posições
//numeros = (int*) realloc(numeros, 5 * sizeof(int));

//numeros[3] = 40;
//numeros[4] = 50;

//Percorrer vetor pela lista
//int buscaLinear(int lista[], int tamanho, int valor){
    //for(int i = 0; < tamanho; i++){
        //if (lista[i] == valor){
            //return i; // Retorna o índice onde encontrou o valor
        //}
    //}
    //return -1; // Retorna -1 se não encontrou
//}

// Percorrer Lista encadeada
int buscaLinearLista(struct No* inicio, int valor){
    int pos = 0;
    struct No* atual = inicio;
    while (atual != NULL){
        if (atual->dado == valor){
            return pos;
        }
        atual = atual->proximo;
        pos++;
    }
    return -1;
}
//return 0;

//}

