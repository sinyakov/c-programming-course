#include <iostream>

bool isPrime(int x){
    for(int i = 2; i < x; i++){
        if(x % i == 0){
            return false;
        }
    }
    return x != 1;
}

bool isHyperPrime(int x) {
    while(x != 0){
        if(!isPrime(x)) {
            return false;
        }
        x = x / 10;
    }
    return true;
}

int main() {
    
//    int x;
//    scanf("%i", & x);
    
    for (int i = 1; 100000; i++) {
        if (isHyperPrime(i)) {
            printf("%d\n", i);
        }
    }
    
    
    return 0;
}
