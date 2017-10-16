#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

class matrix {
private:
    int n;
    int m;
    double **matr; // массив массивов
public:
    matrix(int m, int n) { // конструктор  c двумя параметрами
        this->m = m;        // инициализируем поля класса
        this->n = n;        // столбец
        matr = new double*[m];  // выделяем память
        for (int i = 0; i < m; i++) {
            matr[i] = new double[n]; //--||--
        }
    }
    ~matrix() // деструктор
    {
        for (int i = 0; i < m; i++){
            delete[] matr[i];  // освобождаем память , выделенную в конструкторе
        }
        delete [] matr;
        
    }
    //методы для работы с матрицей
    void createRandom() {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matr[i][j] = rand() % 10 + 10;
            }
        }
    }
    void display() {
        for (int i = 0; i < m; i++) {
            printf("( ");
            for (int j = 0; j < n; j++) {
                printf("%02f, ", matr[i][j]);
            }
            printf("),\n");
        }
        printf("\n");
        
    }
    
    
    matrix* operator+(const matrix& matr2) {   // метод сложения матриц
        matrix *matrsumm = new matrix(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrsumm->matr[i][j] = matr[i][j] + matr2.matr[i][j];
            }
        }
        return(matrsumm);
    }
    
    
    matrix* operator-(const matrix& matr2) { // метод вычитания матриц
        matrix *matrsumm = new matrix(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrsumm->matr[i][j] = matr[i][j] - matr2.matr[i][j];
            }
        }
        return(matrsumm);
    }
    
    matrix* operator*(const double s) {  // метод уменожения на число
        matrix *matrmult = new matrix(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrmult->matr[i][j] = matr[i][j] * s;
            }
        }
        return(matrmult);
    }
    
    matrix* operator/(const double s) { // метод деления на число
        matrix *matrmult = new matrix(m, n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matrmult->matr[i][j] = matr[i][j] / s;
            }
        }
        return(matrmult);
    }
    
    
    matrix* operator*(const matrix& matr2) {   //  метод умножения матриц
        matrix *matrmult = new matrix(m, matr2.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < matr2.n; j++) {
                matrmult->matr[i][j] = 0;
                for (int h = 0; h < n; h++) {
                    matrmult->matr[i][j] += matr[i][h] * matr2.matr[h][j];
                }
            }
        }
        return(matrmult);
    }
    
    //перегружаем операторы
    void operator =(const matrix& matr2) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matr[i][j] = matr2.matr[i][j];
            }
        }
    }
    
    void operator +=(const matrix& matr2) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matr[i][j] += matr2.matr[i][j];
            }
        }
    }
    
    void operator -=(const matrix& matr2) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matr[i][j] -= matr2.matr[i][j];
            }
        }
    }
    
    void operator *=(const double s) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matr[i][j] *= s;
            }
        }
    }
    
    void operator /=(const double s) {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                matr[i][j] /= s;
            }
        }
    }
    
    friend istream& operator>>(istream& ist, const matrix& matr) {
        for (int i = 0; i < matr.m; i++) {
            for (int j = 0; j < matr.n; j++) {
                ist >> matr.matr[i][j];
            };
        }
        cout << "\n";
        return ist;
    }
    
    
    double getCellValue(int i, int j) { // метод  для извлечения элемента массива на месте i j
        return matr[i][j];
    }
    
    void setCellValue(int i, int j, double value) {  //метод для заполнения  массива элементом  на место i, j
        matr[i][j] = value;
    }
    
};


int main() {
    
    int n;
    cout << " vvedite razmer matrix"<<" ";
    cin >> n;
    matrix *a = new matrix(n, n); // создаем матрицу
    cin >> *a; // выводим на экран
    a->display();
    // дальше по Фадееву страница 187 используем формулы
    
    vector<matrix*> u(n);  // создаем вектор типо матрица
    vector<matrix*> v(n); // ----
    vector<matrix*> p(n);
    vector<matrix*> r(n);
    vector<matrix*> q(n);
    vector<double> alpha(n);
    vector<matrix*> inv(n);
    
    inv[0] = new matrix(1, 1);			//  первая обратная матрица
    inv[0]->setCellValue(0, 0, 1.0 / a->getCellValue(0, 0)); // извлекаем элемент первой строки и столбца , единицу делим на него и вставляем
    
    for (int i = 1; i < n; i++) {
        
        v[i] = new matrix(1, i);//
        for (int j = 0; j < i; j++) {
            v[i]->setCellValue(0, j, a->getCellValue(i, j)); // заполняем в столбец
        }
        
        u[i] = new matrix(i, 1);
        for (int j = 0; j < i; j++) {
            u[i]->setCellValue(j, 0, a->getCellValue(j, i)); // заполняем в строку
        }
        
        matrix *vInv = *v[i] * *inv[i - 1];  // по формуле  Vn*A(n-1)^(-1)
        matrix *invU = *inv[i - 1] * *u[i]; // по формуле A[n-1]^(-1)*Un
        matrix *tmp = *vInv  * *u[i];//Vn*A(n-1)^(-1)*Un
        alpha[i] = a->getCellValue(i, i) - tmp->getCellValue(0, 0); // альфа=ann-Vn*A(n-1)^(-1)*Un
        
        r[i] = *invU / -alpha[i];
        q[i] = *vInv / -alpha[i];
        
        matrix *invUV = *invU * *v[i]; //  A[n-1]^(-1)*Un*Vn
        matrix *invUVinv = *invUV * *inv[i - 1];//A[n-1]^(-1)*Un*Vn
        *invUVinv /= alpha[i];//A[n-1]^(-1)*Un*Vn/aльфаn 
        
        p[i - 1] = *inv[i - 1] + *invUVinv;  // по формуле 
        
        inv[i] = new matrix(i + 1, i + 1);
        
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < i; k++) {
                inv[i]->setCellValue(j, k, p[i - 1]->getCellValue(j, k)); //заполняем  
            }
        }
        for (int j = 0; j < i; j++) {
            inv[i]->setCellValue(j, i, r[i]->getCellValue(j, 0)); // заполняем  извлеченные элементы из вектора
        }
        for (int j = 0; j < i; j++) {
            inv[i]->setCellValue(i, j, q[i]->getCellValue(0, j)); // заполняем  ---
        }
        
        inv[i]->setCellValue(i, i, 1.0 / alpha[i]); // заполняем
        
        delete vInv;        // чистим память
        delete invU;
        delete tmp;
        delete invUV;
        delete invUVinv;
        
    }
    
    inv[n-1]->display(); // выводим 
        
    return 0;
}
