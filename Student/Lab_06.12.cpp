#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <windows.h>


using namespace std;

// Допоміжна функція: перевірка критерію (додатне та непарне)
bool IsCriterion(int value) {
    return (value > 0 && value % 2 != 0);
}

// 1. Рекурсивне формування масиву випадковими числами в діапазоні [Low, High]
void Create(int* b, const int size, const int Low, const int High, int i = 0) {
    if (i >= size) return;
    b[i] = Low + rand() % (High - Low + 1);
    Create(b, size, Low, High, i + 1);
}

// 2. Рекурсивне виведення масиву у рядок
void Print(const int* b, const int size, int i = 0) {
    if (i >= size) {
        cout << endl;
        return;
    }
    cout << setw(4) << b[i];
    Print(b, size, i + 1);
}

// 3. Рекурсивне обчислення кількості елементів, що відповідають критерію
int Count(const int* b, const int size, int i = 0) {
    if (i >= size) return 0;
    int current = IsCriterion(b[i]) ? 1 : 0;
    return current + Count(b, size, i + 1);
}

// 4. Рекурсивне обчислення суми елементів, що відповідають критерію
int Sum(const int* b, const int size, int i = 0) {
    if (i >= size) return 0;
    int current = IsCriterion(b[i]) ? b[i] : 0;
    return current + Sum(b, size, i + 1);
}

// 5. Рекурсивна заміна елементів, що відповідають критерію, нулями
void Replace(int* b, const int size, int i = 0) {
    if (i >= size) return;
    if (IsCriterion(b[i])) {
        b[i] = 0;
    }
    Replace(b, size, i + 1);
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    srand((unsigned)time(0));

    const int SIZE = 23;
    const int LOW = -25;
    const int HIGH = 80;

    int b[SIZE];

    // Формування та первинне виведення масиву
    Create(b, SIZE, LOW, HIGH);
    cout << "Початковий масив b:" << endl;
    Print(b, SIZE);

    // Обчислення кількості та суми
    int count = Count(b, SIZE);
    int sum = Sum(b, SIZE);

    // Заміна елементів нулями
    Replace(b, SIZE);

    // Виведення обчислених результатів
    cout << "\nРезультати:" << endl;
    cout << "Кількість елементів (додатні і непарні): " << count << endl;
    cout << "Сума елементів (додатні і непарні):     " << sum << endl;

    // Виведення модифікованого масиву
    cout << "\nМодифікований масив b:" << endl;
    Print(b, SIZE);

    return 0;
}