#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct firstCome {
    int unidadeTempo;
    int processo;
    struct firstCome *prox;
} fcfs;


typedef struct {
    fcfs* inicio;
    fcfs* fim;
} extremidades;


typedef struct firstJob {
    int processo;
    int unidadeTempo;
    struct firstJob *prox;
} fj;



typedef struct roundRobin {
    int processo;
    int unidadeTempo;
    struct roundRobin *prox;
} rr;



int trinta() {
    int i = rand() % 10 + 1;
    if(i >= 1 && i <= 3){
        return 1;
    } else { 
        return 0;
    }
}


int geraAleatorio(){
    int i = rand() % 20 + 1;
    return i;
}


//-------------------------------------------------------------------
//Funções para o firstJob


// Funciona
void inserirOrdenado(fj **lista, int novoProcesso, int novaUnidadeTempo) {
    fj *novoNo = (fj *)malloc(sizeof(fj));
    if (!novoNo) {
        fprintf(stderr, "Erro ao alocar memória para o novo nó.\n");
        exit(EXIT_FAILURE);
    }
    novoNo->processo = novoProcesso;
    novoNo->unidadeTempo = novaUnidadeTempo;
    novoNo->prox = NULL;

    if (*lista == NULL || novaUnidadeTempo < (*lista)->unidadeTempo) {
        // Inserir no início
        novoNo->prox = *lista;
        *lista = novoNo;
    } else {
        // Encontrar posição de inserção
        fj *atual = *lista;
        while (atual->prox != NULL && atual->prox->unidadeTempo < novaUnidadeTempo) {
            atual = atual->prox;
        }

        // Inserir no meio ou no final
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}


//Funcionando perfeitamente
int firstJob() {
    int iteracoes = 0;
    int numero_processos = 1;
    int _30;
    int criado = 0;
    int processo_criado = 0, tempo_criado = 0;
    fj *lista = (fj*)malloc(sizeof(fj));
    lista->processo = numero_processos;
    lista->unidadeTempo = geraAleatorio();
    //fila->unidadeTempo = 19;
    lista->prox = NULL;
    printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(NULL, NULL)\tAção: Criação do processo:(%d, %d)\n", 
    iteracoes, lista->processo, lista->unidadeTempo, lista->processo, lista->unidadeTempo);
    iteracoes++;
    numero_processos++;
    
    while(1) {
        _30 = trinta();
        if(_30 == 1){
            fj *node = (fj*)malloc(sizeof(fj));
            
            inserirOrdenado(&lista, numero_processos, geraAleatorio());
            processo_criado = numero_processos;
            tempo_criado = node->unidadeTempo;
            numero_processos++;
            criado = 1;
            free(node);
            }

        lista->unidadeTempo--;
        if(lista->prox != NULL) {
            printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(%d, %d)",  
            iteracoes, lista->processo, lista->unidadeTempo,lista->prox->processo, lista->prox->unidadeTempo);
        } else {
            printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(NULL, NULL)",  
            iteracoes, lista->processo, lista->unidadeTempo);
        }
        if(criado == 1) {
            printf("\tAção: Criação do processo (Id:%d, Tempo:%d)\n", processo_criado, tempo_criado);
            criado = 0;
        }   else {
            printf("\tAção: Nenhuma\n");
        }
        //lista->unidadeTempo--;

        if (lista->unidadeTempo == 0) {
            fj *temp = lista;
            lista = lista->prox;
            free(temp);  // Liberar espaço de memória do processo finalizado
        }   
        iteracoes++;
    }
    
    return numero_processos-1;
}



/*
int roundRobin() {
    int iteracoes = 0;
    int numero_processos = 1;
    int tamanho = 0;int tam_aux = 1;
    int _30;
    rr *fila = (rr*)malloc(sizeof(rr));
    fila[tamanho].processo = numero_processos;
    fila[tamanho].unidadeTempo = geraAleatorio();
    fila[tamanho].prox = NULL;



    return numero_processos;

}

*/






//-----------------------------------------------------------------
// Funções para o firstCome


void enfileirar(extremidades* fila, int processo, int tempo) {
    fcfs* novo = (fcfs*)malloc(sizeof(fcfs));
    novo->unidadeTempo = tempo;
    novo->processo = processo;
    novo->prox = NULL;

    if (fila->fim == NULL) {
        fila->fim = novo;
        fila->inicio = novo;
    } else {
        fila->fim->prox = novo;
        fila->fim = novo;
    }

    // Adicionamos este trecho para garantir que fila->inicio->prox seja definido corretamente
    if (fila->inicio->prox == NULL) {
        fila->inicio->prox = novo;
    }
}

void desenfileirar(extremidades* fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia\n");
        return;
    }

    fcfs* remove = fila->inicio;
    fila->inicio = fila->inicio->prox;

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(remove);
}




int firstCome() {

    extremidades fila;
    fila.inicio = NULL;
    fila.fim = NULL;

    int iteracoes = 0;
    int numero_processos = 1;
    int _30;
    int criado = 0;
    int processo_criado = 0, tempo_criado = 0;
    tempo_criado = geraAleatorio();
    enfileirar(&fila, numero_processos, tempo_criado);

    printf("fila.inicio%d,%d\n", fila.inicio->processo, fila.inicio->unidadeTempo);
    numero_processos++;

    printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(NULL, NULL)\tAção: Nenhuma\n", iteracoes, fila.inicio->processo, fila.inicio->unidadeTempo);

    printf("Lakaka");
    iteracoes++;
    //TODO: Loop infinito (?)
    while(iteracoes > 0) {
        _30 = trinta();
        if(_30 == 1){
            tempo_criado = geraAleatorio();
            enfileirar(&fila, numero_processos, tempo_criado);
            numero_processos++;
            criado = 1;
        }

        //printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\n",  iteracoes, fila[tamanho].processo, fila[tamanho].unidadeTempo);
        fila.inicio->unidadeTempo--;
        if(criado == 1) {
            //printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(%d, %d)\tAção: Criado processo (Id:%d, Tempo: %d\n",
            //iteracoes, fila.inicio->processo, fila.inicio->unidadeTempo ,fila.inicio->prox->processo, fila.inicio->prox->unidadeTempo,
            //(numero_processos-1), tempo_criado);
            criado = 0;
        } else {
            //printf("Iteração:%d\tID_processo:%d\tUnidadeTempoRestante:%d\tPróximoProcesso:(%d, %d)\tAção: Nenhuma\n", iteracoes, fila.inicio->processo, fila.inicio->unidadeTempo ,fila.inicio->prox->processo, fila.inicio->prox->unidadeTempo);
        }
        
        if(fila.inicio->unidadeTempo == 0) {
            desenfileirar(&fila);
        }
        iteracoes++;
    }
    
    return numero_processos-1;
}





int main() {
    srand(time(NULL));
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

