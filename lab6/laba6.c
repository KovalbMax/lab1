//Создать текстовый файл с записями следующего вида:
//Иванов Петр Сергеевич 1975 Сидоров Николай Андреевич 1981….
//Воробьянинов Ипполит Матвеевич 1978 Прочитать данные из этого файла и 
//записать в другой только те строки, которые относятся к родившимся позднее 1980 года.
#include <stdio.h>
#include <string.h>
int main(){
	char num[2];
	double r;
	char str[50];
	FILE * names= fopen("imena.txt", "r");
	FILE * newnames = fopen("newna.txt", "a");
	while (fgets(str, 50, names) != NULL){
		for (int i=0; i<51; i++){
			if (str[i]=='1' && str[i+1]=='9'){
				num[0]=str[i+2];
				num[1]=str[i+3];
				r = atof(num);
				if (r > 80){
					fputs(str, newnames);
					printf("%s", str);
				}
			}
		}

		
    }	
			

			
	
	fclose(names);
	fclose(newnames);
	return 0;
}
