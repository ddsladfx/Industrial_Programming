#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    // Для a и b от 1 до 1000: k = 1 при a >= b, иначе k = 0.
    int k = (a - b + 1000) / 1000;
    cout << a * k + b * (1 - k) << '\n';
    return 0;
}
