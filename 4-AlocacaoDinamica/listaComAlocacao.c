#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0


typedef struct no {
    int info;
    struct no *prox;
} Node;

typedef struct {
    struct no *comeco;
} Lista;

// Iniciar a lista
void iniciaLista(Lista *lista) {
    lista->comeco = NULL;
}

// Mostrar/Exibir a lista
void mostraLista(Lista lista) {
    Node *aux = lista.comeco;
    while (aux != NULL) {
        printf("%d \t", aux->info);
        aux = aux->prox;
    }
    printf("\n");
}

// Inserir na lista DE FORMA ORDENADA
void insere(Lista *lista, int valor) {
    Node *ant = lista->comeco;
    Node *aux = lista->comeco;
    Node *novoNoh = (Node*) malloc(sizeof(Node));
    novoNoh->info = valor;
    // LISTA VAZIA
    if (aux == NULL || aux->info > valor) {
        lista->comeco = novoNoh;
        novoNoh->prox = ant;
    } else { // LISTA NÃO VAZIA
        Node *ant = lista->comeco;
        while (aux != NULL && aux->info < valor) {
            ant = aux;
            aux = aux->prox;
        }
        novoNoh->prox = ant->prox;
        ant->prox = novoNoh;
    }
}


// Remover um elemento da lista
int removeDaLista(Lista *lista, int valor){
    Node *atual = lista->comeco;
    if(atual == NULL) {
        //printf("Lista vazia. Impossível remover!\n");
        return FALSE;
    } else {
        if(atual->info == valor) {
            lista->comeco = atual->prox;
            free(atual);
            return TRUE;
        }
        Node *ant = lista->comeco;
        while(atual->prox != NULL && atual->info != valor) {
            ant = atual;
            atual = atual->prox;
            if(atual->info == valor) {
                ant->prox = atual->prox;
                free(atual);
                return TRUE;
            }
        }
        printf("Valor não encontrado na lista\n");
    }
} 


int main() {

    Lista lista;
    iniciaLista(&lista);
    int  a = removeDaLista(&lista, 7);
    printf("Valor removido? %d\n", a);

    insere(&lista, 5);
    insere(&lista, 6);
    insere(&lista, 3);
    insere(&lista, 4);
    insere(&lista, 1);
    insere(&lista, 2);
    insere(&lista, 7);
    insere(&lista, 8);
    insere(&lista, 9);

    a= removeDaLista(&lista, 7);
    printf("Valor removido? %d\n", a);


    removeDaLista(&lista, 3);
    printf("Valor removido? %d\n", a);


    mostraLista(lista);
}