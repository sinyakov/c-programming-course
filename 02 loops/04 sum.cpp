//По данному числу n вычислите сумму 4(1-1/3+1/5-1/7+...+(-1)n/(2n+1)).



#include <iostream>

int main() {
    
    int N;
    scanf("%i", &N);
    double sum = 0;
    int sign = 1;
    for(int i = 1; i <= 2 * N + 1; i += 2){
        sum += 1.0 * sign / i;
        sign = -sign;
    }
    
    printf("%lf\n", sum);
    
    return 0;
}
