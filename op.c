/*double creatematrix1(double** matrix1, int n){

	for (int i=0; i<n; i++){
		matrix1[i] = (double *)malloc(n*sizeof(double));
		}
	return 0;
}
double creatematrix2(double** matrix2, int n){
	for (int i=0; i<n; i++){
		matrix2[i] = (double *)malloc(n*sizeof(double));
		}
	return 0;
*/
double ** sum(double **matrix1, double ** matrix2, int n){
	double** result = (double**)malloc(n*sizeof(double*));
	for (int i=0; i<n; i++){
		result[i] = (double *)malloc(n*sizeof(double));
		for (int j=0; j<n; j++){
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	return result;
}
double ** minus(double **matrix1, double ** matrix2, int n){
	double** result = (double**)malloc(n*sizeof(double*));
	for (int i=0; i<n; i++){
		result[i] = (double *)malloc(n*sizeof(double));
		for (int j=0; j<n; j++){
			result[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	return result;
}
double ** umnoj(double **matrix1, double ** matrix2, int n){
	double** result = (double**)malloc(n*sizeof(double*));
	for (int i=0; i<n; i++){
		result[i] = (double *)malloc(n*sizeof(double));
		for (int j=0; j<n; j++){
			for (int k=0; k<n; k++)
				result[i][j] = matrix1[i][k] * matrix2[k][j];
		}
	}
	return result;
}