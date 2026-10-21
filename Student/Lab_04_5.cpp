#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    double x, y, R;
    srand((unsigned) time(NULL));

    cout << "R = "; cin >> R;

    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        if ((x * x + y * y <= R * R) && ((x <= 0 && y <= 0) || (y >= (x - 1) * (x - 1))))
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    cout << endl << fixed;

    for (int i = 0; i < 10; i++)
    {
        x = 2. * R * rand() / RAND_MAX - R;
        y = 2. * R * rand() / RAND_MAX - R;

        if ((x * x + y * y <= R * R) && ((x <= 0 && y <= 0) || (y >= (x - 1) * (x - 1))))
            cout << setw(8) << setprecision(4) << x << " "
                 << setw(8) << setprecision(4) << y << " " << "yes" << endl;
        else
            cout << setw(8) << setprecision(4) << x << " "
                 << setw(8) << setprecision(4) << y << " " << "no" << endl;
    }

    return 0;
}