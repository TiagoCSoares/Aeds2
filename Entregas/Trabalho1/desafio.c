//Desafio: Usando somente aritmética de ponteiros, faça uma função que verifique se uma string está contido na outra.
//
//Exemplo:
//
//char palavra1[10] = "Computacao";
//
//char palavra2[3] = "omp"
//
//// Palavra 2 está contida dentro de Palavra 1.
//
//char palavra1[10] = "Computacao";
//
//char palavra2[3] = "utec"
//
//// Palavra 2 NÃO está contida dentro de Palavra 1.

#include <stdio.h>
#include <string.h>

int main() {

    char palavra1[100];
    char palavra2[100];
    int cont = 0;

    printf("\nDigite a Palavra 1: ");
    scanf("%s", palavra1);
    printf("\nDigite a Palavra 2: ");
    scanf("%s", palavra2);

    char *p1 = &palavra1[0];
    char *p2 = &palavra2[0];

    int length_p1 = strlen(palavra1);
    int length_p2 = strlen(palavra2);
    
    for(int i = 0; i < 10; i++) {
        if(p2[0] == p1[i]) {
            cont++;
            printf("cont %d\n\n", cont);
            while(cont < length_p2 && (*(p2 +cont) == *(p1 + cont + i))){
                printf("cont %d\n\n", cont);
                cont++;
            }
        }
        if(cont == length_p2){
            i += length_p1;
        }   else {
            cont = 0;
        }
    } 

    if((cont) == length_p2) {
        printf("Palavra 2 está contida dentro de Palavra 1.\n");
    }   else {
            printf("Palavra 2 NÃO está contida dentro de Palavra 1.\n");
        }

    return 0;
}