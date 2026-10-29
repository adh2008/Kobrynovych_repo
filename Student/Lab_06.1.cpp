//ітераційний 1 спосіб
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <windows.h>


using namespace std;

void fillArray(int b[], int size){
    for (int i = 0; i < size; i++)
    {
        b[i] = rand() % 106 - 25;
    }
    
}

void printArray(const int b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%4d", b[i]);
    }
    printf("\n");
}

int countElements(const int b[], int size){
    int count = 0;

    for (int i = 0; i < size; i++)
    {
        if (b[i] > 0 && b[i] % 2 != 0)
        {
            count++;
        }
        
    }
    return count;
}

int sumElements(const int b[], int size){
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if(b[i] > 0 && b[i] % 2 != 0){
            sum += b[i];
        }
    }
    return sum;
}
void replaceElements(int b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (b[i] > 0 && b[i] % 2 != 0)
        {
            b[i] = 0;
        }
    }
}
int main(){


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 23;
    int b[N];

    srand(static_cast<unsigned int>(time(0)));

    // 1. формування масиву
    fillArray(b, N);

    // 2. виведення початкового масиву
    printf("Pochatkovyi masyv:\n");
    printArray(b, N);

    // 3. обчислення кількрсті та суми
    int count = countElements(b, N);
    int sum = sumElements(b, N);

    printf("Kilkist dodatnykh neparnykh elementiv: %d\n", count);
    printf("Suma dodatnykh neparnykh elementiv: %d\n", sum);

    // 4. заміна елементу нулями
    replaceElements(b, N);

    // 5. виведення модифікованого масиву
    printf("Modyfikovanyi masyv:\n");
    printArray(b, N);

    return 0;;
}