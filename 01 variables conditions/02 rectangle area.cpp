#include <iostream>
using namespace std;

int main() {
    
    cout << "Введите стороны прямоугольника" << endl;
    
    int a;
    int b;
    cout << "Длина: ";
    cin >> a;
    cout << "Ширина: ";
    cin >> b;
    
    int s = a * b;
    int p = 2 * (a + b);
    
    cout << "Площадь = " << s << endl;
    cout << "Периметр = " << p << endl;
    
    return 0;
}
