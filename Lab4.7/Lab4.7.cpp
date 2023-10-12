#include <iostream>
#include <iomanip>
#include <cmath>

# define M_PI           3.14159265358979323846

using namespace std;
int main()
{
    double xp, xk, x, dx, eps, a;
    int n;
    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << " |"
        << setw(10) << "exp(x)" << " |"
        << setw(7) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;

    double S = 0;
    for (x = xp; x <= xk; x += dx) {
        n = 0;
        double upNum = 1;
        double downNum = 1;
        a = x;
        S += a;
        do {
            n++;
            a *= (x * x * upNum * downNum) / ((downNum + 1) * (downNum + 2));
            S += a;
            upNum += 2;
            downNum += 2;
        } while (abs(a) >= eps);
        S = (M_PI / 2) - S;
        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << exp(x) << " |"
            << setw(10) << setprecision(5) << S << " |"
            << setw(5) << n << " |"
            << endl;
    }
    cout << "-------------------------------------------------" << endl;


    return 0;
}