#include <stdio.h>
#include <stdarg.h>

double sum(int count, ...) {
    va_list args;
    va_start(args, count);

    double result = 0.0;
    for (int i = 0; i < count; i++) {
        result += va_arg(args, double);
    }

    va_end(args);
    return result;
}

double max(int count, ...) {
    va_list args;
    va_start(args, count);

    double max_value = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        double current = va_arg(args, double);
        if (current > max_value) {
            max_value = current;
        }
    }

    va_end(args);
    return max_value;
}

double min(int count, ...) {
    va_list args;
    va_start(args, count);

    double min_value = va_arg(args, double);
    for (int i = 1; i < count; i++) {
        double current = va_arg(args, double);
        if (current < min_value) {
            min_value = current;
        }
    }

    va_end(args);
    return min_value;
}

double average(int count, ...) {
    va_list args;
    va_start(args, count);

    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, double);
    }

    va_end(args);
    return total / count;
}

int main() {
    int n;
    printf("number of digits: ");
    scanf("%d", &n);

    double values[n];
    printf("digits: ");
    for (int i = 0; i < n; i++) {
        scanf("%lf", &values[i]);
    }

    double result_sum = sum(n, values[0], values[1], values[2], values[3], values[4]); // Пример вызова функции sum с 5 числами
    printf("Sum: %f\n", result_sum);

    double result_max = max(n, values[0], values[1], values[2], values[3], values[4]); // Пример вызова функции max с 5 числами
    printf("Max: %f\n", result_max);

    double result_min = min(n, values[0], values[1], values[2], values[3], values[4]); // Пример вызова функции min с 5 числами
    printf("Min: %f\n", result_min);

    double result_avg = average(n, values[0], values[1], values[2], values[3], values[4]); // Пример вызова функции average с 5 числами
    printf("Average: %f\n", result_avg);

    return 0;
}
