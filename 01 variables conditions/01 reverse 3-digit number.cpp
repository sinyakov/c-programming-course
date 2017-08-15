#include <iostream>
using namespace std;

int main() {
    
    // разворачиваем трехзначное число
    
    int a;
    cin >> a;
    
    int c1 = a / 100;       // сотни
    int c2 = a % 100 / 10;  // десятки
    int c3 = a % 10;        // единицы
    
    int b = c3 * 100 + c2 * 10 + c1;
    
    cout << b << endl;
    
    return 0;
}