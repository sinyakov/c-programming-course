#include <iostream>
using namespace std;

int main() {
    
    // Подсчитайте, сколько среди данных N чисел нулей, положительных чисел, отрицательных чисел.
    
    int n;
    cin >> n;
    int positive = 0;
    int negative = 0;
    int zeros = 0;
    
    for (int i = 1; i <= n; i++) {
        int f;
        cin >> f;
        if (f > 0) {
            positive++;
        }
        if (f < 0) {
            negative++;
        }
    }
    
    zeros = n - positive - negative;
    
    cout << "+: " << positive << endl;
    cout << "-: " << negative << endl;
    cout << "0: " << zeros << endl;
    
    
    return 0;
}
