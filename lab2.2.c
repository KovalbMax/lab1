#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */




int main(int argc, char *argv[]) 
{
	int arr[2][2];
	for (int m=0; m<2; m++)
   {
        for (int c=0; c<2; c++)
		{
		printf("Write matrix with space");
		printf("arr[%d][%d] = ", 	m, c);
		scanf("%lf", &arr[m][c]);
		}
	}

printf("New matrix: \n");
printf("\%d %d\n%d %d", arr[0][0]*arr[0][0], arr[0][1]*arr[0][1], arr[1][0]*arr[1][0], arr[1][1]*arr[1][1]);

return 0;
}