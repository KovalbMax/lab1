#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

#define max(arr, size) ({ \ 
    double res = arr[0]; \ 
    for(int i = 0; i < size; i++){ \ 
        if(arr[i] > res){ \ 
            res = arr[i];}} \ 
    printf("\nresult: %.2lf", res);}) 
#define average(arr, size) ({ \ 
    double sum = 0, aver; \ 
    for(int i = 0; i < size; i++){ \ 
      sum += arr[i]; \
    }\
    aver=sum/size;\
    printf("\nAverage: %.2lf", aver);})

int main() { 
     
    int n = 0; 
    double nums[16]; 
    char s[64]; 
    const char cu[2] = " "; 
    printf("Vvedite chisla cherez pobel: "); 
    fgets(s, 64, stdin); 
    char *c = strtok(s, cu); 
     
    while (c != NULL) { 
        nums[n] = atof(c); 
        n++; 
        c = strtok(NULL, cu); 
    } 
     
    max(nums, n); 
    average(nums, n);
     
    return 0; 
}
