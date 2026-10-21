// Гілка dev: першаа зміна).
// Lab_0.2.cpp 
// Кобринович Богдан
// Лабораторна робота № 2. 
// Лінійні програми. 
// Варіант 9 
//тестова зміна для GitHub
#include <iostream> 
#include <cmath> 
using namespace std;
 
int main()
{
    double alpha; // (кут α) 
    double beta;  // (кут β) 
    double z1;    // результат обчислення 1-го виразу 
    double z2;    // результат обчислення 2-го виразу 
 
    cout << "alpha = "; cin >> alpha;
    cout << "beta = ";  cin >> beta;
 
    // обчислення виразів 
    z1 = pow(cos(alpha) - cos(beta), 2) - pow(sin(alpha) - sin(beta), 2);
    z2 = -4 * pow(sin((alpha - beta) / 2.0), 2) * cos(alpha + beta);
 
    cout << endl;
    cout << "z1 = " << z1 << endl;
    cout << "z2 = " << z2 << endl;
 
    cin.get();
    return 0;
}