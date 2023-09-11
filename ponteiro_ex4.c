#include <stdio.h> 

int main() {

    int v1[5] = { 1, 2, 3, 4, 5};
    int v2[5] = { 1, 2, 3, 4, 5};
    int v3[6] = { 1, 2, 3, 4, 5, 6};
    int *p1 = &v1[0];
    int *p2 = &v2[0];
    int *p3 = &v3[0];


    int length_v1 = sizeof(v1)/sizeof(v1[0]);
    int length_v2 = sizeof(v2)/sizeof(v2[0]);
    int length_v3 = sizeof(v3)/sizeof(v3[0]);

    //soma v1 e v2
    if(length_v1 == length_v2){
        int vsoma_12[length_v1];
        for(int i = 0; i < length_v1; i++) {
            vsoma_12[i] = *(p1+i) + *(p2+i);
        }
    } else(printf("Vetores de tamanhos diferentes"));

    //soma v2 e v3
    if(length_v2 == length_v3){
        int vsoma_23[length_v1];
        for(int i = 0; i < length_v1; i++) {
            vsoma_23[i] = v2[i] + v3[i];
        }
    } else(printf("Vetores de tamanhos diferentes"));


    return 0;
}