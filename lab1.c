include<stdio.h>
#include<math.h>

int main()
{
    int n=0;
    int a, b, c, d, o;
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
    
    do {
    printf("Если хотите повторить программу напишите 1, если нет - 2");
    scanf("%d",&o);
    if (o==1){
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
    
    printf("x1=%.2lf\nx2=%.lf",x1,x2);}}
    else {
    break;}
    } while(n<5);
    
    return 0;
}