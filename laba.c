#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*	Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения.
 Объявить два массива из четырёх элементов типа humen. 
 Ввести с консоли или из фай-ла элементы одного массива и построить на их основе другой,
  упорядочив элементы по годам рождения. Вывести результат. */
enum {lenth = 50};

struct humen{
	char name[20];
	char secname[20];
	int year;
};
struct humen str1[lenth];
struct humen str2[lenth];
int main(int argc, char *argv[]) {

	int n=4;
	for(int i=0;i<n;i++){
		printf("input name: ");
  		gets(str1[i].name);
  		printf("input surname: ");
  		gets(str1[i].secname);
  		printf("input birthday: ");
  		gets(str1[i].year);
	}
  		printf("\n");
  	
	
	return 0;
}