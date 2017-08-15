//  Дана последовательность натуральных чисел, завершающаяся числом 0. Определите, какое наибольшее число подряд идущих элементов этой последовательности равны друг другу.



#include <iostream>

int main() {
    int count = 0;
    int result = 0;
    int prev = 0;
    int x = 1;
    while(x != 0){
        scanf("%i", &x);
        if(prev == x){
            count++;
        }
        else{
            if(result < count){
                result = count;
            }
            count = 1;
        }
        prev = x;
    }

    printf("%d\n", result);
    
    return 0;
}
