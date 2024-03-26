#include <stdlib.h>
#include <malloc.h>
/*Написать функцию, вычисляющую сумму, разность или произведение данных матриц
   (их передать по указателю) и возвращающую указатель на массив-результат. 
  Разместить эту функцию в отдельном модуле (отличном от того, где располагается
функция main()). Выдать на консоль значения полученного вектора. */
int** operations(double** matrix1, double** matrix2, int n ,char znac) {
    int** result = (double**)malloc(n * sizeof(double*));
    for (int i = 0; i < rows; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
        for (int j = 0; j <n; j++) {
            if (znac == '+') {
                result[i][j] = matrix1[i][j] + matrix2[i][j];
            } else if (znac == '-') {
                result[i][j] = matrix1[i][j] - matrix2[i][j];
            } else if (znac == '*') {
                result[i][j] = 0;
                for (int k = 0; k < cols; k++) {
                    result[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }
    unt l;
    return result;
}