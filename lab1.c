#include<stdio.h>
#include<math.h>

int main()
{
    int a, b, c, d;
    double x1 ,x2;
    printf("Напишите a,b,c через пробел - ");
    scanf("%d%d%d",&a,&b,&c);
    d=b*b - 4*a*c;
    if (d<0){
    printf("Дискриминант меньше 0");
    }
    if (d==0){
    x1=-b/(2*a);
    
    printf("x1=%lf",x1);
    }
    if (d>0){
    x1=(-b+sqrt(d))/(2*a);
    x2=(-b-sqrt(d))/(2*a);
    
    printf("x1=%.2lf\nx2=%.lf",x1,x2);}
    return 0;
}
