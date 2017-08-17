#include <iostream>
using namespace std;

void fillArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void printArray(int* a, int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void reverseArray(int* a, int n){
    int tmp = 0;
    for(int i = 0; i < n/2; i++){
        tmp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = tmp;
    }
}

int sumElements(int* a, int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += a[i];
    }
    return sum;
}

bool containsZeros(int* a, int n) {
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            return true;
        }
    }
    return false;
}

int countElementsGreaterPrevious(int*a, int n){
    int count = 0;
    for(int i = 1; i < n; i++){
        if(a[i-1] < a[i]){
            count++;
        }
    }
    return count;
}

bool allElementsPositive(int* a, int n) {
    for(int i = 0; i < n; i++){
        if(a[i] <= 0){
            return false;
        }
    }
    return true;
}

bool isSameSign(int a, int b){
    return a * b > 0 || (a == 0 && b == 0);
}

bool allElementsSameSign(int* a, int n) {
    for(int i = 1; i < n; i++){
        if(!isSameSign(a[i-1], a[i])){
            return false;
        }
    }
    return true;
}

int main() {

    int a[10000];   // объявил массив из 10000 элементов
    int size;   // «размер» массива — элементы, которые мы обрабатываем
    
    cin >> size;
    
    fillArray(a, size);
    printArray(a, size);
    reverseArray(a, size);
    printArray(a, size);
    
    
    return 0;
}
