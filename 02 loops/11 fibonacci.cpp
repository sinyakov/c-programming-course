#include <stdio.h>

int main() {
    
    int x;
    scanf("%i", &x);
    
    int a = 0;
    int b = 1;
    
    for(int i = 1; i <= x; i++) {
        int c = a + b;
        a = b;
        b = c;
    }

    printf("%i\n", a);
    
    return 0;
}
