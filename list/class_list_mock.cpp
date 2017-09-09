#include <iostream>
using namespace std;

struct Point {
    int x;
    int y;
    Point(int x_, int y_) : x(x_), y(y_) {};
};

class List {
private:
    struct node{
        Point* data;
        node* next;
    };
    
    node* root; // указатель на первый элемент списка

public:
    List() {
        root = NULL;
    }
    
    void print() {};
    void printReverse() {};
    
    int size() { return 0; };
    bool empty() { return true; };
    
    void insert(Point* p) {};
    void remove(int num) {};
    
    void sort() {}; // можно написать сортировку со вложенными циклами
                    // идея как с массивами, только там мы ходили счетчиками int i, j
                    // а здесь будут указатели node* i, j
    
};

int main(int argc, const char * argv[]) {

    List l;
    
    for (int i = 0; i < 10; i++) {
        Point* p = new Point(rand() % 10, rand() % 10);
        l.insert(p);
    }
    
    l.remove(2);
    l.remove(5);
    
    l.print();
    
    return 0;
}
