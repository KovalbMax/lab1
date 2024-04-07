#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char  str[81];
	printf("Vvedite stroku do 80 simvolov - ");
	fgets(str, 81, stdin);
	fflush(stdin);
	puts(str);
	for (int m=0; m<81; m++)
	{
		if (str[m]=='a'){
			str[m]='A';
		}
		else if(str[m]=='b'){
			str[m]='B';
		}
		
	}
	printf("\%s", str);
	return 0;
}
 235 235 2 2 3234 3580 
90 ъ
20 