//Написать функцию, вычисляющую сумму, разность или произведение данных матриц
//   (их передать по указателю) и возвращающую указатель на массив-результат. 
//  Разместить эту функцию в отдельном модуле (отличном от того, где располагается
//  функция main()). Выдать на консоль значения полученного вектора. 

int n;
double sum(double a[n][n], double b[n][n]){
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			return a[i][j] + b[i][j];
			
		}
	}
}

double proiz(double a[n][n], double b[n][n]){
	for (int i=0; i<2; i++){
		for (int j=0; j<2; j++){
			for (int k=0; k<2; k++) {
				return a[i][k] * b[k][j];
				 
			
			}
	
		}
	}
}
double minus(double a[n][n], double b[n][n]){
	for (int i=0; i<n; i++){
		for (int k=0; k<n;k++){
			return a[i][k] - b[i][k];
			
		}
	}
}