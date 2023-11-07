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

int grau(Node *raiz, int valor) {
    if (raiz == NULL) {
        return -1;
    }
    int valorExiste = busca(raiz, valor);
    if (valorExiste == FALSE) {
        return -1;
    }
    if(raiz->info == valor) {
        if(raiz->esq && raiz->dir) {
            return 2;
        }
    
        if(raiz->esq == NULL && raiz->dir == NULL) {
            return 0;
        }
        return 1;
    }
    if (raiz->info < valor) {
        return grau(raiz->dir, valor);
    }
    return grau(raiz->esq, valor);
} 


// nivel(raiz, _, 0)
int nivel(Node *raiz, int valor, int contador) {
    if(!raiz){
        return 0;
    }
    if(raiz->info == valor) {
        return contador;
    }
    if(raiz->info > valor) {
        return nivel(raiz->esq, valor, contador + 1);
    }
    return nivel(raiz->dir, valor, contador + 1);

}

int main() {
    //Podemos suprimir a função "inicia" / "iniciaArvore" com essa declaração 
    //Node *raiz = (Node *) malloc(sizeof(Node));
    Node *raiz = NULL;
    
    raiz = insere(raiz, 8);
    raiz = insere(raiz, 4);
    raiz = insere(raiz, 12);
    raiz = insere(raiz, 2);
    raiz = insere(raiz, 1);
    raiz = insere(raiz, 3);
    raiz = insere(raiz, 6);
    raiz = insere(raiz, 5);
    raiz = insere(raiz, 7);
    raiz = insere(raiz, 10);
    raiz = insere(raiz, 14);
    raiz = insere(raiz, 9);
    raiz = insere(raiz, 11);
    raiz = insere(raiz, 13);
    raiz = insere(raiz, 15);
    //raiz = insere(raiz, 17);
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


    int lakaka = grau(raiz, 30); 
    printf("o grau do noh eh %d\n", lakaka);
    lakaka = nivel(raiz,17, 0);
    printf("%d\n", lakaka);


    int array[15] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    int valor = 0;
    for(int i = 0; i< 15; i++) {
        if(array[i] == valor) {
            printf("encontrado em %d iterações\n", i);
        } else {printf("não encontrado\n");}
    }

    return 0;
}