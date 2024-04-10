#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*	Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения.
 Объявить два массива из четырёх элементов типа humen. 
 Ввести с консоли или из фай-ла элементы одного массива и построить на их основе другой,
  упорядочив элементы по годам рождения. Вывести результат. */
enum {lenth = 50};

struct human{
	char name[50];
	char surname[50];
	int year;
};
struct human human1[lenth];
struct human human2[lenth];
int main(int argc, char *argv[]) {

	int n=4;
	// Ввод данных
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
	
	
	// Сортировка 
  	for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (human2[i].year > human2[j].year) {
                struct human p = human2[i];
                human2[i] = human2[j];
                human2[j] = p;
            }
        }
    }

    // Вывод отсортированного массива
    for (int i = 0; i < 4; i++) {
        printf("Name: %s, Surname: %s, Year: %d\n", human2[i].name, human2[i].surname, human2[i].year);
    }
  	
	
	return 0;
}