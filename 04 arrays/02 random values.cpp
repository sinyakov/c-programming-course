#include <iostream>
using namespace std;

//rand()                     ->  0 .. 2 000 000 000
//rand() % (X + 1)           ->  0 .. X
//rand() % (B - A + 1) + A   ->  [A .. B]
//    0 .. B-A         + A   ->  [A .. B]

void fillArray(int*a, int size, int A, int B){
    for(int i = 0; i < size; i++){
        a[i] = rand() % (B - A + 1) + A;
    }
}

void printArray(int*a, int size){
    for(int i = 0; i < size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int countValue(int*a, int size, int value){
    int count = 0;
    for(int i = 0; i < size; i++){
        if(a[i] == value){
            count++;
        }
    }
    return count;
}

void computeDistribution(int* a, int size, int minValue, int maxValue) {
    for(int value = minValue; value <= maxValue; value++){
        cout << value << " " << countValue(a, size, value) * 100.0 / size << endl;
    }
}

// Дан массив, состоящий из целых чисел. Напишите программу, которая определяет, есть ли в массиве пара соседних элементов с одинаковыми знаками.

bool isSameSign(int a, int b){
    return a * b > 0 || (a == 0 && b == 0);
}

bool containAgjacentSameSignNumbers(int*a, int size){
    for(int i = 1; i < size; i++){
        if(isSameSign(a[i-1], a[i])){
            return true;
        }
    }
    return false;
}

// определяет среднее арифметическое всех элементов этого массива, которые меньше 50, и среднее арифметическое всех остальных элементов.

void arithmeticalMean(int*a, int size, int delimiter) {
    int count = 0;
    double sum = 0;
    double sum2 = 0;
    for(int i = 0; i < size; i++) {
        if(a[i] < delimiter){
            sum += a[i];
            count++;
        }
        else{
            sum2 += a[i];
        }
    }
    cout << (count != 0 ? sum / count : 0) << " ";
    cout << (size - count != 0 ? sum2 / (size - count) : 0) << endl;
}


int main() {
    
    int a[1000000];
    int size;
    int A, B;
    cin >> size;
    cin >> A >> B;
    fillArray(a, size, A, B);
    printArray(a, size);
    arithmeticalMean(a, size, 50);
    
    //computeDistribution(a, size, A, B);
    
    return 0;
}
