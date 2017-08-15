//Напишите программу, которая определяет, верно ли, что введённое число содержит две одинаковых цифры, стоящие рядом (как, например, 221).
#include <iostream>

bool equalDigitsExist(int x) {
    while(x != 0){
        int lastDigit = x % 10;
        int penultDigit = x / 10 % 10;
        if(lastDigit == penultDigit){
            return true;
        }
        x /= 10;
    }
    return false;
}

int main() {
    
    int x;
    scanf("%i", &x);
    printf(equalDigitsExist(x) ? "YES\n" : "NO\n");
    
    return 0;
}
