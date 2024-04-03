#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*	Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения.
 Объявить два массива из четырёх элементов типа humen. 
 Ввести с консоли или из фай-ла элементы одного массива и построить на их основе другой,
  упорядочив элементы по годам рождения. Вывести результат. */
typedef struct humen{
	char name[20];
	char secname[20];
	int year[20];
};
	int getyear(humen kent)
	{	
    	return kent.year[];
	}
	int n=4;
	void sorting(humen kents[]){
		humen tmp;
		for (int i=0; i<n; i--){
			for (int j=0; j<n; j++){
				if (getyear(humen.year[j]) > getyear(humen.year[j+1])){
					tmp=kents[j];
					kents[j]=humen[j+1];
					kents[j+1]= tmp;					
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
    {
        printf("%s %d %d %d sum = %d\n", humen[i].name, humen[i].secname, getyear(kents[i]);
    }

humen str1[4], str2[4];
int main(int argc, char *argv[]) {
	int n=4;
	for(int i=0;i<n;i++){
  		printf("input name: ");
  		gets(str1[i].name);
  		printf("input surname: ");
  		gets(str1[i].secname);
  		printf("input birthday: ");
  		gets(str1[i].year);
  		printf("\n");
  		sorting(kents);
  	
	}
	return 0;
}