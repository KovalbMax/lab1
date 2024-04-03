#include <stdio.h>
#include <stdlib.h>
#include "operations.h"

int main() {
    
    int n;
    char znac;
    printf("Vvedite razmernost - ");
    scanf("%d", &n);
    double** matrix1;
    double** matrix2;
    matrix1 = (double**)malloc(n * sizeof(double*));
    matrix2 = (double**)malloc(n * sizeof(double*));

    for (int i = 0; i < n; i++) {
        matrix1[i] = (double*)malloc(n * sizeof(double));
        matrix2[i] = (double*)malloc(n * sizeof(double));
    }
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
    }

    printf("Vvedite znacheniya 1 matrici:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Vvedite znacheniya 2 matrici:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix2[i][j]);
        }
    }

    printf("VVedite znac operacii(+,-,*) - ");
    scanf(" %c", &znac);
    if (znac == '+') {
        result = sum(matrix1, matrix2, n);
    } else if (znac == '-') {
        result = minus(matrix1, matrix2, n);
    } else if (znac == '*') {
        result = comp(matrix1, matrix2, n);
    }
 

    printf("Rezultat:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++) {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);

    return 0;
}
