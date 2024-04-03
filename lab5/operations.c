#include <stdlib.h>
#include <malloc.h>

double ** sum(double **matrix1, double **matrix2, int n){
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i=0; i<n ; i++){
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j <n; j++) {
        	result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return result;
}
double** minus(double **matrix1, double **matrix2, int n){
    double** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    return result;
}
double** comp(double **matrix1, double **matrix2, int n){
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
    

