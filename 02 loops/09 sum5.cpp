//По данному натуральному числу N найдите сумму чисел 1+1/1!+1/2!+1/3!+...+1/N!. Количество действий должно быть пропорционально N.

#include <iostream>

int main() {
    
    int N;
    scanf("%i", &N);
    double sum = 0;
    int fact = 1;
    for(int i = 0; i <= N; i++){
        sum += 1.0 / fact;
        fact *= i + 1;
        printf("%2d %10d %2f\n", i, fact, sum);
    }
    
    return 0;
}
