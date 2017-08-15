#include <iostream>

long long divisorsSum(long long x) {
    long long sum = 0;
    for(int i = 1; i < x; i++){
        if(x % i == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    
    for (long long i = 1; i <= 1000000; i++) {
        if (i == divisorsSum(i)) {
            printf("%lli\n", i);
        }
    }
    
    return 0;
}
