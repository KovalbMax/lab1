#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* ЗАДАНИЕ 4
 Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон. Разместить 
 их в отдельном модуле (отличном от того, где располагается функция main( )). Ввести с консоли значения длин сторон треугольника
 (с проверкой на корректность неравенства треугольника)
 и выдать на консоль вычисленные с помощью написанных функций значения его периметра и площади */
double P(double a, double b, double c)
{
	return a+b+c;
}
double S(double a, double b, double c)
{
	int g;
	g=P(a,b,c)/2;
	return sqrt(g*(g-a)*(g-b)*(g-c));
}


int main(int argc, char *argv[]) {
	double s, p;
	double a,b,c;
	printf("Print a, b, c - ");
	scanf("%lf%lf%lf", &a,&b,&c);
	if (((a+b)<=c) || ((a+c)<=b) ||((c+b)<=a))
	{
		printf("Not correct!");
	}
	else{
		p=P(a,b,c);
		s=S(a,b,c);
		printf("Perimetr =%.2f\n", p);
		printf("Square =%.2f\n", s);
	}
	
	
	return 0;
}