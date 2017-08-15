#include <iostream>
using namespace std;

int main() {
    
    // Вводится число N, а затем N чисел, сумму которых необходимо вычислить.
    
    int sum = 0;
    int n;
    cin >> n;
    
    for (int i = 1; i <=n; i++){
        int a;
        cin >> a;
        sum = sum + a;
    }
    cout << sum << endl;
    
    return 0;
}
