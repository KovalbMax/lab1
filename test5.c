/*Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double 
(значения n и элементы массивов ввести с консоли). А также ввести с консоли знак операции: '+', '-' или '*'. 
Написать функцию, вычисляющую сумму, разность или произведение данных матриц (их передать по указателю) 
и возвращающую указатель на массив-результат. Разместить эту функцию в отдельном модуле 
(отличном от того, где располагается функция main()). Выдать на консоль значения полученного вектора.
*/
#include <stdio.h>
#include <stdlib.h>
double** creatematrix(int n){
	double** matrix = (double**)malloc(n*sizeof(double*));
	for (int i=0; i<n; i++){
		matrix[i] = (double*)malloc(n*sizeof(double));
	}
	return matrix;
}
double** sum(double** m1, double** m2, int n){
	double** result = creatematrix(n);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			result[i][j] = m1[i][j] + m2[i][j];
		}
	}
	return result;
}
double** minus(double** m1, double** m2, int n){
	double** result = creatematrix(n);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			result[i][j] = m1[i][j] - m2[i][j];
		}
	}
	return result;
}
double** umnoj(double** m1, double** m2, int n){
	double** result = creatematrix(n);
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			for (int k=0; k<n; k++){
				result[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}
	return result;
}
double printmatrix(double** matrix, int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			printf("%.2f ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
int main(){
	int n;
	char znac;
	printf("Vvedite razmernost: ");
	scanf("%d", &n);
	
	
	
	double** matrix1 = creatematrix(n);
	double** matrix2 = creatematrix(n);
	double** result; 
	
	
	printf("Vvedite elementi 1 matrici:");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%lf", &matrix1[i][j]);
		}
	}
	printf("Vvedite elementi 2 matrici:");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			scanf("%lf", &matrix2[i][j]);
		}
	}
	printf("Vvedite znac:");
	scanf(" %c", &znac);
	if (znac == '+'){
		result = sum(matrix1, matrix2, n);
	}
	else if (znac == '-'){
		result = minus(matrix1, matrix2, n);
	}
	else if (znac == '*'){
		result = umnoj(matrix1, matrix2, n);
	}
	
	
	printmatrix(result, n);
	for (int i=0; i<n; i++){
		free(matrix1[i]);
		free(matrix2[i]);
		free(result[i]);
	}
	free(matrix1);
	free(matrix2);
	free(result;)
	return 0; 
}