//рекурсивний 2 спосіб
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Рекурсивне введення масиву
void inputArray(vector<int>& a, int i)
{
    if (i == a.size())
        return;

    cout << "a[" << i << "] = ";
    cin >> a[i];

    inputArray(a, i + 1);
}

// Рекурсивне виведення масиву
void printArray(const vector<int>& a, int i)
{
    if (i == a.size())
        return;

    cout << setw(5) << a[i];

    printArray(a, i + 1);
}

// Рекурсивне обчислення суми індексів
// непарних елементів масиву
int sumOddElementIndices(const vector<int>& a, int i)
{
    if (i == a.size())
        return 0;

    if (a[i] % 2 != 0)
        return i + sumOddElementIndices(a, i + 1);

    return sumOddElementIndices(a, i + 1);
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Array size must be positive." << endl;
        return 0;
    }

    vector<int> a(n);

    cout << "Enter array elements:" << endl;
    inputArray(a, 0);

    cout << "\nOriginal array:\n";
    printArray(a, 0);

    int sum = sumOddElementIndices(a, 0);

    cout << "\nSum of indices of odd elements = "
         << sum << endl;

    return 0;
}
