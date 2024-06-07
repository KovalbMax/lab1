#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int days_difference(struct tm *date1, struct tm *date2) {
    time_t time1 = mktime(date1);
    time_t time2 = mktime(date2);

    int difference = abs(difftime(time1, time2)) / (60 * 60 * 24);

    return difference;
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Не удалось открыть файл input.txt\n");
        return 1;
    }

    int day, month, year;
    fscanf(file, "%d.%d.%d", &day, &month, &year);
    fclose(file);

    time_t t = time(NULL);
    struct tm *current_time = localtime(&t);

    struct tm input_date = {0};
    input_date.tm_mday = day;
    input_date.tm_mon = month - 1;
    input_date.tm_year = year - 1900;

    int difference = days_difference(&input_date, current_time);

    printf("Разница в днях между %02d.%02d.%d и сегодняшней датой: %d\n", day, month, year, difference);

    return 0;
}
