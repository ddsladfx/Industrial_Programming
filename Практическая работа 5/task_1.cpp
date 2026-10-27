#include <iostream>

using namespace std;

int main() {
    long double x, y;
    cin >> x >> y;
    if (x <= 0 || y <= 0) {
        cout << "Values must be positive\n";
        return 0;
    }
    int day = 1;
    // По формату вывода сравнивается объём за день, а не накопленная сумма.
    while (x < y) {
        x *= 1.1L;
        day++;
    }
    cout << day << '\n';
    return 0;
}
