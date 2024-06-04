#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
/*Написать программу вычисления максимального числа из введенных пользователем в виде одной строки. 
Использовать для этого макрос (без функции), на вход которому подается массив чисел и их количество. 
*/ 
#define max(arr, size) ({\ 
 double r = 0, res = 0; \ 
 for(int i = 0; i < size-1; i++){ \ 
  if(arr[i] < arr[i+1]){ \ 
   r = arr[i+1];}} \ 
 res = r; \ 
 printf("\nresult: %.2lf", res);}) 
 
int main() { 
     
    int n = 0, i; 
    double nums[16]; 
    char s[64]; 
    const char cu[2] = " "; 
    printf("Vvedite chisla cheres probel: "); 
    fgets(s, 64, stdin); 
    char *c = strtok(s, cu); 
     
    while (c != NULL) { 
        nums[n] = atof(c); 
        n++; 
        c = strtok(NULL, cu); 
    } 
     
    max(nums, n); 
     
    return 0; 
}