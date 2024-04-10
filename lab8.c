#include <stdio.h>
#include <stdlib.h>

/* Создать текстовый файл с записями, включающие имя/фамилию человека, год рождения, пол и рост (в метрах).
 Упорядочить элементы по году рождения, имени/фамилии, полу или росту. Вывести результат. 
 Указать элемент, по которому следует упорядочить, через консоль.
  А также реализовать возможность задавать несколько полей для упорядочивания. */
struct human{
	char name[50];
	char surname[50];
	int year;
	char gender;
	double hight;
};

int main(int argc, char *argv[]) {
	int n=4;
	struct human p[100]; 
	FILE * people = fopen("people.txt", "r");
	for (int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			fscanf(people, "%s %s %d %c %lf", p.name, p.surname, p.year, p.gender, p.hight);
			
		}
	}
	
	
	
	fclose(people);
	return 0;
}