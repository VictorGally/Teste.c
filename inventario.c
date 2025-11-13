//MOD 1 - Hora de Codar

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca necessária para funções de string (strcpy, strcmp)

//Define uma constante para o comprimento máximo que cada texto pode ter.
#define MAX_STR_LEN 50 // Tamanho máximo de cada string/texto

//-----------------------------------------------------------------------
// PARTE 1: LISTA ESTÁTICA (VETOR DE STRINGS)
// Uma lista estática é uma estrutura de dados de tamanho fixo,
// implementada usando um vetor (ou array).
// Toda a memória necessária é alocada de uma só vez, quando a variável é declarada.
//-----------------------------------------------------------------------

// Define uma constante para o número máximo de itens que nossa lista pode conter.
#define TAM_MAX 10 // Define o número máximo de itens na lista estática

// Estrutura que representa a lista estática
typedef struct {
    char dados[TAM_MAX][MAX_STR_LEN]; // Matriz: 10 linhas (itens), 50 colunas (caracteres por item)
    int quantidade; // Este é o nosso contador de controle. Ele informa quantos itens estão realmente armazenados na lista

} ListaEstatica;

// Funções da Lista Estática

// Esta função prepara a lista para ser usada.
// Ela simplesmente define o contador quantidade como 0, indicando que a lista está vazia.
// Recebemos um ponteiro (*lista) para modificar a cariável original passada para a função.
void inicializarlistaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char* texto);
void removerListaEstatica(ListaEstatica *lista, const char* texto);
void listarListaEstatica(const ListaEstatica *lista);

//--------------------------------------------------------------------------
// PARTE 2: LISTA ENCADEADA (DE STRINGS)
// Uma lista encadeada é uma estrutura de dados de tamanho dinâmico.
// Ela é composta por "nós" separados na memoria.
// onde cada nó contém um dado e um ponteiro que "aponta" para o próximo nó da sequência.
//--------------------------------------------------------------------------

// Estrutura do no (cada elemento da lista)
// -char* dados: Este é um ponteiro. Ele não armazena o texto em si, mas sim o endereço
// de memória onde o texto está guardado.
// Isso é muito flexível, pois cada texto pode ter um tamanho diferente, e alocamos apenas
// a memória necessaria para cada um.
// - struct No* proximo: Este é o ponteiro que cria a "ligação". Ele armazena o endereço do próximo nó na lista.
// O último nó da lista terá este ponteiro apontando para NULL.
typedef struct No{
    char* dado; // Ponteiro para a string (alocada dinamicamente)
    struct No *proximo;
} No;

// Isso é um atalho. Em vez de escrever No* sempre que quisermos nos referir à nossa lista, podemos simplesmente usar
// A "lista" em si aoenas um ponteiro para o primeiro nó (a "cabeça" da lista).
typedef No* ListaEncadeada;

// Funções da Lista Encadeada

// Uma lista encadeada cazia é representada por um ponteiro de cabeça que aponta para NULL.
// Esta função simplesmente atribui NULL ao ponteiro que apresenta nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista);

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto);
void removerlistaEncadeada(ListaEncadeada *lista, const char* texto);
void listarListaEncadeada(const ListaEncadeada lista);
void liberarListaEncadeada(ListaEncadeada *lista); // Função nova para limpar a memória

//--------------------------------------------------------------------------
// FUNÇÃO PRINCIPAL (main) E MENUS
//--------------------------------------------------------------------------

void menuListaEstatica();
void menuListaEncadeada();

int main(){
    int opcao;
    do{
        printf("\n--- MANIPULACAO DE LISTAS (TEXTO) ---\n");
        printf("1. Lista Estatica\n");
        printf("2. Lista Encadeada\n");
        printf("0. Sair do Programa\n");
        printf("Escolher uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao){
            case 1:
                menuListaEstatica();
                break;
            case 2:
                menuListaEncadeada();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");    
        }
    } while (opcao != 0);

    return 0;
}

//-------------------------------------------------------------------
// IMPLEMENTAÇÃO DAS FUNÇÕES - LISTA ESTÁTICA
//-------------------------------------------------------------------

void inicializarListaEstatica(ListaEstatica *lista){
    lista->quantidade = 0;
}

void inserirListaEstatica(ListaEstatica *lista, const char* texto){
    // primeiro, ela verifica se alista->quantidade já atingiu TAM_MAX.
    // se sim, a lista esta cheia e a função retorna.
    if (lista->quantidade == TAM_MAX){
        printf("Erro: Lista cheia! nao e possivel inserir\n");
        return;
    }
    // A inserção ocorre na primeira "linha" livre da ma
    // Para strings, não podemos fazer "lista->dados[i] texto:" porque em C não se pode atribuir vetores/ strings
    // Precisamos copiar o conteúdo da string para a posição conrreta na nossa matriz dados.
    strcpy(lista->dados[lista->quantidade], texto);
    // Após a cópia, lista->quantidade é incrementado, pois agora temos mais um item na lista.
    lista->quantidade++;
    printf("Texto \"%s\" inserindo com sucesso.\n", texto);
}

