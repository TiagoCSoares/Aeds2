#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct no{
    int info;
    struct no *esq;
    struct no *dir; 
} Node;



// Inserir novo elemento na Arvore
Node* insere (Node *raiz, int valor){
    Node* node = (Node *) malloc(sizeof(Node));
    node->info = valor;
    node->esq = NULL;
    node->dir = NULL;

    if(raiz == NULL) {
        raiz = node;
    } else {

        if(raiz->info > valor) {
            raiz->esq = insere(raiz->esq, valor);
        }
        if(raiz->info < valor) {
            raiz->dir = insere(raiz->dir, valor);
        }
    }

    return raiz;

}



//TODO: Mostrar a árvore
//Notações: Pré-Ordem, Em-ordem e Pós-ordem
void mostraArvorePreOrdem(Node *raiz) {
    //printf("%d \t", raiz->info);
    if(raiz != NULL) { //if (raiz)
        printf("%d \t", raiz->info);
        mostraArvorePreOrdem(raiz->esq);
        mostraArvorePreOrdem(raiz->dir);
    }
}


void mostraArvoreEmOrdem(Node *raiz) {
    //printf("%d \t", raiz->info);
    if(raiz != NULL) { //if (raiz)
        mostraArvoreEmOrdem(raiz->esq);
        printf("%d \t", raiz->info);
        mostraArvoreEmOrdem(raiz->dir);

    }
}


void mostraArvorePosOrdem(Node *raiz) {
    //printf("%d \t", raiz->info);
    if(raiz != NULL) { //if (raiz)
        mostraArvorePosOrdem(raiz->esq);
        mostraArvorePosOrdem(raiz->dir);
        printf("%d \t", raiz->info);
    }
}

Node* remover(Node *raiz, int valor) {
    if (raiz == NULL) {
        return raiz;
    }

    if (raiz->info == valor) {
        if(raiz->esq == NULL && raiz->dir == NULL){
            free(raiz);
            return NULL;
        }
        if(raiz->esq == NULL) {
            Node *aux = raiz->dir;
            free(raiz);
            return aux;
        }
        if(raiz->dir == NULL) {
            Node* aux = raiz->esq;
            free(raiz);
            return aux;
        }
        Node *aux = raiz->esq;
        Node *ant = aux;

        while(aux->dir != NULL) {
            ant = aux;
            aux = aux->dir;
        }
        if(aux->esq != NULL && aux != ant){
            ant->dir = aux->esq;
        } else if (aux != ant) { ant->dir = NULL;}
        aux->dir = raiz->dir;
        aux->esq = raiz->esq;
        if(ant == aux) {
            aux->esq = NULL;
        }

        free(raiz);
        return aux;
    } else if(raiz->info > valor) {
        raiz->esq = remover(raiz->esq, valor);
    } else {
        raiz->dir = remover(raiz->dir, valor);
    }
    return raiz;
}



//TODO: Buscar elemento na árvore O(log n)
int busca(Node *raiz, int valor) {
    if(raiz == NULL) {
        return FALSE;
    }
    if(raiz->info == valor) {
        return TRUE;
    }
    if(raiz->info > valor){
        busca(raiz->esq, valor);
    } else {
        busca(raiz->dir, valor);
    }
}



int main() {
    //Podemos suprimir a função "inicia" / "iniciaArvore" com essa declaração 
    //Node *raiz = (Node *) malloc(sizeof(Node));
    Node *raiz = NULL;
    
    raiz = insere(raiz, 50);
    raiz = insere(raiz, 30);
    //raiz = insere(raiz, 30);
    raiz = insere(raiz, 60);
    raiz = insere(raiz, 80);
    raiz = insere(raiz, 20);
    raiz = insere(raiz, 45);
    raiz = insere(raiz, 90);
    raiz = insere(raiz, 75);
    mostraArvorePreOrdem(raiz);
    printf("\n");
    mostraArvoreEmOrdem(raiz);
    printf("\n");
    mostraArvorePosOrdem(raiz);
    printf("\n");
    //int cade = busca(raiz,90);
    //printf("Item foi encontrado? %d", cade);
    printf("\n");
    raiz = remover(raiz, 90);
    
    printf("\n");
    mostraArvorePreOrdem(raiz);
    printf("\n");
    mostraArvoreEmOrdem(raiz);
    printf("\n");
    mostraArvorePosOrdem(raiz);
    printf("\n");
    //printf("O valor da informação é: %d \n", raiz->info);

    return 0;
}