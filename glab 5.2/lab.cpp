#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int& n, double s, double F, double R);
double A(const double x, const int n, double a);

int main()
{
    double xp, xk, x, dx, eps, F = 0, R = 0, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-------------------------------------------------" << endl;
    cout << "|" << setw(5) << "x" << " |"
        << setw(10) << "log(x)" << " |"
        << setw(7) << "S" << " |"
        << setw(5) << "n" << " |"
        << endl;
    cout << "-------------------------------------------------" << endl;
    x = xp;
    while (x <= xk && x > 0)
    {
        s = S(x, eps, n, s, F, R);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
            << setw(10) << setprecision(5) << log(x) << " |"
            << setw(10) << setprecision(5) << s << " |"
            << setw(5) << n << " |"
            << endl;
        x += dx;
    }
    cout << "-------------------------------------------------" << endl;
    return 0;
}

double S(const double x, const double eps, int& n, double s, double F, double R)
{
    n = 0;
    F = 0;
    double a = 1;
    s = a;
    do {
        n++;

        R = (pow(x - 1, 2 * n + 1) / ((2 * n + 1) * pow(x + 1, 2 * n + 1)));
        s += R;
    } while (abs(a) >= eps);
    return s;
}

double A(const double x, const int n, double a)
{
    double R = x / n;
    a *= R;
    return a;
}