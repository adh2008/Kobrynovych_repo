#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double S, P;
    int j, i;

    // 1) Спосіб з використанням циклів while
    S = 0;
    j = 2;
    while (j <= 20) {
        P = 1;
        i = j * j;
        while (i <= 400) {
            P *= i;
            i++;
        }
        S += j / (j * j + P);
        j++;
    }
    cout << "1) while:    " << S << endl;

    // 2) Спосіб з використанням циклів do-while
    S = 0;
    j = 2;
    do {
        P = 1;
        i = j * j;
        do {
            P *= i;
            i++;
        } while (i <= 400);
        S += j / (j * j + P);
        j++;
    } while (j <= 20);
    cout << "2) do-while: " << S << endl;

    // 3) Спосіб з використанням циклів for з інкрементом (++)
    S = 0;
    for (j = 2; j <= 20; j++) {
        P = 1;
        for (i = j * j; i <= 400; i++) {
            P *= i;
        }
        S += j / (j * j + P);
    }
    cout << "3) for (++):  " << S << endl;

    // 4) Спосіб з використанням циклів for з декрементом (--)
    S = 0;
    for (j = 20; j >= 2; j--) {
        P = 1;
        for (i = 400; i >= j * j; i--) {
            P *= i;
        }
        S += j / (j * j + P);
    }
    cout << "4) for (--):  " << S << endl;

    return 0;
}