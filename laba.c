#include <stdio.h>
#include <stdlib.h>

/*	Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения.
 Объявить два массива из четырёх элементов типа humen. 
 Ввести с консоли или из фай-ла элементы одного массива и построить на их основе другой,
  упорядочив элементы по годам рождения. Вывести результат. */

int main(int argc, char *argv[]) {
		struct humen{
			char name[];
			char secname[];
			int year;
		} humen;
		humen str1[4], str2[4];
		for(i=0;i<4;i++){
  			printf("input name: ");
  			gets(str1[i].name);
  			printf("input surname: ");
  			gets(str1[i].secname);
  			printf("input birthday: ");
  			gets(str1[i].year);
		}
	printf("%s %s %d", humen.)	
	return 0;
}