//Nome: Tiago Costa Soares
//Matrícula: 2020.1.08.017


#include <stdio.h>
#include <stdlib.h>

int main() {
    int *gradeAverage;
    int numberOfStudents, currentIndex, higherAPC;

    numberOfStudents = 1;
    currentIndex = -1;

    higherAPC = 0;
    gradeAverage = (int*) malloc(numberOfStudents * sizeof(int));

    if (gradeAverage == NULL) {
        printf("Erro na alocação dinâmica!\n");
        exit(0);
    }


    while(gradeAverage[currentIndex] >= 0){
        currentIndex++;
        printf("Digite o CDA do aluno %d:", currentIndex);
        scanf("%d", &gradeAverage[currentIndex]);
        numberOfStudents++;
        gradeAverage = (int*) realloc(gradeAverage, (numberOfStudents * sizeof(int)));

        if (gradeAverage[currentIndex] > higherAPC) {
            higherAPC = gradeAverage[currentIndex];
        }
    }

    printf("O maior valor CDA entre os alunos da UNIFAL é de: %d\n", higherAPC);

    free(gradeAverage);
}