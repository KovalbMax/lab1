#include <stdio.h>

double Digits(int n) {
    if (n / 10 != 0) {
        Digits(n / 10);
    }
    printf("%d ", n % 10);
    return 0;
}

double DigitsReverse(int n) {
    printf("%d ", n % 10);
    if (n / 10 != 0) {
        DigitsReverse(n / 10);
        return 0;
    }
}
double WordsReverse(char str[], int len) {
    printf("%c ", str[len - 1]);
    if (len > 1) {
        WordsReverse(str, len - 1);
        return 0;
    }
}
int main() {
	char p[100];
	printf("Enter a string: ");
    scanf("%s", p); 
    int length = strlen(p);
    int N;
    printf("print N: ");
    scanf("%d", &N);

    printf("v obichnom poryadke: ");
    Digits(N);
    
    printf("\nv obratnom poryadke: ");
    DigitsReverse(N);
	printf("\nbukvi : ");
	WordsReverse(p, length);
    return 0;
}
