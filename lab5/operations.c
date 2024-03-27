#include <stdlib.h>
#include <malloc.h>
double** oper(double** matrix1, double** matrix2, int n ,char znac) {
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
    }
    for (int i=0; i<n ; i++){
       for (int j = 0; j <n; j++) {
            if (znac == '+') {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            } else if (znac == '-') {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            } else if (znac == '*') {
                result[i][j] = 0;
                for (int k = 0; k < n; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }
        
    return result;
}
