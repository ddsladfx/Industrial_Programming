#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

long double power(long double a, unsigned long long n) {
    long double result = 1;
    while (n > 0) {
        if (n % 2 == 1) result *= a;
        n /= 2;
        if (n > 0) a *= a;
    }
    return result;
}

int main() {
    long double a;
    long long n;
    cin >> a >> n;
    if (a == 0 && n < 0) {
        cout << "Division by zero\n";
        return 0;
    }
    // Такое вычисление модуля не переполняется даже при LLONG_MIN.
    unsigned long long exponent = n < 0 ? 0ULL - static_cast<unsigned long long>(n) : n;
    long double result = power(n < 0 ? 1 / a : a, exponent);
    if (isfinite(result)) cout << setprecision(18) << result << '\n';
    else cout << "Overflow\n";
    return 0;
}
