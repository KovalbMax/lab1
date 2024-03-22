
#include <stdlib.h>
#include <malloc.h>
/* Разместить в динамической памяти 2 массива – 2 матрицы размерностью 
n на n с элементами типа double (значения n и элементы массивов ввести с консоли).
 А также ввести с консоли знак операции: '+', '-' или '*'.
  Написать функцию, вычисляющую сумму, разность или произведение данных матриц
   (их передать по указателю) и возвращающую указатель на массив-результат. 
  Разместить эту функцию в отдельном модуле (отличном от того, где располагается
   функция main()). Выдать на консоль значения полученного вектора. */

int main(int argc, char *argv[]) {
	int n;
	int znac;
	printf("Vvedite razmernost - ");
	scanf("%d", &n);
	double **matrix1; double **matrix2;
	matrix1=(double**)malloc(n*sizeof(double*));
	matrix2=(double**)malloc(n*sizeof(double*));
	for (int i=0; i<n; i++){
		matrix1[i]=(double**)malloc(n*sizeof(double));
		matrix2[i]=(double**)malloc(n*sizeof(double));
	}
	printf("Vvedite znacheniya 1 matrici - ");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%lf ", &matrix1[i][j]);	
		}
	}
	printf("Vvedite znacheniya 2 matrici - ");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%lf", &matrix2[i][j]);	
		}
	}
	printf("Vvedite znac operacii(+,-,*) - ");
	scanf("%c", &znac);
	for (int i=0; i<n; i++){
		free(matrix1[i]);
		free(matrix2[i]);
	}
	free(matrix1);
	free(matrix2);
	return 0;
}