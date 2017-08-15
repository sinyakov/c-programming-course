// Дано целое число, не меньшее 2. Выведите его наименьший натуральный делитель, отличный от 1.


#include <stdio.h>

int main() {
    
    int x;
    scanf("%i", &x);
    int a = 2;
    
    while(x % a != 0) {
        a++;
    }
    printf("%i\n", a);
    
    
    return 0;
}
