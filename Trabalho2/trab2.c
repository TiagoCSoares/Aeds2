#include <stdio.h>
#include <stdlib.h>
#define TAM 100

typedef struct firstCome {
    int unidadeTempo;
    //struct fcfs;
} fcfs;

typedef struct firstJob {
    int unidadeTempo;
    struct fj;
} fj;


fj ordenaFJ(fj *no) {
    fj aux = *no;
    fj node = *no;
    return *no;
}


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


int firstCome() {
    int numero_processos = 1;
    int tamanho = 0;
    int tam_aux = 1;
    int _30;
    fcfs fila[TAM];
    fila[tamanho].unidadeTempo = geraAleatorio();
    printf("%d\t", fila[0].unidadeTempo);

    while(fila[tamanho].unidadeTempo >= 0 && tamanho < TAM) {

        _30 = trinta();
        if(_30 == 1 && tam_aux < TAM){
            fila[tam_aux].unidadeTempo = geraAleatorio();
            printf("%d\t", fila[tam_aux].unidadeTempo);
            tam_aux++;
            numero_processos++;
        }

        fila[tamanho].unidadeTempo--;

        if(fila[tamanho].unidadeTempo == 0) {
            tamanho++;
        }
    }
    
    return numero_processos;
}


int firstJob() {


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
                printf("%d\n", lakaka);
                break;
            case 2:
                a = geraAleatorio();
                printf("%d", a);
                break;
            case 3:
                a = geraAleatorio();
                    printf("%d", a);
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

    return 0;
}