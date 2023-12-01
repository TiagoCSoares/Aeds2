#include <stdio.h>
#include <stdlib.h>


typedef struct firstCome {
    int unidadeTempo;
    struct fcfs;
} fcfs;



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


void firstCome() {


}



int main() {

    int define = 1;
    int a = 0;
    int b = 0;
    while(define != 0){
        printf("\nEscolha o método desejado:\n");
        printf("1- First Come, First Served\n");
        printf("2- Shortest Job First\n");
        printf("3- Round-Robin\n");
        printf("0- Sair do Programa\n");
        
        scanf("%d", &define);

        switch (define) {
            case 1:
                b = trinta();
                if(b == 1){
                    a = geraAleatorio();
                    printf("%d", a);
                }
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


    return 0;
}