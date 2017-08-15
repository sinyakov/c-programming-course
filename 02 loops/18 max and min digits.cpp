// Необходимо вывести наименьшую и наибольшую цифры данного числа через пробел.
#include <iostream>

int minDigit(int num){
    int min = 9;
    while(num != 0){
        int digit = num % 10;
        if(min > digit){
            min = digit;
        }
        num /= 10;
    }
    return min;
}
int maxDigit(int num){
    int max = 0;
    while(num != 0){
        int digit = num % 10;
        if(max < digit){
            max = digit;
        }
        num /= 10;
    }
    return max;
}

int main() {
    int x;
    scanf("%i", &x);
    printf("%i %i", minDigit(x), maxDigit(x));
    return 0;
}
