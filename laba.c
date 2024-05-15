#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int lenth = 50;

struct human {
    char name[50];
    char surname[50];
    int year;
};

// Функция qsort
int compare(const void *a, const void *b) {
    struct human *h1 = (struct human *)a;
    struct human *h2 = (struct human *)b;
    return (*h1).year - (*h2).year;
}

int main(int argc, char *argv[]) {
    struct human human1[lenth];
    struct human human2[lenth];
    int n = 4;


    printf("Please, input data:\n");
    for (int i = 0; i < n; i++) {
        printf("Name: ");
        scanf("%s", human1[i].name);
        printf("Surname: ");
        scanf("%s", human1[i].surname);
        printf("Year: ");
        scanf("%d", &human1[i].year);
    }
    memcpy(human2, human1, sizeof(human1));

    // Сортировка qsort
    qsort(human2, n, sizeof(struct human), compare);


    for (int i = 0; i < n; i++) {
        printf("Name: %s, Surname: %s, Year: %d\n", human2[i].name, human2[i].surname, human2[i].year);
    }

    return 0;
}