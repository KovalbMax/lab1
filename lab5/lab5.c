
#include <stdlib.h>
#include <malloc.h>
#include"Untitled1"
/* Разместить в динамической памяти 2 массива – 2 матрицы размерностью 
n на n с элементами типа double (значения n и элементы массивов ввести с консоли).
 А также ввести с консоли знак операции: '+', '-' или '*'.
  Написать функцию, вычисляющую сумму, разность или произведение данных матриц
   (их передать по указателю) и возвращающую указатель на массив-результат. 
  Разместить эту функцию в отдельном модуле (отличном от того, где располагается
   функция main()). Выдать на консоль значения полученного вектора. */


int main(int argc, char *argv[]) {
	int n;
	double p[n][n];
	double m[n][n];
	double o[n][n];
	printf("Vvedite razmer");
	scanf("%d", &n);
	double **matrix1 = (double **)malloc(n * sizeof(double *));
	double **matrix2 = (double **)malloc(n * sizeof(double *));
	for (int i=0; i<n ; i++){
		matrix1[i]=(double*)malloc(n*sizeof(double));
		matrix2[i]=(double*)malloc(n*sizeof(double));
	}
	printf("Vvedite elementi 1-oi matrici");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%lf", &matrix1[i][j]);
		}
	}
	printf("Vvedite elementi 2-oi matrici");
	for (int i=0; i<n; i++){
		for (int j=0; j<n;j++){
			scanf("%lf", &matrix2[i][j]);
		}
	}
	for (int i=0; i<n;i++){
		free(matrix1[i]);
		free(matrix2[i]);
	}
	free(matrix1);
	free(matrix2);
	printf("Vvedite znac(+,-,*)");
	char znac; 
	scanf("%c", &znac);
	if (znac=='+'){
		for (int i=0; i<n ; i++){
			for (int j=0; j<n ; j++){
				p[i][j] += sum(matrix1[n][n],matrix2[n][n]);
			}
		}
		
	}
	else if(znac=='-'){
		for (int i=0; i<n ; i++){
			for (int j=0; j<n ; j++){
				p[i][j] += minus(matrix1[n][n],matrix2[n][n]);
			}
		}
	}
	else if(znac=='*'){
		for (int i=0; i<n ; i++){
			for (int j=0; j<n ; j++){
				p[i][j] += proiz(matrix1[n][n],matrix2[n][n]);
			}
		}
	}
	return 0;
}