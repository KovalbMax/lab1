#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char surname[50];
    int yearOfBirth;
    char gender;
    float height;
} Person;

// Объявляем функцию сравнения (compare) здесь, как показано в предыдущем примере

void printPeople(Person people[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %s, %d, %c, %.2f m\n", people[i].name, people[i].surname, people[i].yearOfBirth, people[i].gender, people[i].height);
    }
}

int readPeopleFromFile(const char* filename, Person people[], int maxPeople) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }
    
    int count = 0;
    while(count < maxPeople && fscanf(file, "%49s %49s %d %c %f", people[count].name, 
          people[count].surname, &people[count].yearOfBirth, 
          &people[count].gender, &people[count].height) == 5) {
        count++;
    }
    
    fclose(file);
    return count;
}

int main() {
    const int maxPeople = 100;
    Person people[maxPeople];
    int count;
    
    // Вместо чтения данных с консоли, мы загрузим их из файла
    count = readPeopleFromFile("ludi.txt", people, maxPeople);

    // Выполнение сортировки и печати, как в предыдущих примерах
    // ...

    return 0;
}
