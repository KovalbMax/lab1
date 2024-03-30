#include <stdio.h>
#include <stdlib.h>
/*Создать текстовый файл с записями следующего вида:Иванов Петр Сергеевич 1975
Сидоров Николай Андреевич 1981….Воробьянинов Ипполит Матвеевич 1978
 Прочитать данные из этого файла и записать в другой только те строки, 
 которые относятся к родившимся позднее 1980 года.*/
int main(){
	char str[]="1, 2, 3"; 
	FILE *names = fopen("imena.txt", "r");
	FILE *newnames=fopen("newimena.txt", "w");
	fputs(str, newnames);
	fclose(newnames);
	fclose(names);
	return 0;
	
}
