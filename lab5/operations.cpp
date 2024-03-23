#include <stdlib.h>
#include <malloc.h>
/*Написать функцию, вычисляющую сумму, разность или произведение данных матриц
   (их передать по указателю) и возвращающую указатель на массив-результат. 
  Разместить эту функцию в отдельном модуле (отличном от того, где располагается
функция main()). Выдать на консоль значения полученного вектора. */
int n;
typedef double (*TFunc)();
double *sum(int n, double m1, double m2, double result){
	for (int i=0; i<n ; i++){
		for (int j=0; j<n ; j++){
			result[i][j] += m1[i][j] + m2[i][j]
		}
	}
	return result 
}