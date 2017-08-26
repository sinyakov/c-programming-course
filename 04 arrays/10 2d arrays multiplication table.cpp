#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int N = 10;
    int** a = new int*[N];
    
    int M = 10;
    
    for (int i = 0; i < N; i++) {
        a[i] = new int[M];
        for (int j = 0; j < M; j++) {
            a[i][j] = (i+1) * (j+1);
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << setw(2) << a[i][j] << (j != M - 1 ? " " : "\n");
        }
    }
    
    return 0;
}
