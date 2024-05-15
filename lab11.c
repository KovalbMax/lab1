#include <stdio.h>

double sum(int count, double* array) {
    double total = 0.0;
    for (int i = 0; i < count; i++) {
        total += array[i];
    }
    return total;
}

double max(int count, double* array) {
    double maximum = array[0];
    for (int i = 1; i < count; i++) {
        if (array[i] > maximum) {
            maximum = array[i];
        }
    }
    return maximum;
}

double min(int count, double* array) {
    double minimum = array[0];
    for (int i = 1; i < count; i++) {
        if (array[i] < minimum) {
            minimum = array[i];
        }
    }
    return minimum;
}

double average(int count, double* array) {
    if (count == 0) return 0; // Защита от деления на ноль
    return sum(count, array) / count;
}

int main() {
    int count;
    printf("Vvedite kol-vo elementov: ");
    scanf("%d", &count);

    double values[count];
    printf("Vvedite %d elementov: ", count);
    for (int i = 0; i < count; i++) {
        scanf("%lf", &values[i]);
    }

    printf("Sum: %f\n", sum(count, values));
    printf("Max: %f\n", max(count, values));
    printf("Min: %f\n", min(count, values));
    printf("Average: %f\n", average(count, values));

    return 0;
}