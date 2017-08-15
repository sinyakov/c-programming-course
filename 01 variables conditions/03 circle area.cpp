#include <iostream>
using namespace std;

int main() {
    
    double pi = 3.1415926536;
    double r;
    
    cout << "Введите радиус окружности: " << endl;
    cin >> r;
    
    double s = pi * r * r;
    double p = 2 * pi * r;
    
    cout << "Площадь окружности: " << s << endl;
    cout << "Длина окружности: " << p << endl;

    return 0;
}
