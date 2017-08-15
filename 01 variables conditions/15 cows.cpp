// https://informatics.mccme.ru/mod/statements/view3.php?id=276&chapterid=303
// По данному числу n закончите фразу "На лугу пасется..." одним из возможных продолжений: "n коров", "n корова", "n коровы", правильно склоняя слово "корова".

#include <iostream>
using namespace std;

int main() {
    
    int cows;
    cin >> cows;
    
    if (cows % 10 == 1 && cows != 11) {
        cout << cows << " korova" << endl;
    }
    else {
        if ((cows % 10 == 2 || cows % 10 == 3 || cows % 10 == 4) && cows / 10 != 1) {
            cout << cows << " korovy" << endl;
        }
        else {
            cout << cows << " korov" << endl;
        }
    }
    
    return 0;
}
