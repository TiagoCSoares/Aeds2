#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

typedef struct no {
    struct no *ant;
    int info;
    struct no *prox;
} Node;

typedef struct {
    struct no *comeco;
    struct no *fim;
} Lista;

// Iniciar a lista
void iniciaLista(Lista *lista) {
    lista->comeco = NULL;
    lista->fim = NULL;
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



// Mostrar/Exibir a lista inversa
void mostraListaInversa(Lista lista) {
    Node *aux = lista.fim;
    while(aux != NULL){
        printf("%d \t", aux->info);
        aux = aux->ant;
    }
    printf("\n");
}

// Inserir na lista DE FORMA ORDENADA
void insere(Lista *lista, int valor) {
    Node *novoNoh = (Node*) malloc(sizeof(Node));
    novoNoh->info = valor;
    novoNoh->prox = NULL;
    novoNoh->ant = NULL;

    Node *aux = lista->comeco;

    // LISTA VAZIA
    if (aux == NULL || aux->info > valor) {
        novoNoh->prox = aux;
        if (aux != NULL) {
            aux->ant = novoNoh;
        } else {
            lista->fim = novoNoh; // A lista está vazia, então o novo nó é também o fim
        }
        lista->comeco = novoNoh;
    } else { // LISTA NÃO VAZIA
        while (aux != NULL && aux->info < valor) {
            aux = aux->prox;
        }
        if (aux != NULL) {
            novoNoh->ant = aux->ant;
            novoNoh->prox = aux;
            if (aux->ant != NULL) {
                aux->ant->prox = novoNoh;
            } else {
                lista->comeco = novoNoh;
            }
            aux->ant = novoNoh;
        } else {
            lista->fim->prox = novoNoh;
            novoNoh->ant = lista->fim;
            lista->fim = novoNoh;
        }
    }
}

// Remover um elemento da lista
int removeDaLista(Lista *lista, int valor) {
    Node *atual = lista->comeco;
    while (atual != NULL && atual->info != valor) {
        atual = atual->prox;
    }
    if (atual != NULL) {
        if (atual->ant != NULL) {
            atual->ant->prox = atual->prox;
        } else {
            lista->comeco = atual->prox;
        }
        if (atual->prox != NULL) {
            atual->prox->ant = atual->ant;
        } else {
            lista->fim = atual->ant;
        }
        free(atual);
        return TRUE;
    } else {
        printf("Valor não encontrado na lista\n");
        return FALSE;
    }
}

int main() {
    Lista lista;
    iniciaLista(&lista);
    int a = removeDaLista(&lista, 7);
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

    mostraListaInversa(lista);

    a = removeDaLista(&lista, 7);
    printf("Valor removido? %d\n", a);

    removeDaLista(&lista, 3);
    printf("Valor removido? %d\n", a);

    mostraLista(lista);
    mostraListaInversa(lista);

    return 0;
}
