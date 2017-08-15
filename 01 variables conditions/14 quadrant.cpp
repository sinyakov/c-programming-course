// Даны координаты двух точек на плоскости, требуется определить, лежат ли они в одной координатной четверти или нет (все координаты отличны от нуля).

#include <iostream>
using namespace std;

int main() {    
    
    int x1;
    int y1;
    int x2;
    int y2;
    
    cin >> x1 >> y1 >> x2 >> y2;
    
    if (x1 * x2 > 0 && y1 * y2 > 0) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
    
    
    return 0;
}
