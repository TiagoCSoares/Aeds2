#include <stdio.h>


int main() {
    char palavra[100];

    scanf("%s", palavra);

    char *p1 = &palavra[0];

    printf("%s\n\n", palavra);
    printf("%d\n\n", *p1);
}
