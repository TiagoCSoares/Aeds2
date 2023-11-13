#include <stdlib.h>

typedef struct no {
    int info;
    int fb;
    struct no *esq;
    struct no *dir;
} Node;




Node* rotacaoEsquerda(Node* raiz) {
    Node* temp = raiz;
    raiz = raiz->dir;
    temp->dir = raiz->esq;
    raiz->esq = temp;
    //temp->dir = raiz->esq;
    return raiz;
}

Node* rotacaoDireita(Node *raiz) {
    Node *temp = raiz;
    raiz = raiz->esq;
    temp->esq = raiz->dir;
    raiz->dir = temp;

    return raiz;
}


void mostraArvorePreOrdem(Node *raiz) {
    //printf("%d \t", raiz->info);
    if(raiz != NULL) { //if (raiz)
        printf("%d \t", raiz->info);
        mostraArvorePreOrdem(raiz->esq);
        mostraArvorePreOrdem(raiz->dir);
    }
}

Node* rotacaoDuplaDireita(Node *raiz) {
    raiz->esq = rotacaoEsquerda(raiz->esq);
    raiz = rotacaoDireita(raiz);
    return raiz;

}

Node* rotacaoDuplaEsquerda(Node *raiz) {
    raiz->dir = rotacaoDireita(raiz->dir);
    raiz = rotacaoEsquerda(raiz);
    return raiz;
}

int main() {
    // Rotacao Dupla direita ou Esquerda Direita
    //Node *n1 = (Node*) malloc(sizeof(Node));
    //n1->info = 5;
    //Node *n2 = (Node*) malloc(sizeof(Node));
    //n2->info = 2;
    //Node *n3 = (Node*) malloc(sizeof(Node));
    //n3->info = 3;
    //n1->esq = n2;
    //n2->dir = n3;
    

    // Rotacao Dupla esquerda ou Direita Esquerda
    Node *n1 = (Node*) malloc(sizeof(Node));
    n1->info = 5;
    Node *n2 = (Node*) malloc(sizeof(Node));
    n2->info = 8;
    Node *n3 = (Node*) malloc(sizeof(Node));
    n3->info = 7;
    n1->esq = n2;
    n2->dir = n3;
    
 
    //Node *n1 = (Node*) malloc(sizeof(Node));
    //n1->info = 3;
    //Node *n2 = (Node*) malloc(sizeof(Node));
    //n2->info = 2;
    //Node *n3 = (Node*) malloc(sizeof(Node));
    //n3->info = 1;
    //n1->esq = n2;
    //n2->esq = n3;
    //Node *n4 = (Node*) malloc(sizeof(Node));
    //n4->info = 4;
    //n1->dir = n2;
    //n2->dir = n3;
    //n2->esq = n4;
    //raiz = rotacaoEsquerda(raiz);
    //raiz = rotacaoDireita(raiz);
    Node* raiz = n1;
    rotacaoDuplaEsquerda(raiz);
    mostraArvorePreOrdem(raiz);
    return 1;
}