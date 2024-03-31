//Создать текстовый файл с записями следующего вида:
//Иванов Петр Сергеевич 1975 Сидоров Николай Андреевич 1981….
//Воробьянинов Ипполит Матвеевич 1978 Прочитать данные из этого файла и 
//записать в другой только те строки, которые относятся к родившимся позднее 1980 года.
#include <stdio.h>
#include <string.h>
int main(){
	char str[50];
	FILE * names= fopen("imena.txt", "r");
	FILE * newnames = fopen("newna.txt", "a");
	while (fgets(str, 50, names) != NULL){
		int length = strlen(str);
    	int index = length - 1;
    	printf("Last: %c", str[index]);
		
    }	
			

			
	
	fclose(names);
	fclose(newnames);
	return 0;
}
