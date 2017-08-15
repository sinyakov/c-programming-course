//Вычислите 1+2+2^2+2^3+…+2^N.


#include <iostream>

int main() {
    
    int N;
    scanf("%i", &N);
    int a = 1;
    int sum = 0;
    for(int i = 0; i <= N; i++){
        sum += a;
        a *= 2;
    }
    printf("%i", sum);
    
    
    return 0;
}
