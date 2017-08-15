#include <iostream>
int reverseNumber(int x) {
    int result = 0;
    while(x != 0){
        int digit = x % 10;
        result = result * 10 + digit;
        x /= 10;
    }
    return result;
}
int main() {
    int count = 0;
    for(int i = 1; i < 100000; i++){
        if(i == reverseNumber(i)){
            printf("%i\n", i);
            count++;
        }
    }
    printf("Количество: %i\n", count);
    return 0;
}
