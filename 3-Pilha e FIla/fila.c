#include <stdio.h>
#include <string.h>
#define TAM 8


typedef struct _Pessoa {
    char nome[20];
    int idade;
} Pessoa;



void mostraFila(Pessoa *fila, int comeco, int fim, int tamanho) {
    if(tamanho == 0){
        printf("Fila vazia\n");
    } else {
        /*printf("fim%d\n", fim);
        /*printf("comeco: %d\n", comeco);
        printf("fim %d\n", fim);*/

        /*while(comeco != fim){
            printf("Pessoa #%d \t Nome: %s \t Idade: %d\n", comeco, fila[comeco].nome, fila[comeco].idade);
            if(comeco+1 == TAM){
                comeco = -1;
            }
        }
        printf("Pessoa #%d \t Nome: %s \t Idade: %d\n", comeco, fila[comeco].nome, fila[comeco].idade);*/




        //FILA CIRCULAR
        //COMECO -> FIM
        while(comeco != fim){
            if(comeco == TAM) {
                comeco = 0;
            }
            printf("Pessoa #%d \t Nome: %s \t Idade: %d\n", comeco, fila[comeco].nome, fila[comeco].idade);
            comeco+= 1;
        }
            printf("Pessoa #%d \t Nome: %s \t Idade: %d\n", comeco, fila[comeco].nome, fila[comeco].idade);
    }
}

void inserirFila(Pessoa *fila, int *comeco, int *fim, int *tamanho, Pessoa pessoa) {
    if(*tamanho == TAM) {
        printf("Lista Cheia\n"); //Queue 
    } else {

        //*fim = (*fim == TAM-1) ? 0 : *fim + 1
        if(*fim == TAM - 1){
            *fim = 0;
        }

        /*strcpy(fila[*fim + 1].nome, pessoa.nome);    //receber o valor de uma string em outra
        fila[*fim+1].idade = pessoa.idade;*/

        *fim += 1;
        fila[*fim] = pessoa;
        *tamanho += 1;
    }
}


Pessoa* retiraDaFila(Pessoa *fila, int *comeco, int *tamanho) {
    if(*tamanho == 0) {
        printf("Lista vazia\n");
        return NULL;
    }
    *tamanho = *tamanho - 1;
    int aux = *comeco;
    *comeco = (*comeco == TAM-1) ? 0 : *comeco +1;
    
    return fila;
}

void removerFila(Pessoa *fila, int *comeco, int *tamanho) {
    if(*tamanho == 0){
        printf("Lista vazia\n");
    }   else{ 
        *comeco = (*comeco == TAM-1) ? 0 : *comeco +1;
        *tamanho--;
    }
}




int main() {
    int comeco = 0;
    int fim = -1;
    int tamanho = 0;

    Pessoa fila[TAM];

    Pessoa pessoa = {"Nome", 20};
    inserirFila(fila, &comeco, &fim, &tamanho, pessoa);

    Pessoa pessoa2 = {"Nome", 30};
    inserirFila(fila, &comeco, &fim, &tamanho, pessoa2);

    Pessoa pessoa3 = {"Nome", 301};
    inserirFila(fila, &comeco, &fim, &tamanho, pessoa3);

    Pessoa pessoa4 = {"Nome", 310};
    inserirFila(fila, &comeco, &fim, &tamanho, pessoa4);


    Pessoa pessoa5 = {"Nome", 3120};
    inserirFila(fila, &comeco, &fim, &tamanho, pessoa5);


    Pessoa pessoa6 = {"Nome", 7370};
    inserirFila(fila, &comeco, &fim, &tamanho, pessoa6);


    Pessoa pessoa7 = {"Nome", 830};
    inserirFila(fila, &comeco, &fim, &tamanho, pessoa7);


    Pessoa pessoa8 = {"Nome", 930};
    inserirFila(fila, &comeco, &fim, &tamanho, pessoa8);


    Pessoa pessoa9 = {"Nome", 0};
    inserirFila(fila, &comeco, &fim, &tamanho, pessoa9);



     
    /*printf("fila[0].nome = %s, fila[0].idade = %d\n", fila[0].nome, fila[0].idade);
    printf("fila[1].nome = %s, fila[1].idade = %d\n", fila[1].nome, fila[1].idade); */

    //printf("fila[1].nome = %s, fila[1].idade = %d\n", fila[7].nome, fila[7].idade); 
    //printf("fila[1].nome = %s, fila[1].idade = %d\n", fila[8].nome, fila[8].idade); 

    //removerFila(fila, &comeco, &tamanho);

    mostraFila(fila, comeco, fim, tamanho);

    Pessoa *p1 = retiraDaFila(fila, &comeco, &tamanho);
    printf("nome: %s \t idade: %d\n", p1->nome, p1->idade);


    Pessoa *p2 = retiraDaFila(fila, &comeco, &tamanho);
    printf("nome: %s \t idade: %d\n", p1->nome, p1->idade);
    /*
    int opcao;
    do{
        printf("------------------------------\n");
        printf("Menu: ");
        printf("0- Sair do menu");
        printf("1- Adicionar elemento na fila");
        printf("2- Adicionar elemento na fila");
        printf("3- Remover elemento da fila");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirFIla(&fila, &comeco, &fim, &tamanho, pessoa);
                break;
            case 2: 
                break;
            case 3:
                break;
            deafult:
                printf("Opção inválida\n");

        }
    }while(opcao != 0)
    
    
    
    
    */
    
    
    
    
    return 0;

}