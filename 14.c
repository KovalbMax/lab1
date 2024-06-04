#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_random_numbers(const char *filename, int N) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        fprintf(file, "%d\n", rand() % 100);
    }

    fclose(file);
}

void process_numbers(const char *input_filename, const char *output_filename) {
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    if (!input_file || !output_file) {
        printf("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int number;
    while (fscanf(input_file, "%d", &number) == 1) {
        if (number % 35 == 0) {
            fprintf(output_file, "ПЯТЬСЕМЬ\n");
        } else if (number % 5 == 0) {
            fprintf(output_file, "Пять\n");
        } else if (number % 7 == 0) {
            fprintf(output_file, "Семь\n");
        } else {
            fprintf(output_file, "%d\n", number);
        }
    }

    fclose(input_file);
    fclose(output_file);
}

void create_matrix_and_calculate(const char *filename, int M) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    int *numbers = NULL;
    int count = 0;
    int number;

    while (fscanf(file, "%d", &number) == 1) {
        numbers = realloc(numbers, sizeof(int) * (count + 1));
        numbers[count++] = number;
    }
    fclose(file);

    int N = count;
    int rows = N / M;
    
    int matrix[rows][M];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < M; j++) {
            matrix[i][j] = numbers[i * M + j];
        }
    }

    free(numbers);

    printf("Matrix:\n");
    int row_sum[rows];
    int col_sum[M];

    for (int i = 0; i < rows; i++) {
        row_sum[i] = 0;
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
            row_sum[i] += matrix[i][j];
        }
        printf("\n");
    }

    for (int j = 0; j < M; j++) {
        col_sum[j] = 0;
        for (int i = 0; i < rows; i++) {
            col_sum[j] += matrix[i][j];
        }
    }

    printf("\nRow sums:\n");
    for (int i = 0; i < rows; i++) {
        printf("%d ", row_sum[i]);
    }
    printf("\n");

    printf("Column sums:\n");
    for (int j = 0; j < M; j++) {
        printf("%d ", col_sum[j]);
    }
    printf("\n");
}

int main() {
    int N, M;
    printf("Enter the number of random numbers (N): ");
    scanf("%d", &N);
    printf("Enter the number of columns (M): ");
    scanf("%d", &M);

    generate_random_numbers("input.txt", N);
    process_numbers("input.txt", "output.txt");
    create_matrix_and_calculate("input.txt", M);

    return 0;
}