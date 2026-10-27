#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double a, b;
    cin >> a >> b;
    cout << setprecision(15) << sqrt(a * a + b * b) << '\n';
    return 0;
}
