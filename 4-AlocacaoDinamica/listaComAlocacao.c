#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int info;
    struct no *prox;
} Node;


typedef struct {
    struct no *comeco;
} Lista;


// Inciar a lista
void iniciaLista(Lista *lista) {
    lista->comeco = NULL;
}


// Mostar/Exibir a lista
void mostraLista(Lista lista) {
    Node *aux = lista.comeco;
    while(aux != NULL) {
        printf("%d \t", aux->info);
        aux = aux->prox;     
    }
}


// Inserir na lista
void insere(Lista *lista, int valor) {
    Node *aux = lista->comeco;
    while(aux != NULL && aux->info < valor) {
        aux = aux->prox;
    }
    if(aux->info > valor || aux) {
        Node novoNoh
    }
}


int main() {
    Lista lista;
    iniciaLista(&lista);
    mostraLista(lista);

    return 0;
}

