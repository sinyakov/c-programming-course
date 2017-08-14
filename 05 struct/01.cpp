// http://informatics.mccme.ru/mod/statements/view.php?id=279
// Программа получает на вход набор точек на плоскости. Сначала задано количество точек n, затем идет последовательность из n строк, каждая из которых содержит два числа: координаты точки. Величина n не превосходит 100, все исходные координаты – целые числа, не превосходящие 103 по абсолютной величине.

#include <iostream>
#include <math.h>
using namespace std;

// Cтруктура для хранения точки
struct point {
  int x;
  int y;
};

// Заполнение массива
void fillArray(struct point *a, int size) {
  for (int i = 0; i < size; i++) {
    cin >> a[i].x >> a[i].y;
  }
}

// Функция считает расстояние от точки до начала координат
double pointDistance(struct point p) {
  return sqrt(p.x * p.x + p.y * p.y);
}

// Функция возвращает индекс самой удаленной точки
int furthestPointIndex(struct point *a, int size) {
  int maxDistance = 0;
  int index = 0;
  
  for (int i = 0; i < size; i++) {
    if (pointDistance(a[i]) > maxDistance) {
      maxDistance = pointDistance(a[i]);
      index = i;
    }
  }

  return index;
}

int main() {
  
  struct point a[100]; // Массив из точек
  int n;
  cin >> n;

  fillArray(a, n);
  int index = furthestPointIndex(a, n);
  cout << a[index].x << " " << a[index].y << endl;

  return 0;
}