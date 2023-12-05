#include <stdio.h>
#include <stdlib.h>
#define TAM 10

typedef struct firstCome {
    int unidadeTempo;
    int processo;
} fcfs;



typedef struct firstJob {
    int processo;
    int unidadeTempo;
    struct firstJob *prox;
} fj;



int trinta() {
    int i = rand() % 10 + 1;
    if(i >= 1 && i <= 9){
        return 1;
    } else { 
        return 0;
    }
}


int geraAleatorio(){
    int i = rand() % 20 + 1;
    return i;
}


//void insereOrdenado(fj *node, fj *fila) 
//{
//    fj *novo = node;
//    fj *raiz = fila;
//    fj *ant;
//    while (raiz->prox != NULL && raiz->unidadeTempo <= node->unidadeTempo) {
//        ant = raiz;
//        raiz = raiz->prox;
//    }
//
//    if (raiz->prox == NULL) {
//        raiz->prox = node;
//    } else {
//        ant->prox = novo;
//        novo->prox = raiz;
//    }
//}
//
//int firstJob() {
//    int iteracoes = 0;
//    int numero_processos = 1;
//    int tam_aux = 1;
//    int _30;
//    fj *fila = NULL;
//
//    fila->processo = numero_processos;
//    fila->unidadeTempo = geraAleatorio;
//    fila->prox = NULL;
//    printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(NULL, NULL)\n",  iteracoes, fila->processo, fila->unidadeTempo);
//    iteracoes++;
//
//    while(fila->unidadeTempo > 0) {
//
//            _30 = trinta();
//            if(_30 == 1 && tam_aux <= TAM){
//                fj *node = (fj*)malloc(sizeof(fj));
//                node->processo = numero_processos;
//                node->unidadeTempo = geraAleatorio();
//                insereOrdenado(node, &fila);
//                tam_aux++;
//                numero_processos++;
//            }
//
//            //printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\n",  iteracoes, fila[tamanho].processo, fila[tamanho].unidadeTempo);
//            fila->unidadeTempo--;
//            printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(%d, %d)\n",  iteracoes, fila->processo, fila->unidadeTempo,fila->prox->processo, fila->prox->unidadeTempo);
//
//            if(fila->unidadeTempo == 0) {
//                fila = fila->prox;
//            }
//            iteracoes++;
//        }
//    
//    return numero_processos-1;
//}


int firstCome() {

    //TODO: Retirar o tamanho fixo da lista
    int iteracoes = 0;
    int numero_processos = 1;
    int tamanho = 0;
    int tam_aux = 1;
    int _30;
    fcfs fila[TAM];
    int inicio = 0;
    int fim = 0;
    fila[tamanho].processo = numero_processos;
    numero_processos++;
    fila[tamanho].unidadeTempo = geraAleatorio();
    printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(NULL, NULL)\n",  iteracoes, fila[tamanho].processo, fila[tamanho].unidadeTempo);
    iteracoes++;

    //TODO: Loop infinito (?)
    while(fila[tamanho].unidadeTempo > 0 && tamanho <= TAM) {

        _30 = trinta();
        if(_30 == 1 && tam_aux <= TAM){
            fila[tam_aux].processo = numero_processos;
            fila[tam_aux].unidadeTempo = geraAleatorio();
            tam_aux++;
            numero_processos++;
        }

        //printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\n",  iteracoes, fila[tamanho].processo, fila[tamanho].unidadeTempo);
        fila[tamanho].unidadeTempo--;
        printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(%d, %d)\n",  iteracoes, fila[tamanho].processo, fila[tamanho].unidadeTempo,fila[tamanho+1].processo, fila[tamanho+1].unidadeTempo);

        if(fila[tamanho].unidadeTempo == 0) {
            tamanho++;
        }
        iteracoes++;
    }
    
    return numero_processos-1;
}



int main() {

    int define = 1;
    int a = 0;
    int b = 0;
    /*while(define != 0){
        printf("\nEscolha o método desejado:\n");
        printf("1- First Come, First Served\n");
        printf("2- Shortest Job First\n");
        printf("3- Round-Robin\n");
        printf("0- Sair do Programa\n");
        
        scanf("%d", &define);

        switch (define) {
            case 1:
                int lakaka = firstCome();
                break;
            case 2:
                a = geraAleatorio();
                break;
            case 3:
                a = geraAleatorio();
                    break;
            case 0:
                printf("Saindo do programa");
                break;
            default:
                printf("\nValor incorreto, tente novamente!\n");
        
        } 
        }
        */
    int lakaka = firstCome();
    printf("\n%d\n", lakaka);
    //int lakaka2 = firstJob();
    //printf("\n%d\n", lakaka2);
    return 0;
}