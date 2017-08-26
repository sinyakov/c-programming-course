#include <iostream>
using namespace std;

// НОД с использованием циклов
int gcd(int a, int b) {
   
   while(a != 0 && b != 0){
       if(a > b){
           a %= b;
       }
       else{
           b %= a;
       }
   }
   
   return a == 0 ? b : a;
}

// Рекурсивный способ
int gcd2(int a, int b) {
    return b == 0 ? a : gcd2(b, a % b);
}


int lcm(int a, int b) {
    return a / gcd(a , b) * b;
}

int main() {

    int a;
    int b;
    cin >> a >> b;
    cout << gcd(a, b) << " " << lcm(a, b) << endl;
    
    return 0;
}
