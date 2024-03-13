double **sum(double **a, double **b, int n) {
    double **result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    return result;
}

double **multiply(double **a, double **b, int n) {
    double **result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return result;
}

double **subtract(double **a, double **b, int n) {
    double **result = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        result[i] = (double *)malloc(n * sizeof(double));
        for (int j = 0; j < n; j++) {
            result[i][j] = a[i][j] - b[i][j];
        }
    }
    return result;
}