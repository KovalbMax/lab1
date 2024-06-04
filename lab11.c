#include <stdio.h>
#include <stdarg.h>

double calculate_sum(int num, ...) {
    va_list args;
    double sum = 0;
    
    va_start(args, num);
    for (int i = 0; i < num; i++) {
        sum += va_arg(args, double);
    }
    va_end(args);
    
    return sum;
}

double calculate_max(int num, ...) {
    va_list args;
    double max = -999999; // Используем начальное значение, которое гарантированно меньше любого другого значения
    
    va_start(args, num);
    for (int i = 0; i < num; i++) {
        double current = va_arg(args, double);
        if (current > max) {
            max = current;
        }
    }
    va_end(args);
    
    return max;
}

double calculate_min(int num, ...) {
    va_list args;
    double min = 999999; // Используем начальное значение, которое гарантированно больше любого другого значения
    
    va_start(args, num);
    for (int i = 0; i < num; i++) {
        double current = va_arg(args, double);
        if (current < min) {
            min = current;
        }
    }
    va_end(args);
    
    return min;
}

double calculate_average(int num, ...) {
    va_list args;
    double sum = 0;
    
    va_start(args, num);
    for (int i = 0; i < num; i++) {
        sum += va_arg(args, double);
    }
    va_end(args);
    
    return sum / num;
}

int main() {
    double sum_result = calculate_sum(5, 10.5, 20.7, 15.2, 8.9, 12.1);
    printf("Sum: %.2f\n", sum_result);

    double max_result = calculate_max(4, 10.5, 20.7, 15.2, 8.9);
    printf("Max: %.2f\n", max_result);

    double min_result = calculate_min(4, 10.5, 20.7, 15.2, 8.9);
    printf("Min: %.2f\n", min_result);

    double avg_result = calculate_average(4, 10.5, 20.7, 15.2, 8.9);
    printf("Average: %.2f\n", avg_result);

    return 0;
}
