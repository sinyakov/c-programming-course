// Подсчитайте количество натуральных делителей числа x (включая 1 и само число; x <= 30000).


#include <iostream>

bool isPrime(int x) {
    int a = 0;
    for(int i = 1; i <= x; i++){
        if(x % i == 0){
            a++;
        }
    }
    
    return a == 2;
}

int main() {

    int x;
    scanf("%i", &x);
//    int a = 0;
//    for(int i = 1; i <= x; i++){
//        if(x % i == 0){
//            a++;
//        }
//    }
//    printf("%i\n", a);
    
    if (isPrime(x)) {
        printf("prime\n");
    }
    else {
        printf("not prime\n");
    }
    
    return 0;
}
