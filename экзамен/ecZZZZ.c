#include <stdio.h>
#include <stdlib.h>
#include <time.h>



double** creatematrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int));
    }
    return matrix;
}
double** sum(int** matrix1, int** matrix2, int n) {
    int** result = creatematrix(n);
    for (int i = 0; i<n; i++){
    	for (int j = 0; j < n; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
	}
        
    return result;
}


double** umnoj(int** matrix1, int** matrix2, int n) {
    int** result = creatematrix(n);
    for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++){
    		for (int k = 0; k < n; k++) {
            result[i][j] += matrix1[i][k] * matrix2[k][j];
        	}
    	}	
	}
        
    return result;
}
int main(){
	int n;
	printf("Vvedite razmernost (n*n) - ");
	scanf("%d", &n);
	int** m1 = creatematrix(n);
	int** m2 = creatematrix(n);
	int** matrix1 = creatematrix(n);
	int** matrix2 = creatematrix(n);
	int** result1 = creatematrix(n);
	int** result2 = creatematrix(n);
	srand(time(NULL));
	clock_t t_start, t_end;
	t_start = clock();
	
	FILE * file = fopen("input.txt", "w");
	for (int i=0; i<n; i++){
		for (int j=0;j<n; j++){
			matrix1[i][j] = rand() % 100;
			fprintf(file, "%3d", matrix1[i][j]);
		}
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
	for (int i=0; i<n; i++){
		for (int j=0;j<n; j++){
			matrix2[i][j] = rand() % 100;
			fprintf(file, "%3d", matrix2[i][j]);
		}
		fprintf(file, "\n");
	}
	
	//fscanf(file, "%d");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
      		fscanf(file, "%d %d", &m1[i][j], &m2[i][j]);
		}
	}

	fclose(file);
	FILE * file2 = fopen("output.txt", "w");
	
	result1 = sum(m1, m2, n);
	result2 = umnoj(m1, m2, n);
	
	
  	fprintf(file2, "result1:\n");
  	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
      		fprintf(file2, "%d ", result1[i][j]);
    	}
    	fprintf(file2, "\n");
  	}


  	fprintf(file2, "\nresult1:\n");
  	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
      		fprintf(file2, "%d ", result2[i][j]);
    	}
    	fprintf(file2, "\n");
  	}
  	
  	
  	file = fopen("input1.txt", "r");
  	
	int number;
    while (fscanf(file, "%d", &number) != EOF) {
        if (number == 0) {
           // fprintf(file, "Zero");
     		printf("Zero\n",number);           
        }else{
    	    printf("%d \n",number);
        }
        
	}
	
	double duration = (clock() - t_start)/(double)CLOCKS_PER_SEC;
	printf("\n");
	printf("Need_time duration  = %f", duration);
	fclose(file);
	fclose(file2);
	for (int i=0; i<n; i++){
		free(matrix1[i]);
		free(matrix2[i]);
		free(result1[i]);
		free(result2[i]);
		free(m1[i]);
		free(m2[i]);
	}
	free(matrix1);
	free(matrix2);
	free(result1);
	free(result2);
	free(m1);
	free(m2);

	return 0;
}