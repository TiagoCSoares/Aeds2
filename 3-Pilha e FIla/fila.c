#include <stdio.h>
#include <string.h>
#define TAM 10


typedef struct _Pessoa {
    char nome[20];
    int idade;
} Pessoa;


void inserirFila(Pessoa *fila, int *comeco, int *fim, int *tamanho, Pessoa pessoa) {
    if(*tamanho == TAM) {
        printf("Lista Cheia\n"); //Queue 
    } else {

        //*fim = (*fim == TAM-1) ?  : *fim + 1
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





void removerFila(Pessoa *fila, int *comeco, int *fim, int *tamanho, Pessoa pessoa) {


    




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
     
    printf("fila[0].nome = %s, fila[0].idade = %d\n", fila[0].nome, fila[0].idade);
    printf("fila[1].nome = %s, fila[1].idade = %d\n", fila[1].nome, fila[1].idade); 








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