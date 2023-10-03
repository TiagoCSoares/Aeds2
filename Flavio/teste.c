#include <stdio.h>

int main () {
    int a = 10;
    int *pont_a = &a;
    int **pont_a2 = &pont_a; 


    printf("var a: %p\n", &a);
    printf("var a: %d\n", a);
    printf("pont pont_a: %p\n", pont_a);
    printf("pont pont_a: %d\n", *pont_a);
    printf("pont pont_a2: %p\n", pont_a2);
    printf("pont pont_a2: %d\n", *pont_a);

}