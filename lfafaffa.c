#include <stdio.h>
#include <stdlib.h>

double** sum(double** matrix1, double** matrix2, int n) {
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
}

double** minus(double** matrix1, double** matrix2, int n) {
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}

double** umnoj(double** matrix1, double** matrix2, int n) {
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

void printmatrica(double** result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", result[i][j]);
        }
        printf("\n");
    }
}

double** creatematrix(int n) {
    double** matrix = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (double*)malloc(n * sizeof(double));
    }
    return matrix;
}

int main(int argc, char* argv[]) {
    int n;
    char znac;

    printf("Vvedite razmernost - \n");
    scanf("%d", &n);

    double** matrix1 = creatematrix(n);
    double** matrix2 = creatematrix(n);
    double** result;

    printf("Vvedite elementi 1 matrici - \n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &matrix1[i][j]);
        }
    }

    printf("Vvedite elementi 2 matrici - \n");
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
        result = umnoj(matrix1, matrix2, n);
    }

    printmatrica(result, n);

    // Освобождение памяти
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
