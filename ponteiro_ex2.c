#include <stdio.h>

int main() {

    int v[60];
    int *p = &v[0];

    printf("Digite o valor: ");
    scanf("%d", p);


    for(int i =1; i < 60; i++){
        v[i] = *p;
    }
    

    for(int i =0; i < 60; i++){
        printf("arr[%d]: %d\n", (i), *(p + i));
    }

    return 0;
}