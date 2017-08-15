// По данному числу N распечатайте все целые степени двойки, не превосходящие N, в порядке возрастания.


#include <iostream>

int main() {
    
    int N;
    scanf("%i", &N);
    int a = 1;
    while(a <= N){
        printf("%i ", a);
        a = a * 2;
    }
    
    return 0;
}
