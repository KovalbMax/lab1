//Создать текстовый файл с записями следующего вида:
//Иванов Петр Сергеевич 1975 Сидоров Николай Андреевич 1981….
//Воробьянинов Ипполит Матвеевич 1978 Прочитать данные из этого файла и 
//записать в другой только те строки, которые относятся к родившимся позднее 1980 года.
#include <stdio.h>
#include <string.h>
int main(){
	int r;
	char str[100];
	FILE * names= fopen("imena.txt", "r");
	FILE * newnames = fopen("newnames.txt", "w");
	while (fgets(str, sizeof(str), names)) {
		sscanf(str,"%*s %*s %*s %d", &r);
		if (r>1980){
			fputs(str, newnames);
		}
	}
	fclose(names);
	fclose(newnames);
	return 0;
}мвлполвплавппвпвпв