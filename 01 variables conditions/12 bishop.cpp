#include <iostream>
using namespace std;

int main() {
    
    int x1;
    int y1;
    int x2;
    int y2;
    
    cin >> x1 >> y1 >> x2 >> y2;
    
    if (abs(x1 - x2) == abs(y1 - y2)) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    
    return 0;
}
