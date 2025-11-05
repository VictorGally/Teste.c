#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    //---Constantes Globais---
    #define MAX_LIVROS 50
    #define MAX_EMPRESTIMOS 100 //Definimos uma capacidade para empréstimos.
    #define TAM_STRING 100

    //---Definição das Estruturas---
    //Struct Livros agora tem um campo 'disponivel' para controlar o status.
    struct Livro {
        char nome[TAM_STRING];
        char autor[TAM_STRING];
        char editora[TAM_STRING];
        int edicao;
        int disponivel; //1 para sim, 0 para não.
    };

    //Nova struct para armazenar informações do empréstimo.
    struct Emprestimo{
        int indeceLivro; //Para saber qual livro do array 'biblioteca'foi emprestado
        char nomeUsuario[TAM_STRING];
    };

    //---Função para limpar o buffer de entrada
    void limparBufferEntrada(){
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    //---Função Principal (main)---
    int main(){
//1. ALOCAÇÃO DINÂMICA DE MEMÓRIA
// Agora, em vez de arrays estáricos, usamos ponteiros.
struct Livro *biblioteca;
struct Emprestimo *emprestimos;

//Usamos calloc para o array de livros. calloc(num_elementos, tamanho_de_cada_elemento)
//Vantagem: inicializa toda a memória com zeros. Isso significa que 'disponível' já começa com todo meu valor zerado
biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

//Usamos malloc para o array de emprestimo. malloc(tamanho_total_em_bytes)
emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

//VERIFICAÇÃO: É crucial verificar se a alocação de memória deu certo.
if(biblioteca == NULL || emprestimos == NULL){
    printf("Erro: Falha ao alocar memoria. \n");
    return 1; //Retorna 1 para indicar um erro.
}

int totalLivros = 0;
int totalEmprestimos = 0;
int opcao;

do{
    printf("====================================\n");
    printf("    BIBLIOTECA - PARTE 2\n");
    printf("====================================\n");
    printf("1 - Cadastrar novo livro\n");
    printf("2 - Listar todos os livros\n");
    printf("3 - Realizar emprstimos\n");
    printf("4 - Listar emprestimos\n");
    printf("0 - Sair\n");
    printf("------------------------------------\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    limparBufferEntrada();

    switch (opcao) {
        case 1: //CADASTRO DE LIVRO
        printf("-----Cadastro de Novo Livro -----\n\n");
        if (totalLivros , MAX_LIVROS){
            //O acesso aos campos do aaray estático.
            printf("Digite o numero do livro: ");
        }
    }
}
    }
