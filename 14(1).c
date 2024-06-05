#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Функция для вычисления количества дней между двумя датами
int daysBetween(int y1, int m1, int d1, int y2, int m2, int d2) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days1 = d1, days2 = d2;

    for (int i = 0; i < m1 - 1; i++) days1 += days[i];
    for (int i = 0; i < m2 - 1; i++) days2 += days[i];

    if (m1 > 2 && y1 % 4 == 0 && (y1 % 100 != 0 || y1 % 400 == 0)) days1++;
    if (m2 > 2 && y2 % 4 == 0 && (y2 % 100 != 0 || y2 % 400 == 0)) days2++;

    int yearsInDays1 = y1 * 365 + y1 / 4 - y1 / 100 + y1 / 400;
    int yearsInDays2 = y2 * 365 + y2 / 4 - y2 / 100 + y2 / 400;

    return yearsInDays2 + days2 - (yearsInDays1 + days1);
}

// Функция создания квадратной матрицы размера m*m, заполненной случайными числами от 0 до 9
int** createMatrix(int m) {
    int matrix = (int)malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        matrix[i] = (int*)malloc(m * sizeof(int));
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 10;
        }
    }
    return matrix;
}

// Функция для вычисления суммы всех элементов матрицы
int sumMatrix(int** matrix, int m) {
    int sum = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Функция для освобождения памяти, занятой матрицей
void freeMatrix(int** matrix, int m) {
    for (int i = 0; i < m; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Функция для вывода матрицы в файл
void writeMatrixToFile(FILE* file, int** matrix, int m, int sum) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            fprintf(file, "%d ", matrix[i][j]);
        }
        fprintf(file, "\n");
    }
    fprintf(file, "Sum: %d\n\n", sum);
}

int main() {
    clock_t t_start = clock();

    // Чтение даты из файла input.txt
    FILE* input = fopen("input.txt", "r");
    if (input == NULL) {
        printf("Cannot open input.txt\n");
        return 1;
    }

    int year, month, day;
    fscanf(input, "%d %d %d", &year, &month, &day);
    fclose(input);

    // Получение текущей даты
    time_t now = time(NULL);
    struct tm* current_time = localtime(&now);

    int days = daysBetween(current_time->tm_year + 1900, current_time->tm_mon + 1, current_time->tm_mday, year, month, day);
    printf("Days until the date: %d\n", days);

    // Генерация матриц
    srand(time(NULL));
    int m;
    printf("Enter the size of the square matrix: ");
    scanf("%d", &m);

    int** currentMatrix = createMatrix(m);
    int currentSum = sumMatrix(currentMatrix, m);

    int** matchedMatrix = NULL;
    int matchedSum = 0;

    int count = 1;

    while (1) {
        if (matchedMatrix != NULL && currentSum == matchedSum) {
            break;
        }

        freeMatrix(currentMatrix, m);
        currentMatrix = createMatrix(m);
        currentSum = sumMatrix(currentMatrix, m);

        if (matchedMatrix == NULL) {
            matchedMatrix = currentMatrix;
            matchedSum = currentSum;
            currentMatrix = createMatrix(m);
            currentSum = sumMatrix(currentMatrix, m);
        }

        count++;
    }

    // Вывод матриц в файл output.txt
    FILE* output = fopen("output.txt", "w");
    fprintf(output, "Matrix 1:\n");
    writeMatrixToFile(output, matchedMatrix, m, matchedSum);

    fprintf(output, "Matrix 2:\n");
    writeMatrixToFile(output, currentMatrix, m, currentSum);

    fprintf(output, "Number of matrices generated: %d\n", count);

    fclose(output);

    // Освобождение памяти
    freeMatrix(matchedMatrix, m);
    freeMatrix(currentMatrix, m);

    // Расчет времени работы программы
    clock_t t_end = clock();
    double duration = (double)(t_end - t_start) / CLOCKS_PER_SEC;
    printf("Execution time: %f seconds\n", duration);

    return 0;
}