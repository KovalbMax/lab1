#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int** createMatrix(int rows, int cols) {
  int** matrix = (int**)malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    matrix[i] = (int*)malloc(cols * sizeof(int));
  }
  return matrix;
}

void createInputFile(int rows, int cols) {
  FILE* file = fopen("input.txt", "w");
  srand(time(NULL));

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      int a = rand() % 100;
      fprintf(file, "%d ", a); // Генерируем случайные числа от 0 до 99
      printf("%d ", a);
    }
    fprintf(file, "\n");
    printf("\n");
  }

  fclose(file);
}

void readMatrixFromFile(int** matrix, int rows, int cols) {
  FILE* file = fopen("input.txt", "r");

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      fscanf(file, "%d", &matrix[i][j]);
    }
  }

  fclose(file);
}

void multiplyMatrices(int** matrix1, int** matrix2, int** result, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      for (int k = 0; k < cols; k++){
        for (int b = 0; b < rows; b++){
          result[i][j] = matrix1[i][k] * matrix2[b][j];
      }
    }
      
    }
  }
}

void addMatrices(int** matrix1, int** matrix2, int** result, int rows, int cols) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      result[i][j] = matrix1[i][j] + matrix2[i][j];
    }
  }
}

int main() {
  int rows, cols;
  printf("Введите количество строк и столбцов матрицы: ");
  scanf("%d %d", &rows, &cols);

  createInputFile(rows, cols);

  int** matrix1 = createMatrix(rows, cols);
  int** matrix2 = createMatrix(cols, rows);
  int** result1 = createMatrix(rows, cols);
  int** result2 = createMatrix(rows, cols);
  
  clock_t t_start,t_end;
  t_start = clock(); 

  readMatrixFromFile(matrix1, rows, cols);
  readMatrixFromFile(matrix2, rows, cols);



  multiplyMatrices(matrix1, matrix2, result1, rows, cols);
  addMatrices(matrix1, matrix2, result2, rows, cols);




  FILE* outputFile = fopen("output.txt", "w");

  fprintf(outputFile, "Результат умножения матриц:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      fprintf(outputFile, "%d ", result1[i][j]);
      printf("%d ", result1[i][j]);
    }
    fprintf(outputFile, "\n");
    printf("\n");
  }

  fprintf(outputFile, "\nРезультат сложения матриц:\n");
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      fprintf(outputFile, "%d ", result2[i][j]);
      printf("%d ", result2[i][j]);
    }
    fprintf(outputFile, "\n");
    printf("\n");
  }



  fclose(outputFile);

  for (int i = 0; i < rows; i++) {
    free(matrix1[i]);
    free(matrix2[i]);
    free(result1[i]);
    free(result2[i]);
  }

  free(matrix1);
  free(matrix2);
  free(result1);
  free(result2);
  double duration = (clock() - t_start) / (double) CLOCKS_PER_SEC;
 
    printf("Need_time duration  = %f",duration);


  return 0;
}