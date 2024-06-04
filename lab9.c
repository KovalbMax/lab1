#include <stdio.h> 
#include <stdlib.h>

#include <string.h>


void space(char *input, char *output) {
    int i = 0;
    while (input[i] != '\0') {
        if (input[i] == '+' || input[i] == '-') {
            // Добавить пробел перед оператором, если это не начало строки и перед ним нет пробела
            if (i > 0 && input[i - 1] != ' ') {
                *output++ = ' ';
            }
            *output++ = input[i];
            // Добавить пробел после оператора, если после него нет пробела и это не конец строки
            if (input[i + 1] != ' ' && input[i + 1] != '\0') {
                *output++ = ' ';
            }
        } else {
            *output++ = input[i];
        }
        i++;
    }
    *output = '\0'; 
}


double calculator(char* expression) {
    char* token;
    double result = 0;
    token = strtok(expression, " ");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            token = strtok(NULL, " ");
            result += atof(token);
        } else if (strcmp(token, "-") == 0) {
            token = strtok(NULL, " ");
            result -= atof(token);
        } else {
            result += atof(token);
        }
        token = strtok(NULL, " ");
    }
    return result;
}

int main() {
    char phrase[100], result_phrase[150]; 

    printf("Введите выражение: ");
    fgets(phrase, sizeof(phrase), stdin); 
    phrase[strlen(phrase) - 1] = '\0'; 

    space(phrase, result_phrase); 
    
    double result = calculator(result_phrase); 

    printf("Результат: %.2lf\n", result); 

    return 0;
}
