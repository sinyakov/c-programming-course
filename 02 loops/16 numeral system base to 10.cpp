#include <iostream>

int main() {
    int x;
    int base;   // основание системы счисления от 2 до 9
    scanf("%i%i", &x, &base);
    int power = 1;
    int sum = 0;
    while(x != 0){
        int digit = x % 10;
        //printf("%i ", digit * power);
        sum += digit * power;
        x = x / 10;
        power *= base;
    }
    printf("%i\n", sum);
    
    return 0;
}
