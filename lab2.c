#include<stdio.h>

int main(int argc, char *argv[])
{
    double array[3][3]={0};
    double glavn, pob; 
    for (int i=0;i<3;i++)
	{
	for (int j=0;j<3;j++)
    {
	printf("Write matrix with space");
    printf("array[%d][%d] = ", i, j);
    scanf("%lf", &array[i][j]);

    }
    }
glavn= array[0][0]+array[1][1]+array[2][2];
pob= array[0][2]+array[1][1]+array[2][0];
printf("\nSum glavnoy diag: %2lf\n", glavn);
printf("\nSum pobochnoy diag: %2lf\n", pob);



printf("2 part");
int arr[2][2]={0};
int p[2][2];
for (int m=0; m<2; m++){
	for (int n=0; n<2; n++){

{
printf("Write matrix with space");
printf("arr[%d][%d] = ", m, n);
scanf("%lf", &arr[m][n]);
		}
	}
}

p[0][0]=arr[0][0]*arr[0][0]+arr[0][1]*arr[1][0];
p[1][0]=arr[1][0]*arr[0][0]+arr[1][1]*arr[1][0];
p[0][1]=arr[0][0]*arr[0][1]+arr[0][1]*arr[1][1];
p[1][1]=arr[1][0]*arr[0][1]+arr[1][1]*arr[1][1];
printf("\nProizvedenie: \%d %d\n%d %d", p[0][0], p[1][0], p[0][1], p[1][1]);

return 0;
}