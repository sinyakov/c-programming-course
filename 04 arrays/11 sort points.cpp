#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef struct Point {
    int x;
    int y;
} Point;

void randomFillArray(Point * array, int size) {
    for (int i = 0; i < size; i++) {
        array[i].x = rand() % 5;
        array[i].y = rand() % 5;
    }
}

void printArray(Point * array, int size) {
    for (int i = 0; i < size; i++) {
        cout << "(" << array[i].x << ", " << array[i].y << ")";
        cout << (i != size - 1 ? " " : "\n");
    }
}

bool cmp (Point i, Point j) {
    if (i.x == j.x) {
        return i.y < j.y;
    }
    else {
        return i.x < j.x;
    }
}

void sortArray(Point * array, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (cmp(array[i], array[j])) {
                swap(array[i], array[j]);
            }
        }
    }
}



int main() {
    
    int size = 10;
    Point* a = new Point[size];

    randomFillArray(a, size);
    printArray(a, size);

    sortArray(a, size);
    printArray(a, size);
    
    sort (a, a + size, cmp);
    printArray(a, size);

    return 0;
}
