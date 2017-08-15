#include <iostream>
using namespace std;

int main() {
    
    // n! = 1 * 2 * 3 * ... * n -- n факториал
    
    int n;
    cin >> n;
    int f = 1;
    for (int i = 1; i <= n; i++) {
        f = f * i;
    }
    cout << f << endl;
    return 0;
}
