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
	char first_name[50];
    char last_name[50];
    char middle_name[50];

    while (fscanf(names, "%s %s %s %d", first_name, last_name, middle_name, &r) == 4) {
        if (r > 1980) {
            fprintf(newnames, "%s %s %s %d\n", first_name, last_name, middle_name, r);
        }
    }

	fclose(names);
	fclose(newnames);
	return 0;
}