void removerListaEstatica(ListaEstatica *lista, const char* texto){
    int i, pos = -1;
    // Para comparar strings, usamos strcmp(). Retorna 0 se forem igauis.
    // A função percorre os itens em uso na lista (de 0 até quantidade).
    // para comparar strings, usamos strcmp(string1, string2).
    // Essa função retorna 0 se as strings forem idênticas. Se encontrar, guarda a posição (pos) e para o loop.
    for (i = 0; i < lista->quantidade; i++){
        if (strcmp(lista->dados[i], texto) == 0){
            pos = i;
            break;
        }
    }

    // Tratamento de Erro: Se o loop terminar e pos continuar -1, o item não foi encontrado.
    if (pos == -1){
        printf("Erro: Texto \"%s\" nao encontrado na lista.\n", texto);
        return;
    }

    // Fechar a lacuna: Se removemos um item do meio da lista, criamos um "buraco".
    // Para preenchê-lo, movemos todos os itens subsequentes uma posição para a esquerda.
    // O loop for começa na posição do item removido e cada item i+1 para a posicao i.
    // Delocar os elementos posteriores para a esquerda strpy.
    for (i = pos; i < lista->quantidade -1; i++){
        strcpy(lista->dados[i], lista->dados[i + 1]);
    }

    // Atualização do Contador: Finalmente, quantidade é decrementado para refletir que a lista tem um item a menos.
    lista->quantidade--;
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEstatica(const ListaEstatica *lista){
        if (lista->quantidade == 0){
        printf("A lista estatica esta vazia\n");
        return;
    }
     printf("]\n");
}

//-------------------------------------------------------
// IMPLEMENTAÇÃO DAS FUNÇÕES - LISTA ENCADEADA
//-------------------------------------------------------

// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta para NULL.
// Esta função simplesmente atribui NULL ao ponteiro que representa nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista){
        *lista = NULL;
}

void inserirListaEncadeada(ListaEncadeada *lista, const char* texto){
        //1. Alocar memoria para o NOVO NÓ
        // Alocação do Nó: malloc(sizeof(No)) pede ao sistema operacional memória suficiente oara um nó.
        // novoNo agora aponta para essa memória.
        No* novoNo = (No*) malloc(sizeof(No));

        if (novoNo == NULL){
            printf("Erro: Falha na alocacao de memoria para o no.\n");
            return;
        }

        // 2. Alocar memória para a STRING dentro do nó
        // strlen(texto) +1 para incluir o caractere nulo '\0' no final
        // Alocacao da String: malloc(strlen(texto) +1) aloc memória para o texto.
        // strlen conta os caracteres, e o +1 é vitak oara o caractere nulo (\0) que finaliza toda string em C.
        // novoNo->dado agora aponta para este espaço
        novoNo->dado = (char*) malloc(strlen(texto) +1);

        if (novoNo->dado == NULL){
            printf("Erro: Falha na alocacao de memoria para o texto.\n");
            free(novoNo); // Libera o nó que já foi alocado
            return;
        }

        //3. Copiar o texto para a memória recém-alocada
        //Copia do texto: strcpy copia o texto de entrada para a área de memória recém-alocada apontada por novoNo->dado
        strcpy(novoNo->dado, texto);

        // 4. ligar o novo nó à lista
        // O ponteiro proximo do novo no passa a apontar para o que era o antigo primeiro nó da lista.
        novoNo->proximo = *lista;
    // A cabeça da lista (*lista) é atualizada para apontar para o novoNo. o novono é agora  o primeiro item
*lista = novoNo;

printf("Texto \"%s\" inserido com sucesso.\n", texto);
}

void removerListaEncadeada(ListaEncadeada *lista, const char* texto){
    //Usamos cois ponteiros, atual e anterior, para percorrer a lisy=ta avança, e anterior e agregado
    // Paramos quando atual aponta para o nó a ser removido
    No *atual = *lista;
    No *anterior = NULL;

    while (atual != NULL && strcmp(atual->dado, texto) != 0){
            anterior = atual;
            atual = atual->proximo;
    }

    if (atual == NULL){
        printf("Erro: texto \"%s\" nao encontrado na lista.\n", texto);
        return;
    }

    // Se o nó a ser removido for o primeiro (anterior == NULL), a cabeça da lista (*lista) passa a ser o segundo (atual)
    // Se estiver no meio/fim, o ponteiro proximo do nó anterior "pula" o atual e aponta para atual->proximo.
    if (anterior == NULL){
        *lista == atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }

    //Liberação de Memória (Muito Importante): para evitar vazamento de memória (memory leak), precisamos devolver
    //Primeiro, free...

    free(atual->dado);

    free(atual);
    printf("Texto \"%s\" removido com sucesso.\n", texto);
}

void listarListaEncadeada(const ListaEncadeada lista){
    No *temp = lista;
    if (temp == NULL){
        printf("A lista encadeada esta vazia.\n");
        return;
    }
    printf("Itens da Lista Encadeada: [ ");
    while (temp != NULL){
        printf("\"%s\" ", temp->dado); // Usar %s para imprimir
        temp = temp->proximo;
    }
printf("]\n");
}
void liberarListaEncadeada(ListaEncadeada *lista){
    No *atual = *lista;
    No *proximo;
    while (atual != NULL){
        proximo = atual->proximo;
        free(atual->dado);
        free(atual);
    }
    return;
}