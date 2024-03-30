//Создать текстовый файл с записями следующего вида:
//Иванов Петр Сергеевич 1975 Сидоров Николай Андреевич 1981….
//Воробьянинов Ипполит Матвеевич 1978 Прочитать данные из этого файла и 
//записать в другой только те строки, которые относятся к родившимся позднее 1980 года.

#include <stdio.h>
int main(){
	char line[1000];
	FILE *newimena=fopen("newnames.txt", "a");
	FILE *imena=fopen("imena.txt", "r");
	fgets(line, 1000, imena);
	printf("%s", line);
	
	fclose(imena);
	fclose(newimena);
	return 0;
}
